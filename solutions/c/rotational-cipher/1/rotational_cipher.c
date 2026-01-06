#include "rotational_cipher.h"
#include <stdlib.h> // for malloc and free
#include <string.h>
char *rotate(const char *text, int shift_key){
    // Review best practice for this
    // char result[100];
    int len = strlen(text);
    char* result = (char*)malloc(len* sizeof(char));
    if (result == NULL) {
        // Always check if allocation failed
        return NULL; 
    }
    // Chars are unicode int, just add the offset
    // Small letters have different ASCII value
    // Modulo 26
    for(int i = 0;i <len;i++){
        // If range of upper
if(text[i]>=65 && text[i]<=90){
    result[i] = ((text[i]-'A') + shift_key)%26 + 'A';
}
        // If range of lower
        else if(text[i]>=97 && text[i]<=122){
    result[i] = ((text[i]-'a') + shift_key)%26 + 'a';
}
        else{
            result[i] = text[i];
        }
    }
    result[len] = '\0';
 
    return result;
}