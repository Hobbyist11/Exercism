#include "resistor_color.h"
static resistor_band_t colorarr[10]={COLORS};

resistor_band_t *colors(void){
    return colorarr;
}

int color_code(resistor_band_t color){
    return color;
}