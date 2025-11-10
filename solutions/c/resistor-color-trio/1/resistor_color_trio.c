#include "resistor_color_trio.h"
#include "math.h"
   #include <stdint.h>


resistor_value_t r;

resistor_value_t color_code(resistor_band_t arr[3]){
   r.value = (arr[0]*10 + arr[1]) * pow(10,arr[2]);
        if(r.value <1000){
           r.value = r.value;
            r.unit = OHMS;
        } else if(r.value >=1000 && r.value < 1000000){
            r.value = r.value / 1000;
            r.unit = KILOOHMS;
        } else if (r.value >= 1000000 && r.value < 1000000000){
            r.value = r.value / 1000000;
            r.unit = MEGAOHMS;
        } else if (r.value >= 1000000000 ){
            r.value = r.value / 1000000000;
            r.unit = GIGAOHMS;
        }
            
    return r;
}