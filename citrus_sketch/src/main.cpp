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
#include <time.h>

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

	// OS起動前に呼ばれるとタスク外なので、ロックせず続行。
	ret = get_tid(&tskid);
	if (ret != E_OK)
		return;

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

	// OS起動前に呼ばれるとタスク外なので、ロックせず続行。
	ret = get_tid(&tskid);
	if (ret != E_OK)
		return;

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

struct RClass *_module_target_board;

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

mrb_value mrb_target_board_getTime(mrb_state *mrb, mrb_value self)
{
	ER ret;
	SYSTIM now;
	struct tm _tm;
	mrb_value arv[7];

	ret = get_tim(&now);
	if (ret == E_OK) {
		now /= 1000000;
		gmtime_r((time_t *)&now, &_tm);

		arv[0] = mrb_fixnum_value(_tm.tm_year + 1900);
		arv[1] = mrb_fixnum_value(_tm.tm_mon + 1);
		arv[2] = mrb_fixnum_value(_tm.tm_mday);
		arv[3] = mrb_fixnum_value(_tm.tm_hour);
		arv[4] = mrb_fixnum_value(_tm.tm_min);
		arv[5] = mrb_fixnum_value(_tm.tm_sec);
		arv[6] = mrb_fixnum_value(_tm.tm_wday);
	}
	else{
		arv[0] = mrb_fixnum_value(-1);
		arv[1] = mrb_fixnum_value(-1);
		arv[2] = mrb_fixnum_value(-1);
		arv[3] = mrb_fixnum_value(-1);
		arv[4] = mrb_fixnum_value(-1);
		arv[5] = mrb_fixnum_value(-1);
		arv[6] = mrb_fixnum_value(-1);
	}
	return mrb_ary_new_from_values(mrb, 7, arv);
}

mrb_value mrb_target_board_setTime(mrb_state *mrb, mrb_value self)
{
	ER ret;
	SYSTIM now;
	struct tm _tm;
	mrb_value value;

	mrb_get_args(mrb, "A", &value);

	if ( !mrb_array_p( value ) ){
		return mrb_fixnum_value(0);
	}

	int len = RARRAY_LEN( value );
	if(len < 6){
		return mrb_fixnum_value(0);
	}

	_tm.tm_year = mrb_fixnum(mrb_ary_ref(mrb, value, 0)) - 1900;
	_tm.tm_mon = mrb_fixnum(mrb_ary_ref(mrb, value, 1)) - 1;
	_tm.tm_mday = mrb_fixnum(mrb_ary_ref(mrb, value, 2));
	_tm.tm_hour = mrb_fixnum(mrb_ary_ref(mrb, value, 3));
	_tm.tm_min = mrb_fixnum(mrb_ary_ref(mrb, value, 4));
	_tm.tm_sec = mrb_fixnum(mrb_ary_ref(mrb, value, 5));

	if ((now = mktime(&_tm)) != 0)
		return mrb_false_value();

	now *= 1000000;
	ret = set_tim(now);
	if (ret != E_OK)
		return mrb_false_value();

	return mrb_true_value();
}

extern "C" void mrb_mruby_others_gem_init(mrb_state* mrb)
{
	_module_target_board = mrb_define_module(mrb, "TargetBoard");

	mrb_define_module_function(mrb, _module_target_board, "setTime", mrb_target_board_setTime, MRB_ARGS_REQ(6));
	mrb_define_module_function(mrb, _module_target_board, "getTime", mrb_target_board_getTime, MRB_ARGS_NONE());

	mrb_mruby_lcd_gem_init(mrb);
	mrb_mruby_remocon_gem_init(mrb);
}

extern "C" void mrb_mruby_others_gem_final(mrb_state* mrb)
{
	mrb_mruby_lcd_gem_final(mrb);
	mrb_mruby_remocon_gem_final(mrb);
}
