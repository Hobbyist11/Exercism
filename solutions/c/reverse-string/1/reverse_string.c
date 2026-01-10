#include "reverse_string.h"
#include <string.h>
#include <stdlib.h>
char *reverse(const char *value){
    int length = strlen(value);
  char* result = malloc(length*sizeof(char));
  for (int i = 0; i < length; i++) {
       
        result[i] = value[length - 1 - i];
    }

    result[length] = '\0';
    return result;
}