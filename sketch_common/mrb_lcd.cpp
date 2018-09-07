/*
 * Adafruit_GFX/Adafruit_SSD1306 mruby wrapper
 *
 *  Copyright (C) 2018 Cores Co., Ltd. Japan
 *
 */
#include <mrb_lcd.h>
#include <mruby/array.h>
#include <mruby/class.h>
#include <mruby/data.h>
#include <mruby/string.h>
#include <Arduino.h>
#include <rx63n/iodefine.h>
#include "Adafruit_SSD1306.h"
#include "../wrbb.h"

struct RClass *_class_lcd;

static void mrb_lcd_free(mrb_state *mrb, void *ptr);

const static struct mrb_data_type mrb_lcd_type = { "LCD", mrb_lcd_free };

static mrb_value mrb_lcd_initialize(mrb_state *mrb, mrb_value self)
{
	Adafruit_SSD1306 *lcd;
	mrb_int num, ret;
	TwoWire *wire;

	ret = mrb_get_args(mrb, "|i", &num);
	if (ret == 0)
		num = 3;

#ifdef GRCITRUS
	switch (num) {
	case 0:
		pinMode(RB_PIN18, INPUT_PULLUP);
		pinMode(RB_PIN19, OUTPUT);
		wire = &Wire;
		break;
	case 1:
		pinMode(RB_PIN0, INPUT_PULLUP);
		pinMode(RB_PIN1, OUTPUT);
		wire = &Wire1;
		break;
	case 2:
		pinMode(RB_PIN5, INPUT_PULLUP);
		pinMode(RB_PIN6, OUTPUT);
		wire = &Wire2;
		break;
	case 3:
		pinMode(RB_PIN7, INPUT_PULLUP);
		pinMode(RB_PIN8, OUTPUT);
		wire = &Wire3;
		break;
	case 4:
		pinMode(RB_PIN11, OUTPUT);
		pinMode(RB_PIN12, INPUT_PULLUP);
		wire = &Wire4;
		break;
	case 5:
		pinMode(RB_PIN22, OUTPUT);
		pinMode(RB_PIN26, INPUT_PULLUP);
		wire = &Wire5;
		break;
	default:
		return  mrb_bool_value(false);
		break;
	}
#else
	switch (num) {
	case 0:
		pinMode(A4, INPUT_PULLUP);
		pinMode(A5, OUTPUT);
		wire = &Wire;
		break;
	case 1:
		pinMode(PIN_IO1, INPUT_PULLUP);
		pinMode(PIN_IO0, OUTPUT);
		wire = &Wire1;
		break;
	case 2:
		pinMode(PIN_IO58, INPUT_PULLUP);
		pinMode(PIN_IO60, OUTPUT);
		wire = &Wire2;
		break;
	case 3:
		pinMode(PIN_IO24, INPUT_PULLUP);
		pinMode(PIN_IO26, OUTPUT);
		wire = &Wire3;
		break;
	case 4:
		pinMode(PIN_IO3, OUTPUT);
		pinMode(PIN_IO5, INPUT_PULLUP);
		wire = &Wire4;
		break;
	case 5:
		pinMode(PIN_IO9, OUTPUT);
		pinMode(PIN_IO8, INPUT_PULLUP);
		wire = &Wire5;
		break;
	case 6:
		pinMode(PIN_IO6, OUTPUT);
		pinMode(PIN_IO7, INPUT_PULLUP);
		wire = &Wire6;
		break;
	case 7:
		pinMode(PIN_IO12, OUTPUT);
		pinMode(PIN_IO11, INPUT_PULLUP);
		wire = &Wire7;
		break;
	case 8:
		pinMode(PIN_IO31, OUTPUT);
		pinMode(PIN_IO30, INPUT_PULLUP);
		wire = &Wire8;
		break;
	default:
		return  mrb_bool_value(false);
		break;
	}
#endif

	lcd = new Adafruit_SSD1306(wire);
	DATA_TYPE(self) = &mrb_lcd_type;
	DATA_PTR(self) = lcd;

	lcd->begin(SSD1306_SWITCHCAPVCC, SSD1306_I2C_ADDRESS, true);
	lcd->clearDisplay();
	lcd->display();

	return self;
}

static void mrb_lcd_free(mrb_state *mrb, void *ptr)
{
	Adafruit_SSD1306 *lcd = (Adafruit_SSD1306 *)ptr;

	delete lcd;
}

