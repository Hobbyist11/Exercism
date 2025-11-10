#include "collatz_conjecture.h"

int steps(int initial){
//     for (int i = 0; initial != 1; i++){
//         if(i %2 == 0){
// initial = initial / 2;
//         } else{
//             initial = (initial * 3) + 1;
//         }
//     }
//     return i;
    if(initial == 0 || initial < 0 ){
        return -1;
    }
    if(initial == 1){
        return 0;
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