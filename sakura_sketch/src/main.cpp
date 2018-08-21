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
#include <tinet_config.h>
#include <tinet_defs.h>
#include <net/ethernet.h>
#include <netinet/in.h>
#include <netinet/in_itron.h>
#include <tinet_cfg.h>
#include <netinet/in_var.h>
#include <net/if6_var.h>
#include <net/net.h>
#include <netinet/udp_var.h>
#include <net/if_var.h>

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
#include "dhcp4_cli.h"
#include "ntp_cli.h"
#include "resolver.h"
#include "netapp_var.h"

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

uint8_t mac_addr[6] = {0x12, 0x34, 0x56, 0x78, 0x9A, 0x01};
bool_t dhcp_enable = true;

struct udp_msg {
	T_IPV4EP dst;
	int len;
	uint8_t buffer[ETHER_MAX_LEN];
};

struct link_msg {
	T_IPV4EP dst;
	int len;
	uint8_t buffer[1];
};

extern int main_time;
struct RClass *_module_target_board;
static void netif_link_callback(T_IFNET *ether);

extern "C" void mbed_mac_address(char *mac)
{
	memcpy(mac, mac_addr, 6);
}

/*
 *  メインタスク
 */
extern "C" void main_task(intptr_t exinf)
{
	/* TINETが起動するまで待つ */
	ether_set_link_callback(netif_link_callback);

	setup();

	while (1) {
		loop();
		//if (serialEventRun) serialEventRun();
	}
}

extern "C" ER callback_nblk_udp(ID cepid, FN fncd, void *p_parblk)
{
	static struct udp_msg msg_inst[2];
	static int msg_no = 0;
	struct udp_msg *msg = &msg_inst[msg_no];
	ER	error = E_OK;

	switch (fncd) {
	case TFN_UDP_CRE_CEP:
	case TFN_UDP_RCV_DAT:
		/* ECN_CAP_PUT("[UDP ECHO SRV] callback_nblk_udp() recv: %u", *(int *)p_parblk); */
		memset(msg, 0, sizeof(struct udp_msg));
		if ((msg->len = udp_rcv_dat(cepid, &msg->dst, msg->buffer, sizeof(msg->buffer), 0)) < 0) {
			syslog(LOG_WARNING, "[UDP ECHO SRV] recv, error: %s", itron_strerror(msg->len));
			return msg->len;
		}
		msg_no = (msg_no + 1) % 2;
		return psnd_dtq(MAIN_DATAQUEUE, (intptr_t)msg);

	case TFN_UDP_SND_DAT:
		break;
	default:
		syslog(LOG_WARNING, "[UDP ECHO SRV] fncd:0x%04X(%s)", -fncd,
			(fncd == TFN_UDP_CRE_CEP ? "TFN_UDP_CRE_CEP" :
			(fncd == TFN_UDP_RCV_DAT ? "TFN_UDP_RCV_DAT" :
			(fncd == TFN_UDP_SND_DAT ? "TFN_UDP_SND_DAT" : "undef"))));

		error = E_PAR;
		break;
	}
	return error;
}

static void netif_link_callback(T_IFNET *ether) {
	static struct link_msg msg_inst[2];
	static int msg_no = 0;
	struct link_msg *msg = &msg_inst[msg_no];
	uint8_t link_up = (ether->flags & IF_FLAG_LINK_UP) != 0;
	uint8_t up = (ether->flags & IF_FLAG_UP) != 0;

	if (dhcp_enable) {
		if (!link_up)
			dhcp4c_rel_info();
		else if (!up)
			dhcp4c_renew_info();
	}
	else {
		up = link_up;
	}

	if (link_up && up)
		ntp_cli_execute();

	memset(msg, 0, sizeof(struct link_msg));

	msg->len = 1;

	if (dhcp_enable) {
		if (!link_up)
			msg->buffer[0] = 0;
		else if (!up)
			msg->buffer[0] = 1;
		else
			msg->buffer[0] = 2;
	}
	else {
		if (!link_up)
			msg->buffer[0] = 0;
		else
			msg->buffer[0] = 2;
	}

	msg_no = (msg_no + 1) % 2;
	psnd_dtq(MAIN_DATAQUEUE, (intptr_t)msg);
}

