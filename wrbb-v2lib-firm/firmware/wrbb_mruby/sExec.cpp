/*
	* 呼び出し実行モジュールプログラム
	*
	* Copyright (c) 2016 Wakayama.rb Ruby Board developers
	*
	* This software is released under the MIT License.
	* https://github.com/wakayamarb/wrbb-v2lib-firm/blob/master/MITL
	*
	*/
#include <Arduino.h>
#include <reboot.h>
#include <string.h>

#include <mruby.h>
#include <mruby/irep.h>
#include <mruby/string.h>
#include <mruby/variable.h>
#include <mruby/error.h>
#include <mruby/array.h>
#include <mruby/opcode.h>
#include <mruby/dump.h>

#include <eepfile.h>
#include <SD.h>
#include <eeploader.h>
#include <utility/r_flash_api_rx600.h>

#include "../wrbb.h"
#include "sExec.h"
#include "sKernel.h"
#include "sSys.h"
#include "sSerial.h"
#include "sMem.h"
#include "sI2c.h"
#include "sServo.h"
#include "sGlobal.h"

#if BOARD == BOARD_GR || FIRMWARE == SDBT || FIRMWARE == SDWF || BOARD == BOARD_P05 || BOARD == BOARD_P06
	#include "sSdCard.h"
	#include "sWiFi.h"
#endif

#if REALTIMECLOCK
	#include "sRtc.h"
#endif

#ifdef SAMBOUKAN
	#include "sDCMotor.h"
#endif

//#if FIRMWARE == JAM
//	#include "sPanCake.h"
//#endif
//

//バージョンのセット
volatile char	ProgVer[] = {FIRMWARE_TEXT BOARDNUM WRBB_VERSION BYTECODE_TEXT CPURAM};

extern char RubyStartFileName[];
extern char RubyFilename[];
extern char ExeFilename[];
extern bool SdClassFlag;

#define DF_SIZE 32 * 1024
#ifdef GRCITRUS
//uint8_t RubyCode[RUBY_CODE_SIZE];			//静的にRubyコード領域を確保する
uint8_t *RubyCode = NULL;					//動的にRubyコード領域を確保するため
#else
#define RubyCode ((char *)DF_ADDRESS)	// DATA FLASHにRubyコード領域を確保する
#endif

bool IgnoreOP_STOP = false;

extern char brodata[];
extern char erodata[];

extern "C" mrb_bool mrb_ro_data_p(const char *p)
{
	return (brodata <= p && p < erodata)
		|| (((char *)DF_ADDRESS) <= p && p < &((char *)DF_ADDRESS)[DF_SIZE]);
}

bool cmp_rubycode(int pos, char *buf)
{
	uint32_t *pos1, *pos2, *end = (uint32_t *)&RubyCode[pos + DF_ERASE_BLOCK_SIZE];

	for (pos1 = (uint32_t *)&RubyCode[pos], pos2 = (uint32_t *)buf;
		pos1 < end; pos1++, pos2++){
		if (*pos1 != *pos2)
			return false;
	}

	return true;
}

bool write_rubycode(int pos, char *buf)
{
	uint8_t result;

	if (flash_datarom_blankcheck((int)&RubyCode[pos])) {
		result = flash_datarom_EraseBlock((int)&RubyCode[pos]);
		if (result != FLASH_SUCCESS)
			return false;
	}
	result = flash_datarom_WriteData((int)&RubyCode[pos], buf, DF_ERASE_BLOCK_SIZE);
	if (result != FLASH_SUCCESS)
		return false;

	return true;
}

#ifdef MRB_BYTECODE_DECODE_OPTION
//**************************************************
//  mrubyプログラムの強制停止用フック
//**************************************************
static mrb_code forceVMStopHook(struct mrb_state* mrb, mrb_code code)
{
	if (!IgnoreOP_STOP && (Serial.isBreakState() || Serial.didDtrOffEvent())) {
		return OP_STOP;
	}
	return code;
}
#endif/*MRB_BYTECODE_DECODE_OPTION*/

