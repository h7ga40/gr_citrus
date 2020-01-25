#ifndef _NET_MISC_H_
#define _NET_MISC_H_

#define NET_MISC_STACK_SIZE	1024		/* NTP クライアントタスク（IPv4）のスタックサイズ	*/

#define NET_MISC_MAIN_PRIORITY	5		/* NTP クライアントタスク（IPv4）の優先度		*/

#ifdef __cplusplus
extern "C"
#endif
void net_misc_task(intptr_t exinf);

#endif	/* _NET_MISC_H_ */
