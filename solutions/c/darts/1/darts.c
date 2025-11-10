#include "darts.h"
#include <stdlib.h>


const float outside_radius = 100.0;
const  float middle_radius = 25.0;
const  float inside_radius = 1.0;

float power_of2(float num){
    float result;
    return result = ((num-0) * (num-0));
}
int score(coordinate_t position){
dart_board_t section; 
    int result;
  float  border = power_of2(position.x) + power_of2(position.y);
    if( border > outside_radius ){
        section = OUTSIDE;
    }else if( border > middle_radius && border <= outside_radius ){
        section = OUTER;
    }else if(border >inside_radius && border  <= middle_radius){
        section = MIDDLE;
    }else {
        section = INNER;
    }
    
    switch (section){
      case OUTSIDE: 
        result = 0;
    break;
    case OUTER:
    result = 1;
    break;
    case MIDDLE:
    result = 5;
    break;
    case INNER:
    result = 10;
    break;      
    }
    
    return result;
}

