#include "eliuds_eggs.h"

int egg_count(int decimal){
    int result = 0;
    while(decimal != 0){
        int quotient = decimal / 2;
        int  binary = decimal %2;
        if(binary == 1){
            result++;
        }
        decimal = quotient;
        
    }
    return result;
}