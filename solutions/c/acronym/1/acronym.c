#include "acronym.h"
#include <stdlib.h>
#include <ctype.h>
char* abbreviate(const char *phrase){
    if(phrase == NULL || phrase[0] == '\0'){
        return NULL;
    }
    int i = 0;
    int counter = 0;
    int count = 0;
    char* result = malloc(sizeof(char)*20);
    for(int i = 0; i < 20; i++){
        result[i] = ' ';
    }
    while(phrase[i] != '\0'){
        if(counter == 0 && isalpha(phrase[i]) ){
            result[count] = toupper(phrase[i]);
            count++;
            counter++;
        }
        if(phrase[i] == ' ' || phrase[i] == '-'){
            counter = 0;
            i++;
            continue;
        }
    i++;
    }
    result[count] = '\0';
    return result;
}