int8_t to_int8(mrb_int v)
{
	if (v > 0x7F)
		return 0x7F;
	if (v < -0x80)
		return -0x80;
	return v;
}

uint8_t to_uint8(mrb_int v)
{
	if (v > 0xFF)
		return 0xFF;
	if (v < 0)
		return 0;
	return v;
}

int16_t to_int16(mrb_int v)
{
	if (v > 0x7FFF)
		return 0x7FFF;
	if (v < -0x8000)
		return -0x8000;
	return v;
}

uint16_t to_uint16(mrb_int v)
{
	if (v > 0xFFFF)
		return 0xFFFF;
	if (v < 0)
		return 0;
	return v;
}

static mrb_value mrb_lcd_drawBitmap(mrb_state *mrb, mrb_value self)
{
	Adafruit_SSD1306 *lcd = (Adafruit_SSD1306 *)DATA_PTR(self);
	mrb_int x, y, w, h, color, bg, ret;
	mrb_value bitmap;

	ret = mrb_get_args(mrb, "iiSiii|i", &x, &y, &bitmap, &w, &h, &color, &bg);

	if (ret <= 6) {
		lcd->drawBitmap(to_int16(x), to_int16(y), (uint8_t *)mrb_string_value_cstr(mrb, &bitmap), to_int16(w), to_int16(h), to_uint16(color));
	}
	else {
		lcd->drawBitmap(to_int16(x), to_int16(y), (uint8_t *)mrb_string_value_cstr(mrb, &bitmap), to_int16(w), to_int16(h), to_uint16(color), to_uint16(bg));
	}
	lcd->display();

	return self;
}

static mrb_value mrb_lcd_drawChar(mrb_state *mrb, mrb_value self)
{
	Adafruit_SSD1306 *lcd = (Adafruit_SSD1306 *)DATA_PTR(self);
	mrb_int x, y, color, bg, size;
	mrb_value code;

	mrb_get_args(mrb, "iiSiiiii", &x, &y, &code, &color, &bg, &size);

	lcd->drawChar(to_int16(x), to_int16(y), mrb_string_value_cstr(mrb, &code), to_uint16(color), to_uint16(bg), to_uint8(size));
	lcd->display();

	return self;
}

static mrb_value mrb_lcd_drawCircle(mrb_state *mrb, mrb_value self)
{
	Adafruit_SSD1306 *lcd = (Adafruit_SSD1306 *)DATA_PTR(self);
	mrb_int x0, y0, r, color;

	mrb_get_args(mrb, "iiii", &x0, &y0, &r, &color);

	lcd->drawCircle(to_int16(x0), to_int16(y0), r, to_uint16(color));
	lcd->display();

	return self;
}

static mrb_value mrb_lcd_drawFastHLine(mrb_state *mrb, mrb_value self)
{
	Adafruit_SSD1306 *lcd = (Adafruit_SSD1306 *)DATA_PTR(self);
	mrb_int x, y, w, color;

	mrb_get_args(mrb, "iiii", &x, &y, &w, &color);

	lcd->drawFastHLine(to_int16(x), to_int16(y), w, to_uint16(color));
	lcd->display();

	return self;
}

static mrb_value mrb_lcd_drawFastVLine(mrb_state *mrb, mrb_value self)
{
	Adafruit_SSD1306 *lcd = (Adafruit_SSD1306 *)DATA_PTR(self);
	mrb_int x, y, h, color;

	mrb_get_args(mrb, "iiii", &x, &y, &h, &color);

	lcd->drawFastVLine(to_int16(x), to_int16(y), h, to_uint16(color));
	lcd->display();

	return self;
}

static mrb_value mrb_lcd_drawGrayscaleBitmap(mrb_state *mrb, mrb_value self)
{
	Adafruit_SSD1306 *lcd = (Adafruit_SSD1306 *)DATA_PTR(self);
	mrb_int x, y, w, h, ret;
	mrb_value bitmap, mask;

	ret = mrb_get_args(mrb, "iiSii|S", &x, &y, &bitmap, &w, &h, &mask);

	if (ret <= 5) {
		lcd->drawGrayscaleBitmap(to_int16(x), to_int16(y), (uint8_t *)mrb_string_value_cstr(mrb, &bitmap), to_int16(w), to_int16(h));
	}
	else {
		lcd->drawGrayscaleBitmap(to_int16(x), to_int16(y), (uint8_t *)mrb_string_value_cstr(mrb, &bitmap), (uint8_t *)mrb_string_value_cstr(mrb, &mask), to_int16(w), to_int16(h));
	}
	lcd->display();

	return self;
}

