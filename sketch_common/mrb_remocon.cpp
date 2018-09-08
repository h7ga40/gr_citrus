/*
 * IR Remocon mruby class
 *
 *  Copyright (C) 2018 Cores Co., Ltd. Japan
 *
 */
#include <mruby.h>
#include <mruby/class.h>
#include <mruby/data.h>
#include <mruby/hash.h>
#include <mruby/proc.h>
#include <mruby/variable.h>
#include <rx63n/iodefine.h>
#include <rx63n/util.h>
#include "mrb_remocon.h"

#define CAPTURE_LOG_COUNT 256
volatile uint16_t capture_log[CAPTURE_LOG_COUNT];
volatile uint32_t capture_log_pos;

// Capture初期化 //
void sInitCapture(void) {
	// TPU5の16bitタイマで利用(P13) 1サイクル2μ秒//
	PORT1.PDR.BIT.B3 = 0;		// PIN13を入力(TIOCA5).
	PORT1.PMR.BIT.B3 = 1;		// モード：周辺機器設定.
	MPC.PWPR.BIT.B0WI = 0;		// PFSWE書き込み許可.
	MPC.PWPR.BIT.PFSWE = 1;		// PFSレジスタ書き込み許可.
	MPC.P13PFS.BYTE = 0x03;		// 端子機能設定(TIOCA5).
	MPC.PWPR.BYTE = 0x80;		// PFSWE, PFSレジスタ書き込み禁止.
	SYSTEM.PRCR.WORD = 0xA503;	// 保護レジスタ書き込み許可.
	MSTP(TPU5) = 0;				// TPU0～5モジュールストップ解除.
	SYSTEM.PRCR.WORD = 0xA500;	// 保護レジスタ書き込み禁止.
	TPU5.TCR.BIT.TPSC = 3;		// PCLK/64(1.5MHz).
	TPU5.TCR.BIT.CKEG = 0;		// 内部クロック立下りでカウント.
	TPU5.TCR.BIT.CCLR = 0;		// カウントクリアなし.
	TPU5.TIOR.BIT.IOA = 0x8;	// 立ち上がりでキャプチャ.
	TPU5.TIOR.BIT.IOB = 0x9;	// 立下りでキャプチャ.
	TPU5.TMDR.BIT.ICSELB = 1;	// インプットキャプチャ入力元設定(TIOCA5).
	TPU5.TMDR.BIT.BFA = 0;		// TGRA通常モード.
	TPU5.TMDR.BIT.BFB = 0;		// TGRB通常モード.
	TPU5.TMDR.BIT.MD = 0x00;	// 通常動作モード.
//	IEN(TPU5, TGI5A) = 1;		// TGI5A割り込み許可.
	enableInterrupt(VECT_TPU5_TGI5A);
//	IEN(TPU5, TGI5B) = 1;		// TGI5B割り込み許可.
	enableInterrupt(VECT_TPU5_TGI5B);
	IPR(TPU5, TGI5A) = 10;		// プライオリティ10.
	IPR(TPU5, TGI5B) = 10;		// プライオリティ10.
	IR(TPU5, TGI5A) = 0;		// コンペアマッチ割り込み要因クリア.
	IR(TPU5, TGI5B) = 0;		// コンペアマッチ割り込み要因クリア.
	TPUA.TSTR.BIT.CST5 = 0;		// TPU5停止.
	TPU5.TIER.BYTE = 0;			// 割り込み禁止.
}

// キャプチャ処理 //
void sCaptureStart(void)
{
	TPU5.TCNT = 0;
	TPUA.TSTR.BIT.CST5 = 1;
	TPU5.TIER.BYTE = 0x0f;
}

// キャプチャ処理 //
void sCaptureEnd(void)
{
	TPU5.TIER.BYTE = 0x00;
	TPUA.TSTR.BIT.CST5 = 0;
}

