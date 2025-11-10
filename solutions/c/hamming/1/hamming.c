#include "hamming.h"
 #include <string.h> 
int compute(const char *lhs, const char *rhs){
int result = 0;
   int length_left = strlen(lhs);
       int length_right = strlen(rhs);

    if (length_left != length_right){
        return -1;
    }

    
    for(int i = 0; i < length_left; i++){
        if(lhs[i] != rhs[i]){
         result++;   
        }
    }
           return result;
}