/*
 * メッセージ受信待ち
 */
static mrb_value mrb_target_board_wait_msg(mrb_state *mrb, mrb_value self)
{
	int timer;
	SYSTIM now;
	ER ret, ret2;
	struct udp_msg *msg;
	mrb_value arv[3];

	mrb_get_args(mrb, "i", &timer);

	/* メッセージ待ち */
	ret = trcv_dtq(MAIN_DATAQUEUE, (intptr_t *)&msg, timer * 1000);
	if ((ret != E_OK) && (ret != E_TMOUT)) {
		syslog(LOG_ERROR, "trcv_dtq");
		return mrb_nil_value();
	}

	ret2 = get_tim(&now);
	if (ret2 != E_OK) {
		syslog(LOG_ERROR, "get_tim");
		return mrb_nil_value();
	}

	arv[0] = mrb_fixnum_value((now - main_time) / 1000);
	main_time = now;

	/* タイムアウトの場合 */
	if (ret == E_TMOUT) {
		return mrb_ary_new_from_values(mrb, 1, arv);
	}

	/* 内部イベントの場合 */
	if (msg->dst.ipaddr == 0) {
		arv[1] = mrb_fixnum_value(msg->buffer[0]);

		return mrb_ary_new_from_values(mrb, 2, arv);
	}
	/* Echonet電文受信の場合 */
	else {
		/* 通信端点 */
		arv[1] = mrb_str_new(mrb, (char *)&msg->dst, sizeof(msg->dst));

		/* 受信データ */
		arv[2] = mrb_str_new(mrb, (char *)msg->buffer, msg->len);

		return mrb_ary_new_from_values(mrb, 3, arv);
	}
}

/*
 * DHCP開始/解放
 */
static mrb_value mrb_target_board_dhclient(mrb_state *mrb, mrb_value self)
{
	mrb_bool enable;
	ER ret;

	mrb_get_args(mrb, "b", &enable);

	if (enable) {
		/* DHCP開始 */
		ret = dhcp4c_renew_info();
	}
	else{
		/* DHCP解放 */
		ret = dhcp4c_rel_info();
	}

	return ret == E_OK ? mrb_true_value() : mrb_false_value();
}

/*
 * 通信レイヤーへの送信
 */
static mrb_value mrb_target_board_snd_msg(mrb_state *mrb, mrb_value self)
{
	mrb_value rep;
	mrb_value rdat;
	T_IPV4EP *ep;
	ER_UINT ret;

	mrb_get_args(mrb, "SS", &rep, &rdat);

	if (RSTRING_LEN(rep) != sizeof(T_IPV4EP)) {
		mrb_raise(mrb, E_RUNTIME_ERROR, "snd_msg");
		return mrb_nil_value();
	}

	ep = (T_IPV4EP *)RSTRING_PTR(rep);

	ret = udp_snd_dat(MAIN_ECNL_UDP_CEPID, ep, RSTRING_PTR(rdat), RSTRING_LEN(rdat), 1000);
	if (ret < 0) {
		mrb_raise(mrb, E_RUNTIME_ERROR, "snd_msg");
		return mrb_nil_value();
	}

	return mrb_nil_value();
}

/*
 * ローカルアドレスか確認
 */
static mrb_value mrb_target_board_is_local_addr(mrb_state *mrb, mrb_value self)
{
	mrb_value rep;
	T_IPV4EP *ep;

	mrb_get_args(mrb, "S", &rep);

	if (RSTRING_LEN(rep) < sizeof(T_IPV4EP)) {
		mrb_raise(mrb, E_RUNTIME_ERROR, "is_local_addr");
		return mrb_nil_value();
	}

	ep = (T_IPV4EP *)RSTRING_PTR(rep);

	return (ep->ipaddr == MAKE_IPV4_ADDR(127, 0, 0, 1)) ? mrb_true_value() : mrb_false_value();
}