// コンペアマッチA(Low時間の取得).
extern "C" void IntrTPU5_TGI5A(void)
{
	uint32_t us;
	uint32_t a = TPU5.TGRA;
	uint32_t b = TPU5.TGRB;

	// Timer周期割り込み //
	if (a > b)
		a = a - b;
	else
		a = (0x10000 + a) - b;

	us = (4 * a) / 3;
	if (us > 0xFFFF)
		us = 0xFFFF;

	// 偶数番目に入るよう調整
	if ((capture_log_pos % 2) != 0) {
		capture_log[capture_log_pos % CAPTURE_LOG_COUNT] = 0xFFFF;
		capture_log_pos++;
	}
	capture_log[capture_log_pos % CAPTURE_LOG_COUNT] = us;
	capture_log_pos++;
}

// コンペアマッチB（High時間の取得）.
extern "C" void IntrTPU5_TGI5B(void)
{
	uint32_t us;
	uint32_t a = TPU5.TGRA;
	uint32_t b = TPU5.TGRB;

	// Timer周期割り込み //
	if (b > a)
		a = (b - a);
	else
		a = (0x10000 + b) - a;

	us = (4 * a) / 3;
	if (us > 0xFFFF)
		us = 0xFFFF;

	// 奇数番目に入るよう調整
	if ((capture_log_pos % 2) == 0) {
		capture_log[capture_log_pos % CAPTURE_LOG_COUNT] = 0xFFFF;
		capture_log_pos++;
	}
	capture_log[capture_log_pos % CAPTURE_LOG_COUNT] = us;
	capture_log_pos++;
}

class Remocon
{
public:
	enum ParseState {
		None,
		LeaderOn,
		LeaderOff,
		NecFrameDataOn,
		NecFrameDataOff,
		NecStopBitOn,
		AehaFrameDataOn,
		AehaFrameDataOff,
		AehaTrailerOn,
		AehaTrailerOff,
		SircFrameDataOn,
		SircFrameDataOff,
	};
public:
	Remocon();
private:
	uint32_t _capture_log_pos;
	ParseState _state;
	int _pos;
	REMOCON_FORMAT _code_format_num;
	struct remo_con_format *_format;
	union {
		NEC_LogData nec;
		AEHA_LogData aeha;
		SIRC_LogData sirc;
		VBUF_LogData vbuf;
	};
public:
	REMOCON_FORMAT get_remocon_format() {
		return _code_format_num;
	}
	void get_data(NEC_LogData *nec) { *nec = this->nec; }
	void get_data(AEHA_LogData *aeha) { *aeha = this->aeha; }
	void get_data(SIRC_LogData *sirc) { *sirc = this->sirc; }
	void get_data(VBUF_LogData *vbuf) { *vbuf = this->vbuf; }
	bool Receive();
	void Send(NEC_LogData *nec);
	void Send(AEHA_LogData *aeha);
	void Send(SIRC_LogData *sirc);
	void Send(VBUF_LogData *vbuf);
};

Remocon::Remocon()
{
	_capture_log_pos = capture_log_pos;
	_state = None;
	_pos = 0;
	_code_format_num = FORMAT_NONE;
	_format = NULL;
}

/* 信号フォーマット基本情報テーブル */
const struct remo_con_format_base_data FORMAT_BASE_TABLE[REMOCON_FORMAT_NUM] = {
	{ NEC_UNIT_BASE,  NEC_L_ON_T,  NEC_L_OFF_T,  NEC_R_OFF_T,  NEC_V_0_ON_T,  NEC_V_0_OFF_T,  NEC_V_1_ON_T,  NEC_V_1_OFF_T,  NEC_TRAILER_MIN,  NEC_TRAILER_MAX,  NEC_DATA_BITS,  NEC_BUFF_SIZE  },
	{ AEHA_UNIT_BASE, AEHA_L_ON_T, AEHA_L_OFF_T, AEHA_R_OFF_T, AEHA_V_0_ON_T, AEHA_V_0_OFF_T, AEHA_V_1_ON_T, AEHA_V_1_OFF_T, AEHA_TRAILER_MIN, AEHA_TRAILER_MAX, AEHA_DATA_BITS, AEHA_BUFF_SIZE },
	{ SIRC_UNIT_BASE, SIRC_L_ON_T, SIRC_L_OFF_T, SIRC_R_OFF_T, SIRC_V_0_ON_T, SIRC_V_0_OFF_T, SIRC_V_1_ON_T, SIRC_V_1_OFF_T, SIRC_TRAILER_MIN, SIRC_TRAILER_MAX, SIRC_DATA_BITS, SIRC_BUFF_SIZE }
};

