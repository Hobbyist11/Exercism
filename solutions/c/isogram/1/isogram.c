#include "isogram.h"
#include "ctype.h"
#include<stddef.h>
bool is_isogram(const char phrase[]){
    // Check for NULL
    if (phrase == NULL)
        return false;
    
bool result = true;
int arr[26];
    // Initialize array
    for (int i = 0; i < 26; i++){
        arr[i] = 0;
    }

    // Loop over the phrase and append the letters to the list of letters
    for(int i = 0; phrase[i] != '\0'; i++){
       if(tolower(phrase[i]) >= 97 && tolower(phrase[i]) <= 122) {
            arr[(int)tolower(phrase[i])-97]++;
      }  
    }
       
    // Loop over the alphabet array
    for(int i = 0; i < 26; i++){
        if(arr[i] > 1){
            result = false;
        } 
    }
    return result;
}