#include "pangram.h"
#include <ctype.h>
#include <stdlib.h>

bool is_pangram(const char *sentence){
    bool result = true;
    if(sentence == NULL){
        return false;
    }
     
     int arr[26];

    
    for(int i = 0; i < 26; i++){
        arr[i] = 0;
    }
        
    
    for(int i = 0; sentence[i] != '\0'; i++) {
        if(tolower(sentence[i]) >= 97 && tolower(sentence[i]) <= 122) {
            arr[(int)tolower(sentence[i])-97]++;
      }
    }
    for(int i = 0; i < 26; i++){
        if(arr[i] == 0){
            result = false;
        } 
    }
    
    
    return result;
}