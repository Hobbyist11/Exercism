#include "perfect_numbers.h"

kind classify_number(int input){
    if(input == 0 || input < 0){
        return -1;
    }
   int result = 0;
    int aliquotsum = 0;
    for(int i = 1;i<input;++i){
        if(input % i == 0){
            aliquotsum = aliquotsum + i;
        }
    }
    
    if(aliquotsum == input){
        result = 1;
    } else if (aliquotsum > input){
        result = 2;
    } else if(aliquotsum < input){
        result = 3;
    } 
    return result;
}