static mrb_value mrb_lcd_drawLine(mrb_state *mrb, mrb_value self)
{
	Adafruit_SSD1306 *lcd = (Adafruit_SSD1306 *)DATA_PTR(self);
	mrb_int x0, y0, x1, y1, color;

	mrb_get_args(mrb, "iiiii", &x0, &y0, &x1, &y1, &color);

	lcd->drawLine(to_int16(x0), to_int16(y0), x1, y1, to_uint16(color));
	lcd->display();

	return self;
}

static mrb_value mrb_lcd_drawRGBBitmap(mrb_state *mrb, mrb_value self)
{
	Adafruit_SSD1306 *lcd = (Adafruit_SSD1306 *)DATA_PTR(self);
	mrb_int x, y, w, h, ret;
	mrb_value bitmap, mask;

	ret = mrb_get_args(mrb, "iiSii|S", &x, &y, &bitmap, &w, &h, &mask);

	if (ret <= 4) {
		lcd->drawRGBBitmap(to_int16(x), to_int16(y), (uint16_t *)mrb_string_value_cstr(mrb, &bitmap), to_int16(w), to_int16(h));
	}
	else {
		lcd->drawRGBBitmap(to_int16(x), to_int16(y), (uint16_t *)mrb_string_value_cstr(mrb, &bitmap), (uint8_t *)mrb_string_value_cstr(mrb, &mask), to_int16(w), to_int16(h));
	}
	lcd->display();

	return self;
}

static mrb_value mrb_lcd_drawRect(mrb_state *mrb, mrb_value self)
{
	Adafruit_SSD1306 *lcd = (Adafruit_SSD1306 *)DATA_PTR(self);
	mrb_int x, y, w, h, color;

	mrb_get_args(mrb, "iiii", &x, &y, &w, &h, &color);

	lcd->drawRect(to_int16(x), to_int16(y), to_int16(w), to_int16(h), to_uint16(color));
	lcd->display();

	return self;
}

static mrb_value mrb_lcd_drawRoundRect(mrb_state *mrb, mrb_value self)
{
	Adafruit_SSD1306 *lcd = (Adafruit_SSD1306 *)DATA_PTR(self);
	mrb_int x0, y0, w, h, radius, color;

	mrb_get_args(mrb, "iiiii", &x0, &y0, &w, &h, &radius, &color);

	lcd->drawRoundRect(to_int16(x0), to_int16(y0), to_int16(w), to_int16(h), to_int16(radius), to_uint16(color));
	lcd->display();

	return self;
}

static mrb_value mrb_lcd_drawString(mrb_state *mrb, mrb_value self)
{
	Adafruit_SSD1306 *lcd = (Adafruit_SSD1306 *)DATA_PTR(self);
	mrb_int x, y, color, bg;
	mrb_value string;

	mrb_get_args(mrb, "iiSii|S", &x, &y, &string, &color, &bg);

	lcd->drawString(to_int16(x), to_int16(y), mrb_string_value_cstr(mrb, &string), to_uint16(color), to_uint16(bg));
	lcd->display();

	return self;
}

static mrb_value mrb_lcd_drawTriangle(mrb_state *mrb, mrb_value self)
{
	Adafruit_SSD1306 *lcd = (Adafruit_SSD1306 *)DATA_PTR(self);
	mrb_int x0, y0, x1, y1, x2, y2, color;

	mrb_get_args(mrb, "iiiiiii", &x0, &y0, &x1, &y1, &x2, &y2, &color);

	lcd->drawTriangle(to_int16(x0), to_int16(y0), to_int16(x1), to_int16(y1), to_int16(x2), to_int16(y2), to_uint16(color));
	lcd->display();

	return self;
}

static mrb_value mrb_lcd_drawXBitmap(mrb_state *mrb, mrb_value self)
{
	Adafruit_SSD1306 *lcd = (Adafruit_SSD1306 *)DATA_PTR(self);
	mrb_int x, y, w, h, color;
	mrb_value bitmap;

	mrb_get_args(mrb, "iiSiii", &x, &y, &bitmap, &w, &h, &color);

	lcd->drawXBitmap(to_int16(x), to_int16(y), (const uint8_t *)mrb_string_value_cstr(mrb, &bitmap), to_int16(w), to_int16(h), to_uint16(color));
	lcd->display();

	return self;
}