/* 信号詳細データテーブル */
struct remo_con_format FORMAT_DATA_TABLE[REMOCON_FORMAT_NUM];

/* 信号詳細データテーブル作成 */
void make_format_data_table(void)
{
	int i;

	for (i = 0; i < REMOCON_FORMAT_NUM; i++)
	{
		FORMAT_DATA_TABLE[i].U_BASE = FORMAT_BASE_TABLE[i].BASE;
		FORMAT_DATA_TABLE[i].U_MIN = (FORMAT_BASE_TABLE[i].BASE * V_MARGIN_MINUS);
		FORMAT_DATA_TABLE[i].U_MAX = (FORMAT_BASE_TABLE[i].BASE * V_MARGIN_PLUS);
		FORMAT_DATA_TABLE[i].L_ON_MIN = (FORMAT_DATA_TABLE[i].U_MIN * FORMAT_BASE_TABLE[i].L_ON_T_MULTI);
		FORMAT_DATA_TABLE[i].L_ON_MAX = (FORMAT_DATA_TABLE[i].U_MAX * FORMAT_BASE_TABLE[i].L_ON_T_MULTI);
		FORMAT_DATA_TABLE[i].L_OFF_MIN = (FORMAT_DATA_TABLE[i].U_MIN * FORMAT_BASE_TABLE[i].L_OFF_T_MULTI);
		FORMAT_DATA_TABLE[i].L_OFF_MAX = (FORMAT_DATA_TABLE[i].U_MAX * FORMAT_BASE_TABLE[i].L_OFF_T_MULTI);
		FORMAT_DATA_TABLE[i].R_OFF_MIN = (FORMAT_DATA_TABLE[i].U_MIN * FORMAT_BASE_TABLE[i].R_OFF_T_MULTI);
		FORMAT_DATA_TABLE[i].R_OFF_MAX = (FORMAT_DATA_TABLE[i].U_MAX * FORMAT_BASE_TABLE[i].R_OFF_T_MULTI);
		FORMAT_DATA_TABLE[i].V0_ON_MIN = (FORMAT_DATA_TABLE[i].U_MIN * FORMAT_BASE_TABLE[i].V0_ON_T_MULTI);
		FORMAT_DATA_TABLE[i].V0_ON_MAX = (FORMAT_DATA_TABLE[i].U_MAX * FORMAT_BASE_TABLE[i].V0_ON_T_MULTI);
		FORMAT_DATA_TABLE[i].V0_OFF_MIN = (FORMAT_DATA_TABLE[i].U_MIN * FORMAT_BASE_TABLE[i].V0_OFF_T_MULTI);
		FORMAT_DATA_TABLE[i].V0_OFF_MAX = (FORMAT_DATA_TABLE[i].U_MAX * FORMAT_BASE_TABLE[i].V0_OFF_T_MULTI);
		FORMAT_DATA_TABLE[i].V1_ON_MIN = (FORMAT_DATA_TABLE[i].U_MIN * FORMAT_BASE_TABLE[i].V1_ON_T_MULTI);
		FORMAT_DATA_TABLE[i].V1_ON_MAX = (FORMAT_DATA_TABLE[i].U_MAX * FORMAT_BASE_TABLE[i].V1_ON_T_MULTI);
		FORMAT_DATA_TABLE[i].V1_OFF_MIN = (FORMAT_DATA_TABLE[i].U_MIN * FORMAT_BASE_TABLE[i].V1_OFF_T_MULTI);
		FORMAT_DATA_TABLE[i].V1_OFF_MAX = (FORMAT_DATA_TABLE[i].U_MAX * FORMAT_BASE_TABLE[i].V1_OFF_T_MULTI);
		FORMAT_DATA_TABLE[i].TRAIL_MIN = FORMAT_BASE_TABLE[i].TRAIL_MIN;
		FORMAT_DATA_TABLE[i].TRAIL_MAX = FORMAT_BASE_TABLE[i].TRAIL_MAX;
		FORMAT_DATA_TABLE[i].DATA_BITS = FORMAT_BASE_TABLE[i].DATA_BITS;
		FORMAT_DATA_TABLE[i].BUFF_SIZE = FORMAT_BASE_TABLE[i].BUFF_SIZE;
	}
}

