#include "triangle.h"

bool is_equilateral(triangle_t sides){
    if(sides.a == 0){
        return 0;
    }
   if(sides.a == sides.b && sides.c == sides.a){
       return 1;
   } else{
      return 0;
   }
}
bool is_isosceles(triangle_t sides){
    int result;
    if((sides.a + sides.b) >= sides.c && (sides.b + sides.c) >= sides.a && (sides.a+sides.c) >= sides.b){ 
        if(sides.a == sides.b || sides.c == sides.a || sides.c == sides.b){
         result = 1;
        } else{
            result = 0;
        }
    } else{
        return 0;
    }
    return result;
}
bool is_scalene(triangle_t sides){
    
    if((sides.a + sides.b) >= sides.c && (sides.b + sides.c) >= sides.a &&(sides.a+sides.c) >= sides.b){
        if(sides.a != sides.b && sides.a != sides.c && sides.b != sides.c){
            return true;
        } else {
            return false;
        }
        
    } else{
        return false;
    }
    
}