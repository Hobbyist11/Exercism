#include "resistor_color.h"

int color_code(resistor_band_t color) {
    int result;
    switch (color){
        case BLACK:
            result = 0;
            break;
        case BROWN:
            result =1;
            break;
        case RED:
            result = 2; 
            break;
        case ORANGE:
            result = 3;
            break;
        case YELLOW:
            result = 4;
            break;
        case GREEN:
            result = 5;
            break;
        case BLUE:
            result = 6;
            break;
        case VIOLET:
            result = 7;
            break;
        case GREY:
            result = 8;
            break;
        case WHITE:
            result = 9;
            break;
    }
    return result;
}

const resistor_band_t results []={
         BLACK,
BROWN,
RED,
    ORANGE,
YELLOW,
    GREEN,
    BLUE,
    VIOLET,
    GREY,
    WHITE,
    };
const resistor_band_t* colors(void){
    
   return results;
}