/*
 * マルチキャストアドレスか確認
 */
static mrb_value mrb_target_board_is_multicast_addr(mrb_state *mrb, mrb_value self)
{
	mrb_value rep;
	T_IPV4EP *ep;

	mrb_get_args(mrb, "S", &rep);

	if (RSTRING_LEN(rep) < sizeof(T_IPV4EP)) {
		mrb_raise(mrb, E_RUNTIME_ERROR, "is_multicast_addr");
		return mrb_nil_value();
	}

	ep = (T_IPV4EP *)RSTRING_PTR(rep);

	return (ep->ipaddr == MAKE_IPV4_ADDR(224, 0, 23, 0)) ? mrb_true_value() : mrb_false_value();
}

/*
 * 同一アドレスか確認
 */
static mrb_value mrb_target_board_equals_addr(mrb_state *mrb, mrb_value self)
{
	mrb_value rep1, rep2;
	T_IPV4EP *ep1, *ep2;

	mrb_get_args(mrb, "SS", &rep1, &rep2);

	if ((RSTRING_LEN(rep1) != sizeof(T_IPV4EP)) || (RSTRING_LEN(rep2) != sizeof(T_IPV4EP))) {
		mrb_raise(mrb, E_RUNTIME_ERROR, "equals_addr");
		return mrb_nil_value();
	}

	ep1 = (T_IPV4EP *)RSTRING_PTR(rep1);
	ep2 = (T_IPV4EP *)RSTRING_PTR(rep2);

	return (ep1->ipaddr == ep2->ipaddr) ? mrb_true_value() : mrb_false_value();
}

/*
 * ローカルアドレスの取得
 */
static mrb_value mrb_target_board_get_local_addr(mrb_state *mrb, mrb_value self)
{
	T_IPV4EP ep;
	mrb_value rep;

	ep.ipaddr = MAKE_IPV4_ADDR(127, 0, 0, 1);
	ep.portno = 3610;

	rep = mrb_str_new(mrb, (char *)&ep, sizeof(ep));

	return rep;
}

/*
 * マルチキャストアドレスの取得
 */
static mrb_value mrb_target_board_get_multicast_addr(mrb_state *mrb, mrb_value self)
{
	T_IPV4EP ep;
	mrb_value rep;

	ep.ipaddr = MAKE_IPV4_ADDR(224, 0, 23, 0);
	ep.portno = 3610;

	rep = mrb_str_new(mrb, (char *)&ep, sizeof(ep));

	return rep;
}

/*
 * NTP開始
 */
static mrb_value mrb_target_board_ntpdate(mrb_state *mrb, mrb_value self)
{
	/* NTP開始 */
	ntp_cli_execute();

	return mrb_true_value();
}

static mrb_value mrb_target_board_ping(mrb_state *mrb, mrb_value self)
{
	char apip = DEFAULT_API_PROTO;
	mrb_value rline, rret;
	mrb_int tmo, size;
	char *line;
	T_IN_ADDR addr;
	char buf[sizeof("0123:4567:89ab:cdef:0123:4567:255.255.255.255")];

	mrb_get_args(mrb, "S|ii", &rline, &tmo, &size);

	line = RSTRING_PTR(rline);

	if (lookup_ipaddr(&addr, line, &apip) == NULL) {
		return mrb_nil_value();
	}

	buf[0] = '\0';
	if (apip == API_PROTO_IPV6) {
#ifdef SUPPORT_INET6
		ping6(&addr, (uint_t)tmo, (uint_t)size);
		ipv62str(buf, &addr);
#endif
	}
	else {
#ifdef SUPPORT_INET4
#ifdef SUPPORT_INET6
		T_IN4_ADDR addr4;
		addr4 = ntohl(addr.s6_addr32[3]);
		ping4(&addr4, (uint_t)tmo, (uint_t)size);
		ipv42str(buf, &addr4);
#else
		ping4(&addr, (uint_t)tmo, (uint_t)size);
		ipv42str(buf, &addr);
#endif
#endif
	}

	rret = mrb_str_new(mrb, (char *)&buf, strlen(buf));

	return rret;
}