bool Remocon::Receive()
{
	int local_bit;

	if (capture_log_pos - _capture_log_pos > CAPTURE_LOG_COUNT) {
		_capture_log_pos = capture_log_pos - CAPTURE_LOG_COUNT;
		_state = None;
	}

	while (_capture_log_pos != capture_log_pos) {
		bool high = (_capture_log_pos % 2) == 0;
		uint16_t wave_width = capture_log[_capture_log_pos % CAPTURE_LOG_COUNT];
		_capture_log_pos++;

		switch (_state) {
		case None:
			if (!high) {
				_state = None;
				break;
			}
			// リーダーコードONチェック
			_code_format_num = FORMAT_NONE;
			for (int i = 0; i < REMOCON_FORMAT_NUM; i++) {
				if ((FORMAT_DATA_TABLE[i].L_ON_MIN < wave_width) && (wave_width < FORMAT_DATA_TABLE[i].L_ON_MAX)) {
					_state = LeaderOn;
					_format = &FORMAT_DATA_TABLE[i];
					_code_format_num = (REMOCON_FORMAT)i;
					break;
				}
			}
			break;
		case LeaderOn:
			// リーダーコードOFFチェック
			if ((_format->L_OFF_MIN < wave_width) && (wave_width < _format->L_OFF_MAX)) {
				switch (_code_format_num) {
				case FORMAT_NEC:
					memset(&nec, 0, sizeof(nec));
					_pos = 0;
					_state = NecFrameDataOn;
					break;
				case FORMAT_AEHA:
					memset(&aeha, 0, sizeof(aeha));
					_pos = 0;
					_state = AehaFrameDataOn;
					break;
				case FORMAT_SIRC:
					memset(&sirc, 0, sizeof(sirc));
					_pos = 0;
					_state = SircFrameDataOn;
					break;
				default:
					// 内部エラー
					_state = None;
					break;
				}
				break;
			}
			// リピートコードOFFチェック
			else if ((_format->R_OFF_MIN < wave_width) && (wave_width < _format->R_OFF_MAX)) {
				switch (_code_format_num) {
				case FORMAT_NEC:
					memset(&nec, 0, sizeof(nec));
					_state = NecStopBitOn;
					break;
				case FORMAT_AEHA:
					memset(&aeha, 0, sizeof(aeha));
					_state = AehaTrailerOn;
					break;
				case FORMAT_SIRC:
					memset(&sirc, 0, sizeof(sirc));
					_state = SircFrameDataOn;
					break;
				default:
					// 内部エラー
					_state = None;
					break;
				}
				break;
			}
			// リーダコード検出できず
			_state = None;
			break;
		case NecFrameDataOn:
			// 前半パルス幅チェック
			if ((_format->U_MIN < wave_width) && (wave_width < _format->U_MAX)) {
				_state = NecFrameDataOff;
				break;
			}
			// フォーマット違反
			_state = None;
			break;
		case NecFrameDataOff:
			// 後半パルス幅チェック
			if ((_format->V1_OFF_MIN < wave_width) && (wave_width < _format->V1_OFF_MAX)) {
				// 値1 //
				if (_pos < 8) {				// カスタムコード前半(8bit).
					nec.custom_code |= (0x01 << (_pos + 8));
				}
				else if (_pos < 16) {		// カスタムコード後半(8bit).
					nec.custom_code |= (0x01 << (_pos - 8));
				}
				else if (_pos < 24) {		// データコード(正)(8bit).
					nec.data_code_A |= (0x01 << (_pos - 16));
				}
				else if (_pos < 32) {		// データコード(反転)(8bit).
					nec.data_code_B |= (0x01 << (_pos - 24));
				}
			}
			else if ((_format->V0_OFF_MIN < wave_width) && (wave_width < _format->V0_OFF_MAX)) {
				// 値0 //
				/* nec.custom_code &= ~(0x01 << i); */ /* 不要 */
			}
			else {
				// フォーマット違反
				_state = None;
				break;
			}
			_pos++;
			if (_pos < (NEC_CCODE_LEN + NEC_DUNIT_LEN + NEC_DUNIT_LEN)) {
				_state = NecFrameDataOn;
			}
			else {
				_state = NecStopBitOn;
			}
			break;
		case NecStopBitOn:
			if ((_format->U_MIN < wave_width) && (wave_width < _format->U_MAX)) {
				if ((nec.data_code_A & nec.data_code_B) == 0) {
					// 受信完了
					_state = None;
					return true;
				}
			}
			// フォーマット違反
			_state = None;
			break;
		case AehaFrameDataOn:
			// 前半パルス幅チェック
			if ((_format->U_MIN < wave_width) && (wave_width < _format->U_MAX)) {
				_state = AehaFrameDataOff;
				break;
			}
			// フォーマット違反
			_state = None;
			break;
		case AehaFrameDataOff:
			// 後半パルス 3Tか(値1か)
			if ((_format->V1_OFF_MIN < wave_width) && (wave_width < _format->V1_OFF_MAX))
			{
				local_bit = 1;
			}
			// 後半パルス 1Tか(値0か)
			else if ((_format->V0_OFF_MIN < wave_width) && (wave_width < _format->V0_OFF_MAX))
			{
				local_bit = 0;
			}
			/* 終端か */
			else if (_format->TRAIL_MIN <= wave_width)
			{
				/* カスタムコードパリティーチェック */
				if ((_pos < (AEHA_CCODE_LEN + AEHA_PARITY_LEN + AEHA_HDATA_LEN))
					|| (aeha.parity != (((aeha.custom_code >> 12) ^ (aeha.custom_code >> 8) ^ (aeha.custom_code >> 4) ^ aeha.custom_code) & 0xF)))
				{
					/* パリティエラー */
					_state = None;
					break;
				}
				/* 可変長データ数 */
				aeha.num = _pos - (AEHA_CCODE_LEN + AEHA_PARITY_LEN + AEHA_HDATA_LEN);

				/* 正常終了 */
				return true;
			}
			if (_pos < AEHA_CCODE_LEN_H)											/* カスタムコード前半 */
			{
				aeha.custom_code |= (local_bit << (_pos + AEHA_CCODE_LEN_H));
			}
			else if (_pos < AEHA_CCODE_LEN)											/* カスタムコード後半 */
			{
				aeha.custom_code |= (local_bit << (_pos - AEHA_CCODE_LEN_H));
			}
			else if (_pos < (AEHA_CCODE_LEN + AEHA_PARITY_LEN))						/* パリティ */
			{
				aeha.parity |= (local_bit << (_pos - AEHA_CCODE_LEN));
			}
			else if (_pos < (AEHA_CCODE_LEN + AEHA_PARITY_LEN + AEHA_HDATA_LEN))	/* data0 */
			{
				aeha.data0 |= (local_bit << (_pos - (AEHA_CCODE_LEN + AEHA_PARITY_LEN)));
			}
			else																	/* 可変長dataN */
			{
				int j = _pos - (AEHA_CCODE_LEN + AEHA_PARITY_LEN + AEHA_HDATA_LEN);
				aeha.dataN[j / 8] |= local_bit << (j % 8);
			}
			_pos++;
			if (_pos < (AEHA_CCODE_LEN + AEHA_PARITY_LEN + AEHA_HDATA_LEN + 8 * sizeof(aeha.dataN))) {
				_state = AehaFrameDataOn;
			}
			else {
				// バッファなし
				_state = None;
			}
			break;
		case AehaTrailerOn:
			// 前半パルス幅チェック
			if ((_format->U_MIN < wave_width) && (wave_width < _format->U_MAX)) {
				// 
				_state = None;
				return true;
			}
			// フォーマット違反
			_state = None;
			break;
		case SircFrameDataOn:
			// ONパルス幅チェック //
			if ((_format->V0_ON_MIN < wave_width) && (wave_width < _format->V0_ON_MAX))
			{
				local_bit = 0;
			}
			else if ((_format->V1_ON_MIN < wave_width) && (wave_width < _format->V1_ON_MAX))
			{
				local_bit = 1;
			}
			else /* フォーマットエラー */
			{
				_state = None;
				break;
			}
			/* 7bit data まで */
			if (_pos < SIRC_DATA_BITS_NUM)
			{
				_state = SircFrameDataOff;
				sirc.data |= (local_bit << _pos);
			}
			else if (_pos < (SIRC_DATA_BITS_NUM + 8 * sizeof(sirc.addr))) /* 終端まで */
			{
				_state = SircFrameDataOff;
				sirc.addr |= (local_bit << (_pos - 7));
			}
			else /* フォーマットエラー */
			{
				_state = None;
				break;
			}
			_pos++;
			break;
		case SircFrameDataOff:
			// OFFパルス幅チェック
			if ((_format->U_MIN < wave_width) && (wave_width < _format->U_MAX)) {
				// 後続データあり
				_state = SircFrameDataOn;
				break;
			}
			if (_pos >= (SIRC_DATA_BITS_NUM + 5)) {
				// 受信完了
				_state = None;
				return true;
			}
			// フォーマット違反
			_state = None;
			break;
		default:
			// 内部エラー
			_state = None;
			break;
		}
	}

	if (_state == SircFrameDataOff) {
		// 受信完了
		_state = None;
		return true;
	}

	return false;
}