bool HeaderCheck(rite_binary_header *he, unsigned long tsize)
{
	//ファイル送信でバイナリ―形式にするのを忘れると、ヘッダーのファイルサイズが
	//大きくなってしまい、CRCチェックが終わらないので確認
	unsigned long hsize = 0;

	if (memcmp(he->binary_ident, RITE_BINARY_IDENT, sizeof(he->binary_ident)) == 0) {
		hsize = (he->binary_size[0] << 24) | (he->binary_size[1] << 16)
			| (he->binary_size[2] << 8) | he->binary_size[3];
	}
	else if (memcmp(he->binary_ident, RITE_BINARY_IDENT_LIL, sizeof(he->binary_ident)) == 0) {
		hsize = (he->binary_size[0] << 24) | (he->binary_size[1] << 16)
			| (he->binary_size[2] << 8) | he->binary_size[3];
	}

	if (!(hsize > 0)
#if BYTECODE == BYTE_CODE2
		&& (memcmp(he->binary_version, "0001", sizeof(he->binary_version)) == 0)
#elif BYTECODE == BYTE_CODE3
		&& (memcmp(he->binary_version, "0002", sizeof(he->binary_version)) == 0)
#elif BYTECODE == BYTE_CODE4
		&& ((memcmp(he->binary_version, "0003", sizeof(he->binary_version)) == 0)
			|| (memcmp(he->binary_version, "0004", sizeof(he->binary_version)) == 0))
#endif
		) {
		char az[50];
		sprintf(az, "%s is not supported mrb file.", ExeFilename);
		Serial.println(az);
		return false;
	}
#ifndef GRCITRUS
	if (tsize>RUBY_CODE_SIZE) {
		char az[50];
		sprintf(az, "%s size is greater than %lu.", ExeFilename, RUBY_CODE_SIZE);
		Serial.println(az);
		return false;
	}
#endif
	if (hsize > tsize) {
		char az[70];
		sprintf(az, "%s size is %lu greater than file size %lu.", ExeFilename, hsize, tsize);
		Serial.println(az);
		return false;
	}

	return true;
}

extern bool SdBeginFlag;