static mrb_value mrb_target_board_nslookup(mrb_state *mrb, mrb_value self)
{
	static char hostname[DBG_LINE_SIZE + 1];
	mrb_value rline, rret;
	char *line;
	T_RSLV_DNS_MSG	rslv;
	ER_UINT		length, offset;
	uint_t		flags;
	uint8_t		*msg;

	rret = mrb_nil_value();

	mrb_get_args(mrb, "S", &rline);

	line = RSTRING_PTR(rline);

	flags = DNS_LUP_FLAGS_PROTO_IPV6 | DNS_LUP_FLAGS_PROTO_IPV4
		| DNS_LUP_FLAGS_QTYPE_A | DNS_LUP_FLAGS_QTYPE_AAAA;

	/* 照会するホスト名・IP アドレスを解析する。*/
	resolv_hoststr(&flags, hostname, sizeof(hostname), line);

	/* 正引きでも逆引きでもプロトコル上は正引きを指定する。*/
	flags |= DNS_LUP_OPCODE_FORWARD;

	/* IPv6 アドレス、または IPv4 アドレスが指定された時は、照会タイプは PTR に設定する。*/
	if (((flags & DNS_LUP_FLAGS_NAME_MASK) == DNS_LUP_FLAGS_NAME_IPV6) ||
		((flags & DNS_LUP_FLAGS_NAME_MASK) == DNS_LUP_FLAGS_NAME_IPV4))
		flags = (flags & ~DNS_LUP_FLAGS_QTYPE_MASK) | DNS_LUP_FLAGS_QTYPE_PTR;

	if ((msg = (uint8_t *)malloc(DNS_UDP_MSG_LENGTH)) == NULL) {
		return rret;
	}

	if ((length = dns_lookup_host(flags | DNS_LUP_FLAGS_MSG, line, msg, DNS_UDP_MSG_LENGTH, &rslv)) < 0) {
		goto err_ret;
	}

	// T_RSLV_DNS_MSGからオブジェクトを作る

err_ret:
	free(msg);

	return rret;
}

extern "C" void mrb_mruby_others_gem_init(mrb_state* mrb)
{
	_module_target_board = mrb_define_module(mrb, "TargetBoard");

	mrb_define_class_method(mrb, _module_target_board, "wait_msg", mrb_target_board_wait_msg, MRB_ARGS_REQ(1));
	mrb_define_class_method(mrb, _module_target_board, "snd_msg", mrb_target_board_snd_msg, MRB_ARGS_REQ(2));
	mrb_define_class_method(mrb, _module_target_board, "is_local_addr", mrb_target_board_is_local_addr, MRB_ARGS_REQ(1));
	mrb_define_class_method(mrb, _module_target_board, "is_multicast_addr", mrb_target_board_is_multicast_addr, MRB_ARGS_REQ(1));
	mrb_define_class_method(mrb, _module_target_board, "equals_addr", mrb_target_board_equals_addr, MRB_ARGS_REQ(2));
	mrb_define_class_method(mrb, _module_target_board, "get_local_addr", mrb_target_board_get_local_addr, MRB_ARGS_NONE());
	mrb_define_class_method(mrb, _module_target_board, "get_multicast_addr", mrb_target_board_get_multicast_addr, MRB_ARGS_NONE());

	mrb_define_class_method(mrb, _module_target_board, "dhclient", mrb_target_board_dhclient, MRB_ARGS_NONE());
	mrb_define_class_method(mrb, _module_target_board, "ntpdate", mrb_target_board_ntpdate, MRB_ARGS_NONE());
	mrb_define_class_method(mrb, _module_target_board, "ping", mrb_target_board_ping, MRB_ARGS_NONE());
	mrb_define_class_method(mrb, _module_target_board, "nslookup", mrb_target_board_nslookup, MRB_ARGS_NONE());
}

extern "C" void mrb_mruby_others_gem_final(mrb_state* mrb)
{
}
