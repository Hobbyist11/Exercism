#ifndef RESISTOR_COLOR_TRIO_H
#define RESISTOR_COLOR_TRIO_H
#include <stdint.h>

#define COLORS \
BLACK=0, BROWN, RED, ORANGE, YELLOW, GREEN, BLUE, VIOLET, GREY, WHITE

typedef enum RESISTOR_BANDS {COLORS} resistor_band_t;

#define OHMS_SCALE \
OHMS=0,KILOOHMS=1000, MEGAOHMS=1000000,GIGAOHMS=1000000000
typedef enum MEASURE{OHMS_SCALE} ohms_scale_t;

typedef struct {
    uint64_t value;
    ohms_scale_t unit;
}  resistor_value_t;

resistor_value_t color_code(resistor_band_t arr[3]);

#endif
