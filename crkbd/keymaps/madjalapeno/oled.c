#pragma once

#ifdef SSD1306OLED
  #include "ssd1306.h"
#endif

#ifdef OLED_DRIVER_ENABLE

char wpm_str[6];

void render_line(void) {
    oled_write_P(PSTR("\n"), false);
}

void render_logo(void) {
    static const char PROGMEM corne_logo[] = {
        0x80, 0x81, 0x82, 0x83, 0x84,
        0xa0, 0xa1, 0xa2, 0xa3, 0xa4,
        0xc0, 0xc1, 0xc2, 0xc3, 0xc4, 0};
    oled_write_P(corne_logo, false);
    oled_write_P(PSTR("corne"), false);
    render_line();
}

void render_primary(void) {
        render_logo();
        render_line();
        #ifdef WPM_ENABLE
        snprintf(wpm_str, sizeof(wpm_str), " %3d", get_current_wpm());
        #endif // WPM_ENABLE
        render_line();
        #ifdef WPM_ENABLE
        oled_write_ln(" WPM", false);
        render_line();
        oled_write_ln(wpm_str, false);
        #endif // WPM_ENABLE
}

#endif // OLED_DRIVER_ENABLE