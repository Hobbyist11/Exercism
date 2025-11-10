#include "binary.h"
#include <stdlib.h> // For atoi()
#include <math.h>


int convert(const char *input){
   int result = 0;
    int inputlen = 0;
    const char *orig = input;
      
    for(int i = 0; *input != '\0'; i++){
        if (*input == '0' || *input == '1'){
          inputlen++;
        input++;  
        }else{
            return -1;
        }
         
    }
     input = (char *)orig;
   

    int int_in = 0;
     int init_result = 0;
    for(int i = inputlen; *input != '\0'; i--){
        char temp = *(input);
  
           int_in = temp - '0';
       
           init_result = int_in * pow(2,i-1);
        result = init_result + result; 
        
        
        
        input++; 
        }

    

    return result;
}