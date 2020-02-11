#include "PCM.h"
#include "iodefine.h"

int16_t __attribute__((aligned(512))) g_pcm_buffer[DEFAULT_PCM_BUFFER_SIZE / sizeof(int16_t)];

PCMClass::PCMClass(int inputPin, int dmaCh) :
	_inputPin(inputPin),
	_dmaCh(dmaCh),
	_onReceive(NULL),
	_DMACm(NULL)
{
}

PCMClass::~PCMClass()
{
}

int PCMClass::begin(int channels, long sampleRate)
{
	_channels = channels;

	uint16_t adans0 = 0;
	volatile uint16_t *ad_addr = NULL;

	switch (_inputPin) {
	case PIN_AN000: adans0 |= 1 << 0; ad_addr = &S12AD.ADDR0; break;
	case PIN_AN001: adans0 |= 1 << 1; ad_addr = &S12AD.ADDR1; break;
	case PIN_AN002: adans0 |= 1 << 2; ad_addr = &S12AD.ADDR2; break;
	case PIN_AN003: adans0 |= 1 << 3; ad_addr = &S12AD.ADDR3; break;
	case PIN_AN004: adans0 |= 1 << 4; ad_addr = &S12AD.ADDR4; break;
	case PIN_AN005: adans0 |= 1 << 5; ad_addr = &S12AD.ADDR5; break;
	case PIN_AN006: adans0 |= 1 << 6; ad_addr = &S12AD.ADDR6; break;
	case PIN_AN007: adans0 |= 1 << 7; ad_addr = &S12AD.ADDR7; break;
	case PIN_AN008: adans0 |= 1 << 8; ad_addr = &S12AD.ADDR8; break;
	case PIN_AN009: adans0 |= 1 << 9; ad_addr = &S12AD.ADDR9; break;
	case PIN_AN010: adans0 |= 1 << 10; ad_addr = &S12AD.ADDR10; break;
	case PIN_AN011: adans0 |= 1 << 11; ad_addr = &S12AD.ADDR11; break;
	case PIN_AN012: adans0 |= 1 << 12; ad_addr = &S12AD.ADDR12; break;
	case PIN_AN013: adans0 |= 1 << 13; ad_addr = &S12AD.ADDR13; break;
	default: return 0;
	}

	int intno = 0;
	volatile unsigned char *ICU_DMRSRm = NULL;
	switch (_dmaCh){
	case 0: intno = VECT_DMAC_DMAC0I; ICU_DMRSRm = &ICU.DMRSR0; _DMACm = (struct st_dmac1 *)&DMAC0; break;
	case 1: intno = VECT_DMAC_DMAC1I; ICU_DMRSRm = &ICU.DMRSR1; _DMACm = &DMAC1; break;
	case 2: intno = VECT_DMAC_DMAC2I; ICU_DMRSRm = &ICU.DMRSR2; _DMACm = &DMAC2; break;
	case 3: intno = VECT_DMAC_DMAC3I; ICU_DMRSRm = &ICU.DMRSR3; _DMACm = &DMAC3; break;
	default: return 0;
	}

	/* 割り込み禁止 */
	disableInterrupt(VECT_S12AD_S12ADI0);
	disableInterrupt(intno);

	/* 周辺機能の制御レジスタを設定するが、スタートはさせない */

	/*
	 * モジュールストップ機能の設定(S12AD,TMR0,TMR1)
	 */
	SYSTEM.PRCR.WORD = 0xA502;
	SYSTEM.MSTPCRA.BIT.MSTPA17 = 0;
	SYSTEM.MSTPCRA.BIT.MSTPA5 = 0;
	SYSTEM.PRCR.WORD = 0xA500;

	/* A/D変換停止 */
	S12AD.ADCSR.BIT.ADST = 0b0;

	/* 12bitADC初期化 */
	S12AD.ADEXICR.WORD = 0x0000;
	S12AD.ADANS0.WORD |= adans0;

	/* 同期トリガ（MTU、TPU、TMR）によるA/D変換の開始を選択 */
	S12AD.ADCSR.BIT.EXTRG = 0b0;
	/* 同期、非同期トリガによるA/D変換の開始を許可 */
	S12AD.ADCSR.BIT.TRGE = 0b1;
	/* PCLK/8 */
	S12AD.ADCSR.BIT.CKS = 0b00;
	/* スキャン終了後のS12ADI0割り込み発生の許可 */
	S12AD.ADCSR.BIT.ADIE = 0b1;
	/*	シングルスキャンモード */
	S12AD.ADCSR.BIT.ADCS = 0b0;
	/* 自動クリアを禁止 */
	S12AD.ADCER.BIT.ACE = 0b0;
	/* A/Dデータレジスタのフォーマットを左詰めにする */
	S12AD.ADCER.BIT.ADRFMT = 0b1;
	/* TMR0.TCORAとTMR0.TCNT */
	S12AD.ADSTRGR.BIT.ADSTRS = 0b1001;

	/* 16ビットカウントモード */
	TMR0.TCCR.BIT.CSS = 0b11;
	TMR0.TCCR.BIT.CKS = 0b000;
	/* 分周クロック：PCLK/8でカウント */
	TMR1.TCCR.BIT.CSS = 0b01;
	TMR1.TCCR.BIT.CKS = 0b010;
	/* PCLK(48MHz)/8/16kHz */
	TMR0.TCORA = 375;
	/* コンペアマッチAによりクリア */
	TMR0.TCR.BIT.CCLR = 0b01;
	/* IRQ端子機能を設定するが、許可はさせない */
	ICU.IPR[intno].BIT.IPR = 0x1;

	/* DMA転送禁止 */
	_DMACm->DMCNT.BIT.DTE = 0;

	ICU.IR[intno].BIT.IR = 0x0;

	/* DMACの起動要因を設定する */
	*ICU_DMRSRm = VECT_S12AD_S12ADI0;

	/* 転送先アドレス更新モード：インクリメント */
	_DMACm->DMAMD.BIT.DM = 0b10;
	/* 転送元アドレス更新モード：アドレス固定 */
	_DMACm->DMAMD.BIT.SM = 0b00;
	/* 転送先アドレス拡張リピートエリア設定ビット(512Byte) */
	_DMACm->DMAMD.BIT.DARA = 0b01001;
	/* 転送元アドレス拡張リピートエリア設定ビット */
	_DMACm->DMAMD.BIT.SARA = 0b00000;
	/* 周辺モジュールによる転送要求 */
	_DMACm->DMTMD.BIT.DCTG = 0b01;
	/* 16ビット転送 */
	_DMACm->DMTMD.BIT.SZ = 0x01;
	/* リピート領域、ブロック領域は設定しない */
	_DMACm->DMTMD.BIT.DTS = 0b10;
	/* ノーマル転送モード */
	_DMACm->DMTMD.BIT.MD = 0b00;

	/* 転送元の開始アドレスを設定 */
	_DMACm->DMSAR = (unsigned long)ad_addr;
	/* 転送先の開始アドレスを設定 */
	_DMACm->DMDAR = (unsigned long)g_pcm_buffer;
	/* 転送データ数を設定 */
	_DMACm->DMCRA = 0;
	/* ブロック転送数を設定 */
	_DMACm->DMCRB = 0;

	/* DMA転送終了割り込み許可 */
	_DMACm->DMINT.BIT.DARIE = 1;
	_DMACm->DMINT.BIT.ESIE = 1;

	/* DMA転送許可 */
	_DMACm->DMCNT.BIT.DTE = 1;

	/* 変換開始（シングルスキャンモード） */
	S12AD.ADCSR.BIT.ADST = 1;

	/* DMA転送終了割り込み許可 */
	enableInterrupt(intno);

	/* 12bitADC割り込み許可 */
	enableInterrupt(VECT_S12AD_S12ADI0);

	/* DMAC動作許可 */
	DMAC.DMAST.BIT.DMST = 1;

	/* コンペアマッチAによるA/D変換開始要求を許可 */
	((struct st_tmr0_tcsr *)&TMR0.TCSR)->BIT.ADTE = 0b1;

	_intno = intno;

	return 1;
}

