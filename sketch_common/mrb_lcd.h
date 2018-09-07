/*
 * Adafruit_GFX/Adafruit_SSD1306 mruby wrapper
 *
 *  Copyright (C) 2018 Cores Co., Ltd. Japan
 *
 */
#ifndef _MRB_LCD_H_
#define _MRB_LCD_H_

#include <mruby.h>

#ifdef __cplusplus
extern "C" {
#endif

void mrb_mruby_lcd_gem_init(mrb_state* mrb);
void mrb_mruby_lcd_gem_final(mrb_state* mrb);

#ifdef __cplusplus
}
#endif

#endif /* _MRB_LCD_H_ */
