#include "luhn.h"
#include <stddef.h>
#include <string.h>
#include <ctype.h>
bool luhn(const char *num){
    if (!num)return false;

    int count = 0;
    int len = strlen(num);
    int sum = 0;
    for(int i = len -1; i >= 0;i--){
        char c = num[i];
        if(isspace(c)){
            continue;
        }
        if(!isdigit(c)){
            return false;
        }

        int digit = c - '0';
        if(count %2 ==1){
            digit *=2;
            if(digit>9){
                digit -=9;
            }
        }
        sum +=digit;
        count++;
    }
    return(count >1 && (sum%10==0));
}