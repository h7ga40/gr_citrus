/*
 *  TOPPERS/ASP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Advanced Standard Profile Kernel
 * 
 *  Copyright (C) 2010 by Witz Corporation, JAPAN
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
 *  @(#) $Id: gr_sketch.h 1625 2018-08-06 03:54:19Z coas-nagasima $
 */

/* GR-SAKURA/CITRUS用ヘッダファル */

#ifndef	TOPPERS_GRSKETCH_H
#define	TOPPERS_GRSKETCH_H


/*
 *  MCU依存情報の読み込み
 */
#include "rx630.h"

/*
 *  クロック設定
 */

/*
 *  システムクロックICLK(kHz)
 *
 *  CPU，DTC，DMACA，ETHERC，EDMAC，ROM，RAM用
 *  
 */
#define FREQ_ICLK  (96000U)

/*
 *  クロックPCLK(kHz)
 *
 *  タイマ，シリアルなど周辺モジュール用
 */
#define FREQ_PCLK  (48000U)


/*
 *  ボーレート設定
 */
#define BAUD_19200BPS		UINT_C( 78 )
#define BAUD_38400BPS		UINT_C( 39 )
#define BAUD_57600BPS		UINT_C( 25 )
#define BAUD_115200BPS		UINT_C( 12 )

#define UART_BAUDRATE		BAUD_38400BPS


/*
 *  クロックソース
 */
#define UART_CLKSRC			CLK_F1

#endif	/* TOPPERS_GRSKETCH_H */

