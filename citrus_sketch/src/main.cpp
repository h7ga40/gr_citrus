#include <kernel.h>
#include <t_syslog.h>
#include <t_stdlib.h>
#include <sil.h>
#include <string.h>
#include "syssvc/serial.h"
#include "syssvc/syslog.h"
#include "kernel_cfg.h"
#include "main.h"
#include "rx630.h"

#include <Arduino.h>

#include <SD.h>
#include <eeploader.h>

#include <mruby.h>
#include <mruby/compile.h>
#include <mruby/proc.h>
#include <mruby/array.h>
#include <mruby/data.h>
#include <mruby/class.h>
#include <mruby/dump.h>
#include <mruby/string.h>
#include <mruby/version.h>

#include <sExec.h>
#include "../wrbb.h"
#include <rx63n/iodefine.h>
#include "mrb_lcd.h"
#include "mrb_remocon.h"

extern "C" void enableInterrupt(int intno)
{
	ena_int(intno);
}

extern "C" void disableInterrupt(int intno)
{
	dis_int(intno);
}

int lock_count[TNUM_TSKID];

extern "C" void __malloc_lock(struct _reent *r)
{
	ER ret;
	ID tskid;

	ret = get_tid(&tskid);
	if (ret != E_OK)
		abort();

	if (lock_count[tskid] == 0) {
		ret = wai_sem(MLOCK_SEM);
		if (ret != E_OK)
			abort();
	}
	lock_count[tskid]++;
}

extern "C" void __malloc_unlock(struct _reent *r)
{
	ER ret;
	ID tskid;

	ret = get_tid(&tskid);
	if (ret != E_OK)
		abort();

	lock_count[tskid]--;
	if (lock_count[tskid] == 0) {
		ER ret = sig_sem(MLOCK_SEM);
		if (ret != E_OK)
			abort();
	}
}

extern "C" void init_runtime(void);

extern "C" void rx630_uart_init(ID siopid, uint8_t bitrate, uint8_t clksrc)
{
	//Serial.begin(115200);		//仮想USBシリアル
	init_runtime();
}

extern "C" void rx630_uart_pol_putc(char c, ID siopid)
{
	//Serial.print(c);
}

/*
 *  シリアルI/Oポートへのポーリングでの出力
 */
extern "C" ER syslog_wri_log(uint_t prio, const SYSLOG *p_syslog) throw()
{
	return E_OK;
}

/*
 *  メインタスク
 */
extern "C" void main_task(intptr_t exinf)
{
	setup();

	while (1) {
		loop();
		//if (serialEventRun) serialEventRun();
	}
}

extern "C" void mrb_mruby_others_gem_init(mrb_state* mrb)
{
	mrb_mruby_lcd_gem_init(mrb);
	mrb_mruby_remocon_gem_init(mrb);
}

extern "C" void mrb_mruby_others_gem_final(mrb_state* mrb)
{
	mrb_mruby_lcd_gem_final(mrb);
	mrb_mruby_remocon_gem_final(mrb);
}