static mrb_value mrb_lcd_endWrite(mrb_state *mrb, mrb_value self)
{
	Adafruit_SSD1306 *lcd = (Adafruit_SSD1306 *)DATA_PTR(self);

	lcd->endWrite();

	return self;
}

static mrb_value mrb_lcd_fillCircle(mrb_state *mrb, mrb_value self)
{
	Adafruit_SSD1306 *lcd = (Adafruit_SSD1306 *)DATA_PTR(self);
	mrb_int x0, y0, r, color;

	mrb_get_args(mrb, "iiii", &x0, &y0, &r, &color);

	lcd->fillCircle(to_int16(x0), to_int16(y0), to_int16(r), to_uint16(color));
	lcd->display();

	return self;
}

static mrb_value mrb_lcd_fillRect(mrb_state *mrb, mrb_value self)
{
	Adafruit_SSD1306 *lcd = (Adafruit_SSD1306 *)DATA_PTR(self);
	mrb_int x, y, w, h, color;

	mrb_get_args(mrb, "iiiii", &x, &y, &w, &h, &color);

	lcd->fillRect(to_int16(x), to_int16(y), to_int16(w), to_int16(h), to_uint16(color));
	lcd->display();

	return self;
}

static mrb_value mrb_lcd_fillRoundRect(mrb_state *mrb, mrb_value self)
{
	Adafruit_SSD1306 *lcd = (Adafruit_SSD1306 *)DATA_PTR(self);
	mrb_int x0, y0, w, h, radius, color;

	mrb_get_args(mrb, "iiiiii", &x0, &y0, &w, &h, &radius, &color);

	lcd->fillRoundRect(to_int16(x0), to_int16(y0), to_int16(w), to_int16(h), to_int16(radius), to_uint16(color));
	lcd->display();

	return self;
}

static mrb_value mrb_lcd_fillScreen(mrb_state *mrb, mrb_value self)
{
	Adafruit_SSD1306 *lcd = (Adafruit_SSD1306 *)DATA_PTR(self);
	mrb_int color;

	mrb_get_args(mrb, "i", &color);

	lcd->fillScreen(to_uint16(color));
	lcd->display();

	return self;
}

static mrb_value mrb_lcd_fillTriangle(mrb_state *mrb, mrb_value self)
{
	Adafruit_SSD1306 *lcd = (Adafruit_SSD1306 *)DATA_PTR(self);
	mrb_int x0, y0, x1, y1, x2, y2, color;

	mrb_get_args(mrb, "iiiiiii", &x0, &y0, &x1, &y1, &x2, &y2, &color);

	lcd->fillTriangle(to_int16(x0), to_int16(y0), to_int16(x1), to_int16(y1), to_int16(x2), to_int16(y2), to_uint16(color));
	lcd->display();

	return self;
}

static mrb_value mrb_lcd_getCursorX(mrb_state *mrb, mrb_value self)
{
	Adafruit_SSD1306 *lcd = (Adafruit_SSD1306 *)DATA_PTR(self);

	int16_t ret = lcd->getCursorX();

	return mrb_fixnum_value(ret);
}

static mrb_value mrb_lcd_getCursorY(mrb_state *mrb, mrb_value self)
{
	Adafruit_SSD1306 *lcd = (Adafruit_SSD1306 *)DATA_PTR(self);

	int16_t ret = lcd->getCursorY();

	return mrb_fixnum_value(ret);
}

static mrb_value mrb_lcd_getRotation(mrb_state *mrb, mrb_value self)
{
	Adafruit_SSD1306 *lcd = (Adafruit_SSD1306 *)DATA_PTR(self);

	uint8_t ret = lcd->getRotation();

	return mrb_fixnum_value(ret);
}

