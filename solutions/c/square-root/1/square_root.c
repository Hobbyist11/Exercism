#include "square_root.h"
uint16_t square_root(int digit){
    uint16_t L = 0;
    while((L+1)*(L+1)<=digit){
        L+=1;
    }
    return L;
}