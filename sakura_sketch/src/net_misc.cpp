#include <kernel.h>
#include <sil.h>
#include <t_syslog.h>
#include <t_stdlib.h>

#include <tinet_defs.h>
#include <tinet_config.h>

#include <net/if.h>
#include <net/ethernet.h>

#include <net/net.h>
#include <net/net_endian.h>
#include <net/net_var.h>
#include <net/net_timer.h>

#include <netinet/in.h>
#include <netinet/in_var.h>
#include <target_syssvc.h>

#include "dhcp4_cli.h"
#include "dhcp4_cli_var.h"
#include "ntp_cli.h"
#include "kernel_cfg.h"
#include "tinet_cfg.h"
#include "net_misc.h"
#include "netapp.h"

T_DHCP4_CLI_CONTEXT *dhcp4_cli_initialize(ID tskid, ID cepid);
int dhcp4_cli_get_timer(T_DHCP4_CLI_CONTEXT *ct);
void dhcp4_cli_progress(T_DHCP4_CLI_CONTEXT *ct, int elapse);
void dhcp4_cli_wakeup(T_DHCP4_CLI_CONTEXT *ct);
void dhcp4_cli_timeout(T_DHCP4_CLI_CONTEXT *ct);

int net_misc_get_timer(T_DHCP4_CLI_CONTEXT *ct, T_NTP_CLI_CONTEXT *nc)
{
	int timer = dhcp4_cli_get_timer(ct);

	if ((nc->timer != TMO_FEVR) && ((timer == TMO_FEVR) || (timer > nc->timer))) {
		timer = nc->timer;
	}

	return timer;
}

extern T_NTP_CLI_CONTEXT ntp_cli;

/*
 *  DHCP, NTP クライアント タスク
 */

void
net_misc_task (intptr_t exinf)
{
	T_DHCP4_CLI_CONTEXT *ct;
	T_NTP_CLI_CONTEXT *nc = &ntp_cli;
	ER		error = E_OK, ret;
	SYSTIM		prev, time;
	int timer;

	get_tid(&nc->tskid);
	syslog(LOG_NOTICE, "[NET MISC:%d,%d] started.", nc->tskid, (ID)exinf);

	/* 初期化 */
	ct = dhcp4_cli_initialize(nc->tskid, UDP4_DHCP_CLI_CEPID);
	ntp_cli_initialize(nc, NTP_CLI_CEPID);

	ret = get_tim(&time);
	if (ret != E_OK) {
		syslog(LOG_NOTICE, "[NET MISC,%d] get_tim error: %7lu,%s",
			nc->cepid, time / SYSTIM_HZ, itron_strerror(ret));
		return;
	}

	while (true) {
		prev = time;

		/* タイマー取得 */
		timer = net_misc_get_timer(ct, nc);

		/* 待ち */
		error = tslp_tsk(timer);
		if ((error != E_OK) && (error != E_TMOUT)) {
			syslog(LOG_NOTICE, "[NET MISC,%d] tslp_tsk error: %s %d",
				nc->cepid, itron_strerror(error), timer);
			break;
		}

		ret = get_tim(&time);
		if (ret != E_OK) {
			syslog(LOG_NOTICE, "[NET MISC,%d] get_tim error: %s",
				nc->cepid, itron_strerror(ret));
			break;
		}

		/* 時間経過 */
		int elapse = time - prev;
		dhcp4_cli_progress(ct, elapse);
		ntp_cli_progress(nc, elapse);

		/* 起こされた場合 */
		if (error == E_OK) {
			dhcp4_cli_wakeup(ct);
			ntp_cli_wakeup(nc);
		}

		/* タイムアウト処理 */
		dhcp4_cli_timeout(ct);
		ntp_cli_timeout(nc);
	}
}