static mrb_value mrb_lcd_getTextBounds(mrb_state *mrb, mrb_value self)
{
	Adafruit_SSD1306 *lcd = (Adafruit_SSD1306 *)DATA_PTR(self);
	mrb_int x, y;
	int16_t x1, y1;
	uint16_t w, h;
	mrb_value string;
	mrb_value arv[4];

	mrb_get_args(mrb, "Sii", &string, &x, &y);

	lcd->getTextBounds(mrb_string_value_cstr(mrb, &string), to_int16(x), to_int16(y), &x1, &y1, &w, &h);

	arv[0] = mrb_fixnum_value(x1);
	arv[1] = mrb_fixnum_value(y1);
	arv[2] = mrb_fixnum_value(w);
	arv[3] = mrb_fixnum_value(h);

	return mrb_ary_new_from_values(mrb, 4, arv);
}

static mrb_value mrb_lcd_height(mrb_state *mrb, mrb_value self)
{
	Adafruit_SSD1306 *lcd = (Adafruit_SSD1306 *)DATA_PTR(self);

	int16_t ret = lcd->height();

	return mrb_fixnum_value(ret);
}

static mrb_value mrb_lcd_invertDisplay(mrb_state *mrb, mrb_value self)
{
	Adafruit_SSD1306 *lcd = (Adafruit_SSD1306 *)DATA_PTR(self);
	mrb_bool i;

	mrb_get_args(mrb, "b", &i);

	lcd->invertDisplay(i);
	lcd->display();

	return self;
}

static mrb_value mrb_lcd_setCursor(mrb_state *mrb, mrb_value self)
{
	Adafruit_SSD1306 *lcd = (Adafruit_SSD1306 *)DATA_PTR(self);
	mrb_int x, y;

	mrb_get_args(mrb, "ii", &x, &y);

	lcd->setCursor(to_int16(x), to_int16(y));

	return self;
}

static mrb_value mrb_lcd_setFont(mrb_state *mrb, mrb_value self)
{
	Adafruit_SSD1306 *lcd = (Adafruit_SSD1306 *)DATA_PTR(self);
	mrb_value o;
	GFXfont *f = NULL;

	mrb_get_args(mrb, "o", &o);

	lcd->setFont(f);

	return self;
}

static mrb_value mrb_lcd_setRotation(mrb_state *mrb, mrb_value self)
{
	Adafruit_SSD1306 *lcd = (Adafruit_SSD1306 *)DATA_PTR(self);
	mrb_int r;

	mrb_get_args(mrb, "i", &r);

	lcd->setRotation(to_uint8(r));

	return self;
}

static mrb_value mrb_lcd_setTextColor(mrb_state *mrb, mrb_value self)
{
	Adafruit_SSD1306 *lcd = (Adafruit_SSD1306 *)DATA_PTR(self);
	mrb_int c, bg, ret;

	ret = mrb_get_args(mrb, "i|i", &c, &bg);

	if (ret <= 1) {
		lcd->setTextColor(to_uint16(c));
	}
	else {
		lcd->setTextColor(to_uint16(c), to_uint16(bg));
	}

	return self;
}

static mrb_value mrb_lcd_setTextSize(mrb_state *mrb, mrb_value self)
{
	Adafruit_SSD1306 *lcd = (Adafruit_SSD1306 *)DATA_PTR(self);
	mrb_int s;

	mrb_get_args(mrb, "i", &s);

	lcd->setTextSize(to_uint8(s));

	return self;
}

static mrb_value mrb_lcd_setTextWrap(mrb_state *mrb, mrb_value self)
{
	Adafruit_SSD1306 *lcd = (Adafruit_SSD1306 *)DATA_PTR(self);
	mrb_bool w;

	mrb_get_args(mrb, "b", &w);

	lcd->setTextWrap(w);

	return self;
}

static mrb_value mrb_lcd_startWrite(mrb_state *mrb, mrb_value self)
{
	Adafruit_SSD1306 *lcd = (Adafruit_SSD1306 *)DATA_PTR(self);

	lcd->startWrite();

	return self;
}

static mrb_value mrb_lcd_width(mrb_state *mrb, mrb_value self)
{
	Adafruit_SSD1306 *lcd = (Adafruit_SSD1306 *)DATA_PTR(self);

	int16_t ret = lcd->width();

	return mrb_fixnum_value(ret);
}

static mrb_value mrb_lcd_write(mrb_state *mrb, mrb_value self)
{
	Adafruit_SSD1306 *lcd = (Adafruit_SSD1306 *)DATA_PTR(self);
	mrb_int c;

	mrb_get_args(mrb, "i", &c);

	size_t ret = lcd->write(c);
	lcd->display();

	return mrb_fixnum_value(ret);
}

