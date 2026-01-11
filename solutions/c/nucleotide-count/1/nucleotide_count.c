#include "nucleotide_count.h"
#include <string.h>
#include<stdio.h>
#include <stdlib.h>
char *count(const char *dna_strand){
    if (dna_strand == NULL) return "";
    int len = strlen(dna_strand);
    int countarray[4] = {0,0,0,0};
    for(int i = 0;i <= len-1; i++){
        switch(dna_strand[i]){
            case 'A':
                countarray[0]++;
                break;
            case 'C':
                countarray[1]++;
                break;
            case 'G':
                countarray[2]++;
                break;
            case 'T':
                countarray[3]++;
                break;
            default:{
                char *error_res = calloc(1, sizeof(char));
                return error_res;
            }
             
        }
    }
    int size = snprintf(NULL,0, "'A':%d, 'C': %d, 'G': %d, 'T': %d",countarray[0],countarray[1],countarray[2],countarray[3]);
     char* result = malloc(size + 1); 
     sprintf(result, "A:%d C:%d G:%d T:%d",countarray[0],countarray[1],countarray[2],countarray[3]);

    return result; // Return the pointer to the dynamically allocated string
}