//**************************************************
//  スクリプト言語を実行します
//**************************************************
bool RubyRun( void )
{
bool notFinishFlag = true;

	DEBUG_PRINT("mrb_open", "Before");
	mrb_state *mrb = mrb_open();
	DEBUG_PRINT("mrb_open", "After");
	
	if(mrb == NULL){
		Serial.println( "Can not Open mrb!!" );
		return false;
	}

#if (MRUBY_RELEASE_MINOR > 2) && defined(MRB_BYTECODE_DECODE_OPTION)
	mrb->bytecode_decoder = forceVMStopHook;
#endif
	Serial.clearBreakState();
	Serial.clearDtrOffEvent();

	global_Init(mrb);	//グローバル変数の設定
	kernel_Init(mrb);	//カーネル関連メソッドの設定
	sys_Init(mrb);		//システム関連メソッドの設定
	serial_Init(mrb);	//シリアル通信関連メソッドの設定
	mem_Init(mrb);		//ファイル関連メソッドの設定
	i2c_Init(mrb);		//I2C関連メソッドの設定
	servo_Init(mrb);	//サーボ関連メソッドの設定

	//classtest_Init(mrb);

#if REALTIMECLOCK
	rtc_Init(mrb);		//RTC関連メソッドの設定
#endif

#ifdef SAMBOUKAN
	dcMotor_Init(mrb);		//SAMBOUKAの Motorクラス
#endif

//#if FIRMWARE == JAM
//	pancake_Init(mrb);		//PanCake関連メソッドの設定
//#endif

#if GRCITRUS
	strcpy(ExeFilename, RubyFilename);		//実行するファイルをExeFilename[]に入れる。
	//strcpy( RubyFilename, RubyStartFileName );	//とりあえず、RubyFilename[]をRubyStartFileName[]に初期化する。

	RubyFilename[0] = 0;						//Rubyファイル名をクリアする。System.setRun()やFileloaderでセットされ無い限り何も入っていない

	if (ExeFilename[0] == 0) {
		mrb_close(mrb);

		DEBUG_PRINT("ExeFilename", "NULL");
		return false;
	}

	bool result = false;
	for (;;) {
		FILEEEP fpj;
		FILEEEP *fp = &fpj;
		if (EEP.fopen(fp, ExeFilename, EEP_READ) == -1) {
			char az[50];
			sprintf(az, "EEP:%s is not Open!!", ExeFilename);
			EEP.fclose(fp);
			break;
		}

		//先頭にする
		EEP.fseek(fp, 0, EEP_SEEKTOP);

		//ファイルサイズを取得する
		unsigned long tsize = EEP.ffilesize(ExeFilename);

		rite_binary_header he;
		for (int i = 0; i < sizeof(he); i++) { ((uint8_t *)&he)[i] = (uint8_t)EEP.fread(fp); }

		if (!HeaderCheck(&he, tsize)) {
			char az[50];
			sprintf(az, "EEP:%s is not supported mrb file.", ExeFilename);
			Serial.println(az);
			EEP.fclose(fp);
			break;
		}

		//指定のバイト数を超えている場合、ヒープ領域から再取得します。
		if (!getRubyCodeArea(tsize)) {
			char az[50];
			sprintf(az, "EEP:%s size is greater than remaining memory.", ExeFilename);
			Serial.println(az);
			mrb_close(mrb);
			EEP.fclose(fp);

			//RUBY_CODE_SIZEサイズのメモリ領域を再度確保します
			if (!getRubyCodeArea(RUBY_CODE_SIZE)) {
				//この確保もできなかったら、リセットします
				system_reboot(REBOOT_USERAPP);
			}
			return false;
		}

		//先頭にする
		EEP.fseek(fp, 0, EEP_SEEKTOP);

		RubyCode[0] = 0;
		unsigned long pos = 0;
		while (!EEP.fEof(fp)) {
			RubyCode[pos] = (uint8_t)EEP.fread(fp);
			pos++;
		}

		EEP.fclose(fp);

		result = true;
		break;
	}

	//無ければSDカードを検索
	if (!result) {
		File fp = SD.open(ExeFilename, FILE_READ);
		if (!(bool)fp) {
			char az[50];
			sprintf(az, "SD:%s is not Open!!", ExeFilename);
			Serial.println(az);
			mrb_close(mrb);
			return false;
		}

		//mrbファイルチェックを行う
		//int mrbFlag = 0;
		rite_binary_header he;
		for (int i = 0; i < 8; i++) { ((char *)&he)[i] = fp.read(); }

		//先頭にする
		fp.seek(0);

		//ファイルサイズを取得する
		unsigned long tsize = fp.size();

		if (!HeaderCheck(&he, tsize)) {
			char az[50];
			sprintf(az, "SD:%s is not supported mrb file.", ExeFilename);
			Serial.println(az);
			mrb_close(mrb);
			fp.close();
			return false;
		}

		//指定のバイト数を超えている場合、ヒープ領域から再取得します。
		if (!getRubyCodeArea(tsize)) {
			char az[50];
			sprintf(az, "SD:%s size is greater than remaining memory.", ExeFilename);
			Serial.println(az);
			mrb_close(mrb);
			fp.close();

			//RUBY_CODE_SIZEサイズのメモリ領域を再度確保します
			if (!getRubyCodeArea(RUBY_CODE_SIZE)) {
				//この確保もできなかったら、リセットします
				system_reboot(REBOOT_USERAPP);
			}
			return false;
		}

		result = fp.read(RubyCode, tsize) == tsize;

		fp.close();
	}

	if (!result) {
		char az[50];
		sprintf(az, "%s is not Open!!", ExeFilename);
		Serial.println(az);
		mrb_close(mrb);
		return false;
	}
#else
	// ブランクチェックを行ってDATA FLASHをリードモードに移行する
	flash_datarom_blankcheck((int)RubyCode);

	//SDカードがない場合
	if (!SdBeginFlag) {
		strcpy(ExeFilename, RUBY_FILENAME);
		RubyFilename[0] = 0;
		if (!HeaderCheck((rite_binary_header *)RubyCode, RUBY_CODE_SIZE)) {
			mrb_close(mrb);
			return false;
		}
	}
	else {
		strcpy(ExeFilename, RubyFilename);		//実行するファイルをExeFilename[]に入れる。
		//strcpy( RubyFilename, RubyStartFileName );	//とりあえず、RubyFilename[]をRubyStartFileName[]に初期化する。

		RubyFilename[0] = 0;						//Rubyファイル名をクリアする。System.setRun()やFileloaderでセットされ無い限り何も入っていない

		if (ExeFilename[0] == 0) {
			mrb_close(mrb);

			DEBUG_PRINT("ExeFilename", "NULL");
			return false;
		}

		File fp = SD.open(ExeFilename, FILE_READ);
		if (!(bool)fp) {
			char az[50];
			sprintf(az, "%s is not Open!!", ExeFilename);
			Serial.println(az);
			mrb_close(mrb);
			return false;
		}

		//mrbファイルチェックを行う
		//int mrbFlag = 0;
		rite_binary_header he;
		for (int i = 0; i < 8; i++) { ((char *)&he)[i] = fp.read(); }

		//先頭にする
		fp.seek(0);

		//ファイルサイズを取得する
		unsigned long tsize = fp.size();

		if (!HeaderCheck(&he, tsize)) {
			mrb_close(mrb);
			fp.close();
			return false;
		}

		bool result = true;
		unsigned long pos = 0, bpos = 0;
		char buf[DF_ERASE_BLOCK_SIZE];

		// 同じファイルか確認
		while (fp.available()) {
			buf[bpos] = fp.read();
			pos++;
			bpos = pos & ~DF_BLOCK_MASK;
			if (bpos == 0) {
				result = cmp_rubycode(pos - DF_ERASE_BLOCK_SIZE, buf);
				if (!result)
					break;
			}
		}
		while (bpos != 0) {
			buf[bpos] = 0;
			pos++;
			bpos = pos & ~DF_BLOCK_MASK;
			if (bpos == 0) {
				result = cmp_rubycode(pos - DF_ERASE_BLOCK_SIZE, buf);
				if (!result)
					break;
			}
		}

		// 違ったらDATA FLASHに書き込み
		if (!result) {
			//先頭にする
			fp.seek(0);
			pos = 0; bpos = 0;
			while (fp.available()) {
				buf[bpos] = fp.read();
				pos++;
				bpos = pos & ~DF_BLOCK_MASK;
				if (bpos == 0) {
					result = write_rubycode(pos - DF_ERASE_BLOCK_SIZE, buf);
					if (!result)
						break;
				}
			}
			while (bpos != 0) {
				buf[bpos] = 0;
				pos++;
				bpos = pos & ~DF_BLOCK_MASK;
				if (bpos == 0) {
					result = write_rubycode(pos - DF_ERASE_BLOCK_SIZE, buf);
					if (!result)
						break;
				}
			}
		}

		fp.close();
		if (!result) {
			Serial.println("can't write to data flash.");
			mrb_close(mrb);
			return false;
		}
	}
#endif

	DEBUG_PRINT("mruby", "START");

	int arena = mrb_gc_arena_save(mrb);

	//mrubyを実行します
	mrb_load_irep( mrb, (const uint8_t *)RubyCode);

	if( mrb->exc ){
		//struct RString *str;
		char *s;
		int len;

		mrb_value obj = mrb_funcall(mrb, mrb_obj_value(mrb->exc), "inspect", 0);

		if (mrb_string_p(obj)) {
			s = RSTRING_PTR(obj);
			len = RSTRING_LEN(obj);

			const char *e = "Sys#exit";	//Sys#exitだったら正常終了ということ。
			int k = 8;		// ↑が8文字なので。
			int j = 0;
			for( int i=0; i<len; i++ ){
				if(*(s + i) == *(e + j)){
					j++;
					if(j == k){ break; }
				}
				else{
					j = 0;
				}
			}

			if( j<8 ){
				Serial_print_error(mrb, obj);
				notFinishFlag = false;
			}
		}
	}
	mrb->exc = 0;
	mrb_gc_arena_restore(mrb, arena);

	mrb_close(mrb);

	DEBUG_PRINT("mruby", "END");

	SdClassFlag = false;

	if (!IgnoreOP_STOP && (Serial.isBreakState() || Serial.didDtrOffEvent())) {
		notFinishFlag = true;
	}

	return notFinishFlag;
}

