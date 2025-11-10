#include "grains.h"

uint64_t square(uint8_t index){   
    uint64_t result = 1;
    if(index == 0){
         result  = 0;   
        }
    
    for(int i = 1; i<=index; i++){
        if(i == 1){
         result = i * 1;
         } else{
         result =  2 * result;
         }
   
}
     return result;
}

uint64_t total(void){
    uint64_t total = 0;
    for (int i =1; i <= 64; i++){
        total = total+square(i);
    }
    return total;
}