static mrb_value mrb_lcd_writeFastHLine(mrb_state *mrb, mrb_value self)
{
	Adafruit_SSD1306 *lcd = (Adafruit_SSD1306 *)DATA_PTR(self);
	mrb_int x, y, w, color;

	mrb_get_args(mrb, "iiii", &x, &y, &w, &color);

	lcd->writeFastHLine(to_int16(x), to_int16(y), w, to_uint16(color));
	lcd->display();

	return self;
}

static mrb_value mrb_lcd_writeFastVLine(mrb_state *mrb, mrb_value self)
{
	Adafruit_SSD1306 *lcd = (Adafruit_SSD1306 *)DATA_PTR(self);
	mrb_int x, y, h, color;

	mrb_get_args(mrb, "iiii", &x, &y, &h, &color);

	lcd->writeFastVLine(to_int16(x), to_int16(y), h, to_uint16(color));
	lcd->display();

	return self;
}

static mrb_value mrb_lcd_writeFillRect(mrb_state *mrb, mrb_value self)
{
	Adafruit_SSD1306 *lcd = (Adafruit_SSD1306 *)DATA_PTR(self);
	mrb_int x, y, w, h, color;

	mrb_get_args(mrb, "iiiii", &x, &y, &w, &h, &color);

	lcd->writeFillRect(to_int16(x), to_int16(y), to_int16(w), to_int16(h), to_uint16(color));
	lcd->display();

	return self;
}

static mrb_value mrb_lcd_writeLine(mrb_state *mrb, mrb_value self)
{
	Adafruit_SSD1306 *lcd = (Adafruit_SSD1306 *)DATA_PTR(self);
	mrb_int x0, y0, x1, y1, color;

	mrb_get_args(mrb, "iiiii", &x0, &y0, &x1, &y1, &color);

	lcd->writeLine(to_int16(x0), to_int16(y0), x1, y1, to_uint16(color));
	lcd->display();

	return self;
}

static mrb_value mrb_lcd_writePixel(mrb_state *mrb, mrb_value self)
{
	Adafruit_SSD1306 *lcd = (Adafruit_SSD1306 *)DATA_PTR(self);
	mrb_int x, y, color;

	mrb_get_args(mrb, "iii", &x, &y, &color);

	lcd->writePixel(to_int16(x), to_int16(y), to_uint16(color));
	lcd->display();

	return self;
}