void PCMClass::end()
{
	/* 割り込み禁止 */
	disableInterrupt(_intno);
	disableInterrupt(VECT_S12AD_S12ADI0);

	/* コンペアマッチAによるA/D変換開始要求を禁止 */
	((struct st_tmr0_tcsr *)&TMR0.TCSR)->BIT.ADTE = 0b1;

	/* AD変換停止 */
	S12AD.ADCSR.BIT.ADST = 0;

	/* DMAC動作停止 */
	DMAC.DMAST.BIT.DMST = 0;
}

int PCMClass::available()
{
	disableInterrupt(_intno);

	size_t avail = _doubleBuffer.available();

	enableInterrupt(_intno);

	return avail;
}

int PCMClass::read(void *buffer, size_t size)
{
	disableInterrupt(_intno);

	int read = _doubleBuffer.read(buffer, size);

	enableInterrupt(_intno);

	return read;
}

void PCMClass::onReceive(void(*function)(void))
{
	_onReceive = function;
}

void PCMClass::setGain(int gain)
{
}

void PCMClass::setBufferSize(int bufferSize)
{
	_doubleBuffer.setSize(bufferSize);
}

void PCMClass::IrqHandler()
{
	disableInterrupt(_intno);

	_doubleBuffer.write(g_pcm_buffer, sizeof(g_pcm_buffer));

	// call receive callback if provided
	if (_onReceive) {
		_onReceive();
	}

	enableInterrupt(_intno);

	/* DMA再開 */
	_DMACm->DMCNT.BIT.DTE = 1;
}

extern PCMClass PCM;
