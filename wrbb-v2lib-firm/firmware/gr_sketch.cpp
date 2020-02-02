/*
 * WRBB Main
 *
 * Copyright (c) 2016 Wakayama.rb Ruby Board developers
 *
 * This software is released under the MIT License.
 * https://github.com/wakayamarb/wrbb-v2lib-firm/blob/master/MITL
 *
 */
#include <Arduino.h>

#include <eepfile.h>
#include <eeploader.h>
#include <iodefine_gcc63n.h>

#include <mruby/version.h>
#include <mruby.h>

#include <sExec.h>
#include "wrbb.h"
#include <SD.h>

char RubyStartFileName[RUBY_FILENAME_SIZE];	//xmlに指定された最初に起動するmrubyファイル名
char RubyFilename[RUBY_FILENAME_SIZE];
char ExeFilename[RUBY_FILENAME_SIZE];		//現在実行されているファイルのパス名

extern volatile char ProgVer[];
extern bool SdBeginFlag;
int main_time;

//**********************************
//初期化を行います
//**********************************
void init_vm( void )
{
char dat[4];
int en;
int i;

#ifdef GRCITRUS
	//SDファイル関連の初期化
	SdBeginFlag = SdBeginFlag || SD.begin();

	//EEPファイル関連の初期化
	EEP.begin();

	//スタートファイル名を読み込みます
	RubyStartFileName[0] = 0;

	FILEEEP fpj;
	FILEEEP *fp = &fpj;

	//スタートファイル名を読み込みます
	if(EEP.fopen( fp, XML_FILENAME, EEP_READ ) == -1){
		strcpy( RubyStartFileName, RUBY_FILENAME );
	}
	else{
		//file と ack が出るまでひたすら読み込みます
		int pos = 0;
		while( !EEP.fEof(fp) ){
			EEP.fseek(fp, pos, EEP_SEEKTOP);

			dat[0] = 0;
			dat[1] = 0;
			dat[2] = 0;
			dat[3] = 0;
			for( i=0; i< 4; i++ ){
				en = EEP.fread(fp);
				if( en<0 ){ break; }
				dat[i] = (char)en;
			}

			if( RubyStartFileName[0]==0 && dat[0]=='f' && dat[1]=='i' && dat[2]=='l' && dat[3]=='e'  ){

				//見つかったので " or ' まで読み飛ばす
				while( !EEP.fEof(fp) ){
					en = EEP.fread(fp);
					if( en<0 ){ break; }
					if( (char)en==0x22 || (char)en==0x27 ){

						//見つかったので " or ' まで取り込みます
						for( i=0; i<EEPFILENAME_SIZE; i++ ){
							en = EEP.fread(fp);
							if( en<0 ){
								RubyStartFileName[0] = 0;
								break;
							}

							if( (char)en==0x22 || (char)en==0x27 ){
								RubyStartFileName[i] = 0;
								break;
							}
							RubyStartFileName[i] = (char)en;
						}
						break;
					}
				}
			}
			pos++;
		}
		EEP.fclose(fp);
	}
#else
	//SDファイル関連の初期化
	if(!SdBeginFlag && !SD.begin()){
		return;
	}
	SdBeginFlag = true;

	//スタートファイル名を読み込みます
	RubyStartFileName[0] = 0;

	File fp;

	//スタートファイル名を読み込みます
	fp = SD.open( XML_FILENAME, FILE_READ );
	if(!(bool)fp){
		strcpy( RubyStartFileName, RUBY_FILENAME );
	}
	else{
		//file と ack が出るまでひたすら読み込みます
		int pos = 0;
		while( fp.available() ){
			fp.seek(pos);

			dat[0] = 0;
			dat[1] = 0;
			dat[2] = 0;
			dat[3] = 0;
			for( i=0; i< 4; i++ ){
				en = fp.read();
				if( en<0 ){ break; }
				dat[i] = (char)en;
			}

			if( RubyStartFileName[0]==0 && dat[0]=='f' && dat[1]=='i' && dat[2]=='l' && dat[3]=='e'  ){

				//見つかったので " or ' まで読み飛ばす
				while( fp.available() ){
					en = fp.read();
					if( en<0 ){ break; }
					if( (char)en==0x22 || (char)en==0x27 ){

						//見つかったので " or ' まで取り込みます
						for( i=0; i<256; i++ ){
							en = fp.read();
							if( en<0 ){
								RubyStartFileName[0] = 0;
								break;
							}

							if( (char)en==0x22 || (char)en==0x27 ){
								RubyStartFileName[i] = 0;
								break;
							}
							RubyStartFileName[i] = (char)en;
						}
						break;
					}
				}
			}
			pos++;
		}
		fp.close();
	}
#endif

	if(RubyStartFileName[0] == 0){
		strcpy( RubyStartFileName, RUBY_FILENAME );
	}

	//RubyFilenameにスタートファイル名をコピーします
	strcpy( RubyFilename, RubyStartFileName );
}

//**************************************************
// セットアップします
//**************************************************
__attribute__((weak))
void setup()
{
    pinMode(RB_LED, OUTPUT);

#if BOARD == BOARD_GR
    pinMode(PIN_LED0, OUTPUT);
    pinMode(PIN_LED1, OUTPUT);
    pinMode(PIN_LED2, OUTPUT);
    pinMode(PIN_LED3, OUTPUT);
#endif

	//ピンモードを入力に初期化します
	pinModeInit();
	
	//シリアル通信の初期化
	bool isUsbConnect = Serial.begin(115200, SERIAL_8N1);		//仮想USBシリアル

#ifdef GRCITRUS
	//Rubyコード領域をヒープから確保します
	getRubyCodeArea(RUBY_CODE_SIZE);		//このsetup()は、リセット時に一回しか通らないので、freeしなくてもいい。
#endif

	//vmの初期化
	init_vm();

	main_time = millis();

	//Port 3-5がHIGH、またはUSBシリアルが未接続だったら、EEPROMファイルローダーに飛ぶ
	if( FILE_LOAD == 1 && isUsbConnect ){
		while (true){
			if (fileloader((const char*)ProgVer, MRUBY_VERSION)) {
				break;
			}
		}
	}
}

//**************************************************
// 無限ループです
//**************************************************
__attribute__((weak))
void loop()
{
	if( RubyRun()==false ){

		DEBUG_PRINT("RubyRun", "FALSE");
		while (true){
			if (fileloader((const char*)ProgVer, MRUBY_VERSION)) {
				break;
			}
		}
	}
}
