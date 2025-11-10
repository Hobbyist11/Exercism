#include "collatz_conjecture.h"

int steps(int initial){
    if(initial <= 0){
        return -1;
    }
    int steps = 0;
    while (initial != 1){
        if(initial % 2 == 0){
        initial = initial / 2;
        steps++;
        } else{
            initial = (initial * 3) + 1;
            steps++;  
        }
    }
    return steps;
}