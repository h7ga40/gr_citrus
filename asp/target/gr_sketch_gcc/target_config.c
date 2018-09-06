/*
 *  TOPPERS/ASP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Advanced Standard Profile Kernel
 * 
 *  Copyright (C) 2000-2003 by Embedded and Real-Time Systems Laboratory
 *                              Toyohashi Univ. of Technology, JAPAN
 *  Copyright (C) 2005-2007 by Embedded and Real-Time Systems Laboratory
 *              Graduate School of Information Science, Nagoya Univ., JAPAN
 *  Copyright (C) 2008-2010 by Witz Corporation, JAPAN
 *  Copyright (C) 2013      by Mitsuhiro Matsuura
 * 
 *  上記著作権者は，以下の(1)～(4)の条件を満たす場合に限り，本ソフトウェ
 *  ア（本ソフトウェアを改変したものを含む．以下同じ）を使用・複製・改
 *  変・再配布（以下，利用と呼ぶ）することを無償で許諾する．
 *  (1) 本ソフトウェアをソースコードの形で利用する場合には，上記の著作
 *      権表示，この利用条件および下記の無保証規定が，そのままの形でソー
 *      スコード中に含まれていること．
 *  (2) 本ソフトウェアを，ライブラリ形式など，他のソフトウェア開発に使
 *      用できる形で再配布する場合には，再配布に伴うドキュメント（利用
 *      者マニュアルなど）に，上記の著作権表示，この利用条件および下記
 *      の無保証規定を掲載すること．
 *  (3) 本ソフトウェアを，機器に組み込むなど，他のソフトウェア開発に使
 *      用できない形で再配布する場合には，次のいずれかの条件を満たすこ
 *      と．
 *    (a) 再配布に伴うドキュメント（利用者マニュアルなど）に，上記の著
 *        作権表示，この利用条件および下記の無保証規定を掲載すること．
 *    (b) 再配布の形態を，別に定める方法によって，TOPPERSプロジェクトに
 *        報告すること．
 *  (4) 本ソフトウェアの利用により直接的または間接的に生じるいかなる損
 *      害からも，上記著作権者およびTOPPERSプロジェクトを免責すること．
 *      また，本ソフトウェアのユーザまたはエンドユーザからのいかなる理
 *      由に基づく請求からも，上記著作権者およびTOPPERSプロジェクトを
 *      免責すること．
 * 
 *  本ソフトウェアは，無保証で提供されているものである．上記著作権者お
 *  よびTOPPERSプロジェクトは，本ソフトウェアに関して，特定の使用目的
 *  に対する適合性も含めて，いかなる保証も行わない．また，本ソフトウェ
 *  アの利用により直接的または間接的に生じたいかなる損害に関しても，そ
 *  の責任を負わない．
 * 
 *  @(#) $Id: target_config.c 1625 2018-08-06 03:54:19Z coas-nagasima $
 */

/*
 *	ターゲットシステム依存モジュール（GR-SAKURA/CITRUS用）
 */

#include "kernel_impl.h"
#include <sil.h>
#include "gr_sketch.h"
#include "rx630_uart.h"

/*
 *  ターゲットシステム依存 初期化ルーチン
 */
void
target_initialize( void )
{
	/*
	 *  プロセッサ依存の初期化
	 */
	prc_initialize();

	/*
	 *  シリアルポートの設定
	 */
	rx630_uart_init(TARGET_PUTC_PORTID, UART_BAUDRATE, UART_CLKSRC);

	/* ポートP20をTxD0, ポートP21をRxD0に */
	sil_wrb_mem(PORT2_PMR_ADDR, 0x03);

	/* データディレクションレジスタ(PDR)の設定 P21(RxD0)を入力ポートにする */
	sil_wrb_mem(PORT2_PDR_ADDR, 
		sil_reb_mem(PORT2_PDR_ADDR) & ~PORT_PDR_B1_BIT);

	/* データディレクションレジスタ(PDR)の設定 P20(TxD0)を出力ポートにする */
	sil_wrb_mem(PORT2_PDR_ADDR, 
		sil_reb_mem(PORT2_PDR_ADDR) | PORT_PDR_B0_BIT);

	/* 書き込みプロテクトレジスタの設定 PFSWEビットへの書き込みを許可 */
	sil_wrb_mem(MPC_PWPR_ADDR, 0x00);
	/* 書き込みプロテクトレジスタの設定 PxxFSレジスタへの書き込みを許可 */
	sil_wrb_mem(MPC_PWPR_ADDR, 0x40);

	/* P21端子機能制御レジスタ RXD0とする */
	sil_wrb_mem(MPC_P21PFS_ADDR, 0x0a);
	/* P20端子機能制御レジスタ TXD0とする */
	sil_wrb_mem(MPC_P20PFS_ADDR, 0x0a);

	/* 書き込みプロテクトレジスタの設定 書き込みを禁止 */
	sil_wrb_mem(MPC_PWPR_ADDR, 0x80);
}


/*
 *  ターゲットシステムの終了ルーチン
 */
void
target_exit( void )
{
	/*
	 *	プロセッサ依存の終了処理
	 */
	prc_terminate();

	while ( 1 );
}


/*
 *  システムログの低レベル出力のための文字出力
 */
void
target_fput_log( char c )
{
	if( c == '\n' ){
		rx630_uart_pol_putc( '\r' , TARGET_PUTC_PORTID );
	}

	rx630_uart_pol_putc( c , TARGET_PUTC_PORTID );
}

void
TOPPERS_assert_abort( void )
{
	syslog(LOG_EMERG, "assert abort.");
#ifndef _MSC_VER
	while (1) asm("nop");
#endif
}

void init()
{
	
}

unsigned long millis()
{
	return fch_hrt() / 1000;
}

unsigned long micros()
{
	return fch_hrt();
}

void delay(unsigned long ms)
{
	if (dly_tsk(ms * 1000) != E_OK)
		TOPPERS_assert_abort();
}

void delayMicroseconds(unsigned int us)
{
	if (dly_tsk(us) != E_OK)
		TOPPERS_assert_abort();
}
