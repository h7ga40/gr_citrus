#ifndef _MAIN_H_
#define _MAIN_H_

#include <kernel.h>
#include "target_config.h"
#include "../wrbb.h"

#define MAIN_PRIORITY	(TMAX_TPRI - 1)		/* メインタスクの優先度 */
#define MAIN_STACK_SIZE	2048	/* スタック領域のサイズ */
#define MAIN_STACK_ADDR	(CPU * 1024) - MAIN_STACK_SIZE
#define MAIN_DATAQUEUE_COUNT	5

#define INHNO_CMT0_CMI	INT_CMT0_CMI
#define INTNO_CMT0_CMI	INT_CMT0_CMI
#define INHNO_CMT2_CMI	INT_CMT2_CMI
#define INTNO_CMT2_CMI	INT_CMT2_CMI
#define INHNO_USB0_USBI0	INT_USB0_USBI0
#define INHNO_USB0_USBI0	INT_USB0_USBI0
#define INHNO_IRQ0	INT_IRQ0
#define INTNO_IRQ0	INT_IRQ0
#define INHNO_IRQ1	INT_IRQ1
#define INTNO_IRQ1	INT_IRQ1
#define INHNO_IRQ2	INT_IRQ2
#define INTNO_IRQ2	INT_IRQ2
#define INHNO_IRQ3	INT_IRQ3
#define INTNO_IRQ3	INT_IRQ3
#define INHNO_IRQ4	INT_IRQ4
#define INTNO_IRQ4	INT_IRQ4
#define INHNO_IRQ5	INT_IRQ5
#define INTNO_IRQ5	INT_IRQ5
#define INHNO_IRQ6	INT_IRQ6
#define INTNO_IRQ6	INT_IRQ6
#define INHNO_IRQ7	INT_IRQ7
#define INTNO_IRQ7	INT_IRQ7
#define INHNO_IRQ8	INT_IRQ8
#define INTNO_IRQ8	INT_IRQ8
#define INHNO_IRQ9	INT_IRQ9
#define INTNO_IRQ9	INT_IRQ9
#define INHNO_IRQ10	INT_IRQ10
#define INTNO_IRQ10	INT_IRQ10
#define INHNO_IRQ11	INT_IRQ11
#define INTNO_IRQ11	INT_IRQ11
#define INHNO_IRQ12	INT_IRQ12
#define INTNO_IRQ12	INT_IRQ12
#define INHNO_IRQ13	INT_IRQ13
#define INTNO_IRQ13	INT_IRQ13
#define INHNO_IRQ14	INT_IRQ14
#define INTNO_IRQ14	INT_IRQ14
#define INHNO_IRQ15	INT_IRQ15
#define INTNO_IRQ15	INT_IRQ15
#define INHNO_RTC_ALM	INT_RTC_ALM
#define INTNO_RTC_ALM	INT_RTC_ALM
#define INHNO_ICU_GROUP12	INT_ICU_GROUP12
#define INTNO_ICU_GROUP12	INT_ICU_GROUP12
#define INHNO_TPU1_TGI1A	INT_TPU1_TGI1A
#define INTNO_TPU1_TGI1A	INT_TPU1_TGI1A
#define INHNO_TPU2_TGI2A	INT_TPU2_TGI2A
#define INTNO_TPU2_TGI2A	INT_TPU2_TGI2A
#define INHNO_TPU5_TGI5A	INT_TPU5_TGI5A
#define INTNO_TPU5_TGI5A	INT_TPU5_TGI5A
#define INHNO_TPU5_TGI5B	INT_TPU5_TGI5B
#define INTNO_TPU5_TGI5B	INT_TPU5_TGI5B
#define INHNO_TMR0_CMI0A	INT_TMR0_CMI0A
#define INTNO_TMR0_CMI0A	INT_TMR0_CMI0A
#define INHNO_SCI0_RXI	INT_SCI0_RXI
#define INTNO_SCI0_RXI	INT_SCI0_RXI
#define INHNO_SCI0_TXI	INT_SCI0_TXI
#define INTNO_SCI0_TXI	INT_SCI0_TXI
#define INHNO_SCI1_RXI	INT_SCI1_RXI
#define INTNO_SCI1_RXI	INT_SCI1_RXI
#define INHNO_SCI1_TXI	INT_SCI1_TXI
#define INTNO_SCI1_TXI	INT_SCI1_TXI
#define INHNO_SCI2_RXI	INT_SCI2_RXI
#define INTNO_SCI2_RXI	INT_SCI2_RXI
#define INHNO_SCI2_TXI	INT_SCI2_TXI
#define INTNO_SCI2_TXI	INT_SCI2_TXI
#define INHNO_SCI3_RXI	INT_SCI3_RXI
#define INTNO_SCI3_RXI	INT_SCI3_RXI
#define INHNO_SCI3_TXI	INT_SCI3_TXI
#define INTNO_SCI3_TXI	INT_SCI3_TXI
#define INHNO_SCI5_RXI	INT_SCI5_RXI
#define INTNO_SCI5_RXI	INT_SCI5_RXI
#define INHNO_SCI5_TXI	INT_SCI5_TXI
#define INTNO_SCI5_TXI	INT_SCI5_TXI
#define INHNO_SCI6_RXI	INT_SCI6_RXI
#define INTNO_SCI6_RXI	INT_SCI6_RXI
#define INHNO_SCI6_TXI	INT_SCI6_TXI
#define INTNO_SCI6_TXI	INT_SCI6_TXI
#define INHNO_SCI8_RXI	INT_SCI8_RXI
#define INTNO_SCI8_RXI	INT_SCI8_RXI
#define INHNO_SCI8_TXI	INT_SCI8_TXI
#define INTNO_SCI8_TXI	INT_SCI8_TXI
#define INHNO_S12AD_S12ADI0 INT_S12AD_S12ADI0
#define INTNO_S12AD_S12ADI0 INT_S12AD_S12ADI0
#define INHNO_DMAC_DMAC0I   INT_DMAC_DMAC0I
#define INTNO_DMAC_DMAC0I   INT_DMAC_DMAC0I
#define INHNO_DMAC_DMAC1I   INT_DMAC_DMAC1I
#define INTNO_DMAC_DMAC1I   INT_DMAC_DMAC1I
#define INHNO_DMAC_DMAC2I   INT_DMAC_DMAC2I
#define INTNO_DMAC_DMAC2I   INT_DMAC_DMAC2I
#define INHNO_DMAC_DMAC3I   INT_DMAC_DMAC3I
#define INTNO_DMAC_DMAC3I   INT_DMAC_DMAC3I

#ifndef TOPPERS_MACRO_ONLY

#ifdef __cplusplus
extern "C" {
#endif

extern int ustack;

void main_task(intptr_t exinf);

/* 
 * ノンブロッキングコールのコールバック関数
 */
ER callback_nblk_udp(ID cepid, FN fncd, void *p_parblk);

void IntrTPU5_TGI5A(void);
void IntrTPU5_TGI5B(void);

#ifdef __cplusplus
}
#endif

#endif /* TOPPERS_MACRO_ONLY */

#endif	/* of #ifndef _MAIN_H_ */