void Remocon::Send(NEC_LogData *nec)
{
}

void Remocon::Send(AEHA_LogData *aeha)
{
}

void Remocon::Send(SIRC_LogData *sirc)
{
}

void Remocon::Send(VBUF_LogData *vbuf)
{
}

struct RClass *_class_remocon;

static void mrb_remocon_free(mrb_state *mrb, void *ptr);

const static struct mrb_data_type mrb_remocon_type = { "LCD", mrb_remocon_free };

static mrb_value mrb_remocon_initialize(mrb_state* mrb, mrb_value self)
{
	Remocon *remocon;

	sInitCapture();
	sCaptureStart();

	remocon = new Remocon();
	DATA_TYPE(self) = &mrb_remocon_type;
	DATA_PTR(self) = remocon;

	return self;
}

static void mrb_remocon_free(mrb_state *mrb, void *ptr)
{
	Remocon *remocon = (Remocon *)ptr;

	sCaptureEnd();

	delete remocon;
}

static void
set_hash_value(mrb_state *mrb, mrb_value obj, const char *key, mrb_value val)
{
	mrb_hash_set(mrb, obj, mrb_symbol_value(mrb_intern_static(mrb, key, strlen(key))), val);
}

static mrb_value
get_hash_value(mrb_state *mrb, mrb_value obj, const char *key)
{
	return mrb_hash_get(mrb, obj, mrb_symbol_value(mrb_intern_static(mrb, key, strlen(key))));
}