extern "C" void mrb_mruby_lcd_gem_init(mrb_state* mrb)
{
	_class_lcd = mrb_define_class(mrb, "LCD", mrb->object_class);
	MRB_SET_INSTANCE_TT(_class_lcd, MRB_TT_DATA);
	mrb_define_method(mrb, _class_lcd, "initialize", mrb_lcd_initialize, MRB_ARGS_NONE());
	mrb_define_method(mrb, _class_lcd, "drawBitmap", mrb_lcd_drawBitmap, MRB_ARGS_REQ(6)|MRB_ARGS_OPT(1));
	mrb_define_method(mrb, _class_lcd, "drawChar", mrb_lcd_drawChar, MRB_ARGS_REQ(8));
	mrb_define_method(mrb, _class_lcd, "drawCircle", mrb_lcd_drawCircle, MRB_ARGS_REQ(4));
	mrb_define_method(mrb, _class_lcd, "drawFastHLine", mrb_lcd_drawFastHLine, MRB_ARGS_REQ(4));
	mrb_define_method(mrb, _class_lcd, "drawFastVLine", mrb_lcd_drawFastVLine, MRB_ARGS_REQ(4));
	mrb_define_method(mrb, _class_lcd, "drawGrayscaleBitmap", mrb_lcd_drawGrayscaleBitmap, MRB_ARGS_REQ(5)|MRB_ARGS_OPT(1));
	mrb_define_method(mrb, _class_lcd, "drawLine", mrb_lcd_drawLine, MRB_ARGS_REQ(5));
	mrb_define_method(mrb, _class_lcd, "drawRGBBitmap", mrb_lcd_drawRGBBitmap, MRB_ARGS_REQ(5)|MRB_ARGS_OPT(1));
	mrb_define_method(mrb, _class_lcd, "drawRect", mrb_lcd_drawRect, MRB_ARGS_REQ(4));
	mrb_define_method(mrb, _class_lcd, "drawRoundRect", mrb_lcd_drawRoundRect, MRB_ARGS_REQ(5));
	mrb_define_method(mrb, _class_lcd, "drawString", mrb_lcd_drawString, MRB_ARGS_REQ(5)|MRB_ARGS_OPT(1));
	mrb_define_method(mrb, _class_lcd, "drawTriangle", mrb_lcd_drawTriangle, MRB_ARGS_REQ(7));
	mrb_define_method(mrb, _class_lcd, "drawXBitmap", mrb_lcd_drawXBitmap, MRB_ARGS_REQ(6));
	mrb_define_method(mrb, _class_lcd, "endWrite", mrb_lcd_endWrite, MRB_ARGS_NONE());
	mrb_define_method(mrb, _class_lcd, "fillCircle", mrb_lcd_fillCircle, MRB_ARGS_REQ(4));
	mrb_define_method(mrb, _class_lcd, "fillRect", mrb_lcd_fillRect, MRB_ARGS_REQ(5));
	mrb_define_method(mrb, _class_lcd, "fillRoundRect", mrb_lcd_fillRoundRect, MRB_ARGS_REQ(6));
	mrb_define_method(mrb, _class_lcd, "fillScreen", mrb_lcd_fillScreen, MRB_ARGS_REQ(1));
	mrb_define_method(mrb, _class_lcd, "fillTriangle", mrb_lcd_fillTriangle, MRB_ARGS_REQ(7));
	mrb_define_method(mrb, _class_lcd, "getCursorX", mrb_lcd_getCursorX, MRB_ARGS_NONE());
	mrb_define_method(mrb, _class_lcd, "getCursorY", mrb_lcd_getCursorY, MRB_ARGS_NONE());
	mrb_define_method(mrb, _class_lcd, "getRotation", mrb_lcd_getRotation, MRB_ARGS_NONE());
	mrb_define_method(mrb, _class_lcd, "getTextBounds", mrb_lcd_getTextBounds, MRB_ARGS_REQ(3));
	mrb_define_method(mrb, _class_lcd, "height", mrb_lcd_height, MRB_ARGS_NONE());
	mrb_define_method(mrb, _class_lcd, "invertDisplay", mrb_lcd_invertDisplay, MRB_ARGS_REQ(1));
	mrb_define_method(mrb, _class_lcd, "setCursor", mrb_lcd_setCursor, MRB_ARGS_REQ(2));
	mrb_define_method(mrb, _class_lcd, "setFont", mrb_lcd_setFont, MRB_ARGS_REQ(1));
	mrb_define_method(mrb, _class_lcd, "setRotation", mrb_lcd_setRotation, MRB_ARGS_REQ(1));
	mrb_define_method(mrb, _class_lcd, "setTextColor", mrb_lcd_setTextColor, MRB_ARGS_REQ(1)|MRB_ARGS_OPT(1));
	mrb_define_method(mrb, _class_lcd, "setTextSize", mrb_lcd_setTextSize, MRB_ARGS_REQ(1));
	mrb_define_method(mrb, _class_lcd, "setTextWrap", mrb_lcd_setTextWrap, MRB_ARGS_REQ(1));
	mrb_define_method(mrb, _class_lcd, "startWrite", mrb_lcd_startWrite, MRB_ARGS_NONE());
	mrb_define_method(mrb, _class_lcd, "width", mrb_lcd_width, MRB_ARGS_NONE());
	mrb_define_method(mrb, _class_lcd, "write", mrb_lcd_write, MRB_ARGS_REQ(1));
	mrb_define_method(mrb, _class_lcd, "writeFastHLine", mrb_lcd_writeFastHLine, MRB_ARGS_REQ(4));
	mrb_define_method(mrb, _class_lcd, "writeFastVLine", mrb_lcd_writeFastVLine, MRB_ARGS_REQ(4));
	mrb_define_method(mrb, _class_lcd, "writeFillRect", mrb_lcd_writeFillRect, MRB_ARGS_REQ(5));
	mrb_define_method(mrb, _class_lcd, "writeLine", mrb_lcd_writeLine, MRB_ARGS_REQ(5));
	mrb_define_method(mrb, _class_lcd, "writePixel", mrb_lcd_writePixel, MRB_ARGS_REQ(3));
}

extern "C" void mrb_mruby_lcd_gem_final(mrb_state* mrb)
{
}
