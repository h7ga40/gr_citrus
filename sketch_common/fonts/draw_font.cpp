#include <kernel.h>
#include <t_syslog.h>
#include <t_stdlib.h>
#include <string.h>
#include <target_syssvc.h>
#ifndef ADAFRUIT_SSD1306
#include "adafruit_st7735.h"
#else
#include "adafruit_ssd1306.h"
#endif
#include "draw_font.h"

void get_bitmap_font(const uint8_t *string, uint8_t *bitmap_data, uint32_t *use_chars)
{
	uint32_t len, code;
	uint8_t i, j, k;
	uint32_t totalj, totalk;

	*use_chars = 0;
	len = 0;
	if ((string[0] & 0x80) == 0) { len = 1; }
	else if ((string[0] & 0xE0) == 0xC0) { len = 2; }
	else if ((string[0] & 0xF0) == 0xE0) { len = 3; }
	else if ((string[0] & 0xF8) == 0xF0) { len = 4; }
	else { return; }

	j = k = totalj = totalk = 0;

	if (len == 1) {
		code = string[0];
		memcpy(bitmap_data, &UTF8_1B_CODE_BITMAP[code][0], FONT_WIDTH * FONT_HEIGHT / 8);
		*use_chars = 1;
		return;
	}

	if (len == 2) {
		code = string[0];
		// 1バイト目サーチ
		for (i = 0; i < UTF8_CODE_2B_1_NUM; i++) {
			if (Utf8CodeTable_2B_1st[i][0] == code) {
				code = string[1];
				for (j = 0; j < Utf8CodeTable_2B_1st[i][1]; j++) {
					if (UTF8_2B_CODE_BITMAP[totalk].code == code) {
						memcpy(bitmap_data, UTF8_2B_CODE_BITMAP[totalk].bitmap, FONT_WIDTH * FONT_HEIGHT / 8);
						*use_chars = 2;
						return;
					}
					totalk++;
				}
			}
			else {
				totalk += Utf8CodeTable_2B_1st[i][1];
			}
		}
		return;
	}

	if (len == 3) {
		code = string[0];
		// 1バイト目サーチ
		for (i = 0; i < UTF8_CODE_3B_1_NUM; i++) {
			if (Utf8CodeTable_3B_1st[i][0] == code) {
				code = string[1];
				// 2バイト目サーチ
				for (j = 0; j < Utf8CodeTable_3B_1st[i][1]; j++) {
					if (Utf8CodeTable_3B_2nd[totalj][0] == code) {
						code = string[2];
						// 3バイト目サーチ
						for (k = 0; k < Utf8CodeTable_3B_2nd[totalj][1]; k++) {
							if (UTF8_3B_CODE_BITMAP[totalk].code == code) {
								memcpy(bitmap_data, UTF8_3B_CODE_BITMAP[totalk].bitmap, FONT_WIDTH * FONT_HEIGHT / 8);
								*use_chars = 3;
								return;
							}
							totalk++;
						}
						return;
					}
					else {/*読み飛ばすbitmap個数を蓄積*/
						totalk += Utf8CodeTable_3B_2nd[totalj][1];
					}
					totalj++;
				}
			}
			else {/*読み飛ばすbitmap個数を蓄積*/
				for (j = 0; j < Utf8CodeTable_3B_1st[i][1]; j++) {
					totalk += Utf8CodeTable_3B_2nd[totalj][1];
					totalj++;
				}
			}
		}
		return;
	}
}