static mrb_value mrb_remocon_recv(mrb_state* mrb, mrb_value self)
{
	Remocon *remocon = (Remocon *)DATA_PTR(self);
	union {
		NEC_LogData nec;
		AEHA_LogData aeha;
		SIRC_LogData sirc;
		VBUF_LogData vbuf;
	};

	if (!remocon->Receive())
		return mrb_nil_value();

	mrb_value msg = mrb_hash_new(mrb);

	switch (remocon->get_remocon_format())
	{
	case FORMAT_NEC:
		set_hash_value(mrb, msg, "type", mrb_symbol_value(mrb_intern_lit(mrb, "NEC")));
		remocon->get_data(&nec);
		set_hash_value(mrb, msg, "code", mrb_fixnum_value(nec.custom_code));
		set_hash_value(mrb, msg, "data", mrb_fixnum_value(nec.data_code_A));
		break;
	case FORMAT_AEHA:
		set_hash_value(mrb, msg, "type", mrb_symbol_value(mrb_intern_lit(mrb, "AEHA")));
		remocon->get_data(&aeha);
		set_hash_value(mrb, msg, "code", mrb_fixnum_value(aeha.custom_code));
		set_hash_value(mrb, msg, "parity", mrb_fixnum_value(aeha.parity));
		set_hash_value(mrb, msg, "data0", mrb_fixnum_value(aeha.data0));
		set_hash_value(mrb, msg, "data", mrb_str_new(mrb, (char *)&aeha.dataN, (aeha.num + 7) / 8));
		break;
	case FORMAT_SIRC:
		set_hash_value(mrb, msg, "type", mrb_symbol_value(mrb_intern_lit(mrb, "SIRC")));
		remocon->get_data(&sirc);
		set_hash_value(mrb, msg, "data", mrb_fixnum_value(sirc.data));
		set_hash_value(mrb, msg, "address", mrb_fixnum_value(sirc.addr));
		break;
	default:
		set_hash_value(mrb, msg, "type", mrb_symbol_value(mrb_intern_lit(mrb, "UNKNOWN")));
		remocon->get_data(&vbuf);
		set_hash_value(mrb, msg, "data", mrb_str_new(mrb, (char *)&vbuf.data, vbuf.len));
		break;
	} 

	return msg;
}

