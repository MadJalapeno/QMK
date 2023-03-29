#pragma once

/*
/ MCU is a Blok from Boardsource.xyz
/ Blok is based on RP2040
/ pinout's etc :https://peg.software/docs/blok
/ OLED is connected to I2c SCL (GPIO17), and I2c SDA (GPIO16)
/ 
/ /platforms/chibios/converters/promicro_to_blok/_pins_defs.h
/ D1 = 16U
/ D0 = 17U
*/

#include_next <mcuconf.h>

#undef      RP_I2C_USE_I2C0
#define     RP_I2C_USE_I2C0 TRUE