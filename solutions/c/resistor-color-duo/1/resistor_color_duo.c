#include "resistor_color_duo.h"

int color_code(const resistor_band_t *color) {
    int tens;
    int ones;
    int result;
    switch (*(color+0)){
        case BLACK:
            tens = 0;
            break;
        case BROWN:
            tens =1;
            break;
        case RED:
            tens = 2; 
            break;
        case ORANGE:
            tens = 3;
            break;
        case YELLOW:
            tens = 4;
            break;
        case GREEN:
            tens = 5;
            break;
        case BLUE:
            tens = 6;
            break;
        case VIOLET:
            tens = 7;
            break;
        case GREY:
            tens = 8;
            break;
        case WHITE:
            tens = 9;
            break;
    }
    switch (*(color+1)){
        case BLACK:
            ones = 0;
            break;
        case BROWN:
            ones =1;
            break;
        case RED:
            ones = 2; 
            break;
        case ORANGE:
            ones = 3;
            break;
        case YELLOW:
            ones = 4;
            break;
        case GREEN:
            ones = 5;
            break;
        case BLUE:
            ones = 6;
            break;
        case VIOLET:
            ones = 7;
            break;
        case GREY:
            ones = 8;
            break;
        case WHITE:
            ones = 9;
            break;
    }

    result = (tens * 10) + ones;
    return result;
}

