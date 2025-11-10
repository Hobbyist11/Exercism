#include "difference_of_squares.h"

unsigned int sum_of_squares(unsigned int num){
 unsigned int  running_sum = 0;
 for(unsigned int i = 1; i <= num; i++){
     running_sum = running_sum + (i*i);
}
    return running_sum;
}

unsigned int square_of_sum(unsigned int num){
    unsigned int running_sum =0;
    for(unsigned int i=1; i<=num; i++){
        running_sum = running_sum + i;
    }
    return running_sum * running_sum;
}

unsigned int difference_of_squares(unsigned int num){
    unsigned int sum_square = sum_of_squares(num);
    unsigned int square_sum = square_of_sum(num);

    unsigned int result = square_sum - sum_square;
    return result;
}