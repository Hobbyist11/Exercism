#include "luhn.h"
bool luhn(const char *num){
    bool result = false;
    // Count len
    int len = 0;
    int n2 = 0;
    int total =0;

    // How can we improve this?
    int number_array[60];
    int i = 0;

    while(*num != '\0'){ 
        // If has non digit return false, except spaces
        if( (*num<'0' || *num>'9') && *num != ' '){
            return false;
        }else if(*num == ' '){
            num++;
            continue;
        }
        else{
            number_array[i] = *num - '0';
            i++;
            len++;
        }
        num++;
        
    }
    
    // False if 1 or less len
    if(len <=1){
        return false;
    }
    // Double the digits every n+2 starting at 1
    // If >9 digit -9 then sum all the digits

    // I'm doing it from the left not the right!
    for(int i = len-2; i >=0; i-=2){
        if(len == 1){
            i = 0;
        }
        n2 = number_array[i] * 2;
        if(n2 > 9){
            n2 = n2 - 9;
        }
        number_array[i] = n2;
    }

    // Sum all digits
    for(int i = 0; i < len; i++){
        total += number_array[i];
    }
    if(total % 10 == 0){
        result = true;
    } else {
        result = false;
    }


    // Handle canadian SIN

    return result;
}