static mrb_value mrb_remocon_send(mrb_state* mrb, mrb_value self)
{
	Remocon *remocon = (Remocon *)DATA_PTR(self);
	mrb_value msg = mrb_hash_new(mrb);
	mrb_value type;

	mrb_get_args(mrb, "H", &msg);

	type = get_hash_value(mrb, msg, "type");
	if (mrb_symbol(type) == mrb_intern_lit(mrb, "NEC")) {
		NEC_LogData nec;
		mrb_value custom_code;
		mrb_value data;

		memset(&nec, 0, sizeof(nec));
		custom_code = get_hash_value(mrb, msg, "custom_code");
		data = get_hash_value(mrb, msg, "data");

		remocon->Send(&nec);
	}
	else if (mrb_symbol(type) == mrb_intern_lit(mrb, "AEHA")) {
		AEHA_LogData aeha;
		mrb_value custom_code;
		mrb_value data;

		memset(&aeha, 0, sizeof(aeha));
		custom_code = get_hash_value(mrb, msg, "custom_code");
		data = get_hash_value(mrb, msg, "data");

		remocon->Send(&aeha);
	}
	else if (mrb_symbol(type) == mrb_intern_lit(mrb, "SIRC")) {
		SIRC_LogData sirc;
		mrb_value data;
		mrb_value addr;

		memset(&sirc, 0, sizeof(sirc));
		data = get_hash_value(mrb, msg, "data");
		addr = get_hash_value(mrb, msg, "address");

		remocon->Send(&sirc);
	}
	else if (mrb_symbol(type) == mrb_intern_lit(mrb, "UNKNOWN")) {
		VBUF_LogData vbuf;
		mrb_value data;

		memset(&vbuf, 0, sizeof(vbuf));
		data = get_hash_value(mrb, msg, "data");

		remocon->Send(&vbuf);
	}

	return mrb_true_value();
}

extern "C" void mrb_mruby_remocon_gem_init(mrb_state* mrb)
{
	make_format_data_table();

	_class_remocon = mrb_define_class(mrb, "Remocon", mrb->object_class);
	MRB_SET_INSTANCE_TT(_class_remocon, MRB_TT_DATA);

	mrb_define_method(mrb, _class_remocon, "initialize", mrb_remocon_initialize, MRB_ARGS_NONE());
	mrb_define_method(mrb, _class_remocon, "recv", mrb_remocon_recv, MRB_ARGS_NONE());
	mrb_define_method(mrb, _class_remocon, "send", mrb_remocon_send, MRB_ARGS_REQ(1));
}

extern "C" void mrb_mruby_remocon_gem_final(mrb_state* mrb)
{
}
