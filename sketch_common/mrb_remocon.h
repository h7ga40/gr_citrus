/*
 * IR Remocon mruby class
 *
 *  Copyright (C) 2018 Cores Co., Ltd. Japan
 *
 */
#ifndef _MRB_REMOCON_H_
#define _MRB_REMOCON_H_

#include <mruby.h>

/* 許容誤差(倍) */
#define V_MARGIN_PLUS	(1.3)
#define V_MARGIN_MINUS	(0.8)

/* 信号フォーマット識別子 */
enum REMOCON_FORMAT {
	FORMAT_NONE = -1,
	FORMAT_NEC,
	FORMAT_AEHA,
	FORMAT_SIRC,
	REMOCON_FORMAT_NUM
};

/* NECフォーマット情報 */
#define NEC_UNIT_BASE		562U
#define NEC_L_ON_T			16U
#define NEC_L_OFF_T			8U
#define NEC_R_OFF_T			4U
#define NEC_V_0_ON_T		1U
#define NEC_V_0_OFF_T		1U
#define NEC_V_1_ON_T		1U
#define NEC_V_1_OFF_T		3U
#define NEC_TRAILER_MIN		0U
#define NEC_TRAILER_MAX		0U
#define NEC_CCODE_H_SIZE	8U	/* 半値 */

/* 家電製品協会フォーマット情報 */
#define AEHA_UNIT_BASE		425U
#define AEHA_UNIT_MIN		AEHA_UNIT_BASE - 75U	/* 詳細不明 */
#define AEHA_UNIT_MAX		AEHA_UNIT_BASE + 75U	/* 詳細不明 */
#define AEHA_L_ON_T			8U
#define AEHA_L_OFF_T		4U
#define AEHA_R_OFF_T		8U
#define AEHA_V_0_ON_T		1U
#define AEHA_V_0_OFF_T		1U
#define AEHA_V_1_ON_T		1U
#define AEHA_V_1_OFF_T		3U
#define AEHA_TRAILER_MIN	8000U
#define AEHA_TRAILER_MAX	0U
#define AEHA_CCODE_H_SIZE	8U	/* 半値 */

/* ソニーフォーマット情報 */
#define SIRC_UNIT_BASE		600U
#define SIRC_L_ON_T			4U
#define SIRC_L_OFF_T		1U
#define SIRC_R_OFF_T		1U
#define SIRC_V_0_ON_T		1U
#define SIRC_V_0_OFF_T		1U
#define SIRC_V_1_ON_T		2U
#define SIRC_V_1_OFF_T		1U
#define SIRC_TRAILER_MIN	6000U
#define SIRC_TRAILER_MAX	30000U
#define SIRC_CCODE_H_SIZE	0U	/* 半値 */

/* 最大信号bit数 */
#define DATA_SIZE_MAX	256U
#define NEC_DATA_BITS	32U
#define AEHA_DATA_BITS	90U	/* dataN数根拠無し */
#define SIRC_DATA_BITS	20U
/* 最大信号サイズ(リーダ含まず, 1bit信号=2バイト(high/low時間)換算) */
#define NEC_BUFF_SIZE	((NEC_DATA_BITS*2)+1)	/* (16+8+8)*2 + 1 */
#define AEHA_BUFF_SIZE	(AEHA_DATA_BITS*2)		/* (16+4+4+64+2)*2 */
#define SIRC_BUFF_SIZE	(SIRC_DATA_BITS*2)		/* (7+13)*2 */

/* データサイズ関連 */
#define NEC_L_ON_T_LEN				NEC_L_ON_T
#define NEC_L_OFF_T_LEN				NEC_L_OFF_T
#define NEC_R_OFF_T_LEN				NEC_R_OFF_T
#define NEC_CCODE_LEN_H				8U
#define NEC_CCODE_LEN				16U
#define NEC_DUNIT_LEN				8U
#define NEC_STOP_BIT				1U

#define AEHA_L_ON_T_LEN				AEHA_L_ON_T
#define AEHA_L_OFF_T_LEN			AEHA_L_OFF_T
#define AEHA_R_OFF_T_LEN			AEHA_R_OFF_T
#define AEHA_CCODE_LEN_H			8U
#define AEHA_CCODE_LEN				16U
#define AEHA_PARITY_LEN				4U
#define AEHA_HDATA_LEN				4U
#define AEHA_HEADER_DATA_BUF_LEN	48U	/* (16+4+4)*2 */
#define AEHA_DATA_LEN				8U

#define SIRC_L_ON_T_LEN				SIRC_L_ON_T
#define SIRC_L_OFF_T_LEN			SIRC_L_OFF_T
#define SIRC_R_OFF_T_LEN			SIRC_L_OFF_T
#define SIRC_DATA_BITS_NUM			7U
#define SIRC_ADDR_OPTION_NUM		3U

/* 信号フォーマット基本情報 */
struct remo_con_format_base_data
{
	uint16_t BASE;
	uint8_t  L_ON_T_MULTI;
	uint8_t  L_OFF_T_MULTI;
	uint8_t  R_OFF_T_MULTI;
	uint8_t  V0_ON_T_MULTI;
	uint8_t  V0_OFF_T_MULTI;
	uint8_t  V1_ON_T_MULTI;
	uint8_t  V1_OFF_T_MULTI;
	uint16_t TRAIL_MIN;
	uint16_t TRAIL_MAX;
	uint16_t DATA_BITS;
	uint16_t BUFF_SIZE;
};

/* リモコン信号情報 */
struct remo_con_format {
	uint16_t U_BASE;
	uint16_t U_MIN;
	uint16_t U_MAX;
	uint16_t L_ON_MIN;
	uint16_t L_ON_MAX;
	uint16_t L_OFF_MIN;
	uint16_t L_OFF_MAX;
	uint16_t R_OFF_MIN;
	uint16_t R_OFF_MAX;
	uint16_t V0_ON_MIN;
	uint16_t V0_ON_MAX;
	uint16_t V0_OFF_MIN;
	uint16_t V0_OFF_MAX;
	uint16_t V1_ON_MIN;
	uint16_t V1_ON_MAX;
	uint16_t V1_OFF_MIN;
	uint16_t V1_OFF_MAX;
	uint16_t TRAIL_MIN;
	uint16_t TRAIL_MAX;
	uint16_t DATA_BITS;
	uint16_t BUFF_SIZE;
};

typedef struct _NEC_LogData {
	uint16_t	custom_code;
	uint8_t		data_code_A;
	uint8_t		data_code_B;
} __attribute__((packed)) NEC_LogData;

typedef struct _AEHA_LogData {
	uint16_t	custom_code;
	uint8_t		parity;
	uint8_t		num;
	uint8_t		data0;
	uint8_t		dataN[8];
} __attribute__((packed)) AEHA_LogData;

typedef struct _SIRC_LogData {
	uint8_t		data;
	uint16_t 	addr;
} __attribute__((packed)) SIRC_LogData;

typedef struct _VBUF_LogData {
	uint8_t 	len;
	uint8_t		data[64];
} __attribute__((packed)) VBUF_LogData;

/* 信号基本データテーブル */
extern const struct remo_con_format_base_data FORMAT_BASE_TABLE[];

/* 信号詳細データテーブル */
extern struct remo_con_format FORMAT_DATA_TABLE[];

void make_format_data_table(void);

#ifdef __cplusplus
extern "C" {
#endif

void mrb_mruby_remocon_gem_init(mrb_state* mrb);
void mrb_mruby_remocon_gem_final(mrb_state* mrb);

#ifdef __cplusplus
}
#endif

#endif // _MRB_REMOCON_H_
