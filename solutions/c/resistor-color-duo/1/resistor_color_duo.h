#ifndef RESISTOR_COLOR_DUO_H
#define RESISTOR_COLOR_DUO_H
typedef enum {
  BLACK =0,
BROWN,
RED,
ORANGE,
YELLOW,
    GREEN,
    BLUE,
    VIOLET,
    GREY,
    WHITE,
} resistor_band_t;

// const resistor_band_t* colors(void);
int color_code(const resistor_band_t *bands);
#endif
