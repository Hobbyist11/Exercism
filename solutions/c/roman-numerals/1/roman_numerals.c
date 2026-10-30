#include "roman_numerals.h"
#include "stdio.h"
#include<stdlib.h>
char *to_roman_numeral(unsigned int number){
    char* roman_result = calloc(20, sizeof(char));    
    unsigned int result_count = 0;
    int temp_num = number;
    int arr_idx = 0;
    
    while(result_count != number){
        if(temp_num < 4){
        roman_result[arr_idx] = 'I';
        arr_idx++;
            
        result_count+=1;
        temp_num -=1;
         } else if(temp_num == 4){
            roman_result[arr_idx] = 'I';
            arr_idx++;
            
            roman_result[arr_idx] = 'V';
          arr_idx++;
            
            result_count+=4;
            temp_num -= 4;

         }
            else if(temp_num >= 5 && temp_num < 9){
            roman_result[arr_idx] = 'V';
             arr_idx++;
            result_count+=5;
                temp_num = temp_num - 5;
        }
        else if(temp_num == 9){
            roman_result[arr_idx] = 'I';
            arr_idx++;
            
            roman_result[arr_idx] = 'X';
            arr_idx++;
            result_count+=9;
            temp_num -= 9;
         }
        else if(temp_num >= 10 && temp_num < 40){
            roman_result[arr_idx] = 'X';
             arr_idx++;
            result_count+=10;
                temp_num -=10;
        }
        else if(temp_num >= 40 && temp_num < 50){
            roman_result[arr_idx] = 'X';
            arr_idx++;
            
            roman_result[arr_idx] = 'L';
            arr_idx++;
            
            result_count+=40;
            temp_num -= 40;
        }
        else if(temp_num >= 50 && temp_num < 90){
            roman_result[arr_idx] = 'L';
             arr_idx++;
            result_count+=50;
               temp_num -=50;
        } else if(temp_num >= 90 && temp_num < 100){
           roman_result[arr_idx] = 'X';
            arr_idx++;
            
            roman_result[arr_idx] = 'C';
            arr_idx++;
            
            result_count+=90;
            temp_num -= 90;
        } else if(temp_num >= 100 && temp_num < 400){
            roman_result[arr_idx] = 'C';
             arr_idx++;
            
            result_count+=100;
               temp_num -=100;
        } else if(temp_num >= 400 && temp_num < 500){
           roman_result[arr_idx] = 'C';
            arr_idx++;
            
            roman_result[arr_idx] = 'D';
            arr_idx++;
            
            result_count+=400;
            temp_num -= 400;
            
        }  else if(temp_num >= 500 && temp_num < 900){
            roman_result[arr_idx] = 'D';
             arr_idx++;
            result_count+=500;
               temp_num -=500;
    
        } else if(temp_num >= 900 && temp_num < 1000){
           roman_result[arr_idx] = 'C';
            arr_idx++;
            
            roman_result[arr_idx] = 'M';
            arr_idx++;
            
            result_count+=900;
            temp_num -= 900;

        } else if(temp_num >= 1000 && temp_num < 4000){
            roman_result[arr_idx] = 'M';
             arr_idx++;
            
            result_count+=1000;
               temp_num -=1000;
        }
         else {
            roman_result[0] = 'A';
            return roman_result;
        }
    }
    return roman_result;
}