#ifndef DRAW_FONT_H
#define DRAW_FONT_H

#if defined(SHNM16_FONT)
#include "shnm16_font.h"
#elif defined(SHNM12_FONT)
#include "shnm12_font.h"
#else
#include "misaki_font.h"
#endif

#define DISP_X_ADJ	0
#define DISP_Y_ADJ	0
#define X_ZENKAKU_CHARACTERS(hlcd)	((hlcd)->_width / FONT_WIDTH)
#define X_HANKAKU_CHARACTERS(hlcd)	((hlcd)->_width / FONT_HALF_WIDTH)
#define Y_CHARACTERS(hlcd)			((hlcd)->_height / FONT_HEIGHT)
#define X_LINE_TO_PIX(hlcd, x)		((FONT_WIDTH*(x))-DISP_X_ADJ)
#define X_LINE_HALF_TO_PIX(hlcd, x)	((FONT_HALF_WIDTH*(x))-DISP_X_ADJ)
#define Y_ROW_TO_PIX(hlcd, y)		((FONT_HEIGHT*(y))-DISP_Y_ADJ)

#ifdef __cplusplus
extern "C" {
#endif

class Adafruit_GFX;

void get_bitmap_font(const uint8_t *string, uint8_t *bitmap_data, uint32_t *use_chars);

#ifdef __cplusplus
}
#endif

#endif /* DRAW_FONT_H */