//**************************************************
// エラーメッセージ
//**************************************************
void Serial_print_error(mrb_state *mrb, mrb_value obj)
{
	Serial.write((const unsigned char *)RSTRING_PTR(obj), RSTRING_LEN(obj));
	Serial.println();

	mrb_value backtrace = mrb_get_backtrace(mrb);
	for (int i = 0; i < RARRAY_LEN(backtrace); i++) {
		mrb_value v = mrb_ary_ref(mrb, backtrace, i);
		Serial.write((const unsigned char *)RSTRING_PTR(v), RSTRING_LEN(v));
		Serial.println();
	}
}

//**************************************************
// ピンモードを入力に初期化します
//**************************************************
void pinModeInit()
{
	pinMode(RB_LED, OUTPUT);

	pinMode(RB_PIN0, INPUT);
	pinMode(RB_PIN1, INPUT);
	pinMode(RB_PIN2, INPUT);
	pinMode(RB_PIN3, INPUT);
	pinMode(RB_PIN4, INPUT);
	pinMode(RB_PIN5, INPUT);
	pinMode(RB_PIN6, INPUT);
	pinMode(RB_PIN7, INPUT);
	pinMode(RB_PIN8, INPUT);
	pinMode(RB_PIN9, INPUT);
	pinMode(RB_PIN10, INPUT);
	pinMode(RB_PIN11, INPUT);
	pinMode(RB_PIN12, INPUT);
	pinMode(RB_PIN13, INPUT);
	pinMode(RB_PIN14, INPUT);
	pinMode(RB_PIN15, INPUT);
	pinMode(RB_PIN16, INPUT);
	pinMode(RB_PIN17, INPUT);
	pinMode(RB_PIN18, INPUT);
	pinMode(RB_PIN19, INPUT);

	pinMode(RB_PIN20, INPUT);
	pinMode(RB_PIN21, INPUT);
	pinMode(RB_PIN22, INPUT);
	pinMode(RB_PIN23, INPUT);
	pinMode(RB_PIN24, INPUT);
	pinMode(RB_PIN25, INPUT);
	pinMode(RB_PIN26, INPUT);
	pinMode(RB_PIN27, INPUT);
	pinMode(RB_PIN30, INPUT);
	pinMode(RB_PIN31, INPUT);
}
#ifdef GRCITRUS
//**************************************************
// Rubyコード領域をヒープから確保します
//**************************************************
bool getRubyCodeArea(unsigned short size)
{
	if (RubyCode != NULL) {
		free(RubyCode);
		RubyCode = NULL;
	}

	RubyCode = (uint8_t*)malloc(size);

	if (RubyCode == NULL) {
		Serial.println("..Out of Memory!");
		return false;
	}

	return true;
}
#endif
