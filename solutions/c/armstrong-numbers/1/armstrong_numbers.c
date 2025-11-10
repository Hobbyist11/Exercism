#include "armstrong_numbers.h"
#include "math.h"
bool is_armstrong_number(int candidate){
    // How to count the number of digits in a number? 0-9 is 1, 10-99 is 2, 100-999 is 3;
    bool result;
    int digits = log10(candidate)+1;
    int original = candidate;
    int score = 0;
  int i = 0;
    int temp;
    /// Get the xth digit
    while(candidate){
        temp = candidate%10;
        score = pow(temp,digits) + score;
              i++;
        candidate /= 10;
  
    }
    if(score == original)
        result = true;
    else
        result = false;
    return result;
}