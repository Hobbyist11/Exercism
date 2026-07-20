#include "phone_number.h"
#include <ctype.h>
#include <stdlib.h>
#include <stdbool.h>
char *phone_number_clean(const char *input){ 
    char *result = malloc(sizeof(char) * 13);
    
    int count = 0;
    int input_len = 0;
    // bool has_prefix = false;
   while(input[input_len] != '\0'){
       if(isdigit((unsigned char)input[input_len])){
        result[count] = input[input_len];
        count++;
       }
       input_len++;
   }
    if(count == 11  && result[0] != '1'){
            zero_value(result);
        result[10] = '\0';
            return result;
    } else if ((count == 11 && result[0] == '1') && (result[1] != '0'&&result[1] != '1') && (result[4] != '0' && result[4] != '1')){
        // 2. Shift elements to the left to drop the 0th element
        for (int i = 0; i < count - 1; i++) {
            result[i] = result[i + 1];
        }
        count--; // Decrease our tracker
        result[count] = '\0';
        return result;
    }else if (count == 11 && (result[1] == '0'||result[1] == '1')){
        zero_value(result);
        return result;
    }else if ((count == 10 && result[0] == '1')|| result[0]  == '0'){
        zero_value(result);
        return result;
    } else if (count == 10 && (result[3] == '0' || result[3] == '1')){
     zero_value(result);
        return result;
    }else if (count == 11 && (result[4] == '0' || result[4] == '1')){
     zero_value(result);
        return result;
    }
    
    if(count > 11 || count < 10){
       zero_value(result);
    }
        return result;
}

void zero_value(char *result){
    for(int i = 0; i < 10; i++){
        result[i] = '0';
    }
    result[10] = '\0';
}