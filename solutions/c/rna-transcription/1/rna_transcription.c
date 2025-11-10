#include "rna_transcription.h"
#include <stdlib.h>

char *to_rna(const char *dna){
   // count number of characters
    const char *dnaptr = dna;
    int count = 0;
    for(int i = 0; *dnaptr != '\n'; i++){
        dnaptr++;
        count++;
    }
    
    char *result = malloc(count+1);
    for(int i = 0; i < count; i++){
        switch(*(dna+i)){
        case 'G':
        *(result+i) = 'C';
                break;
            case 'C':
                *(result+i) = 'G';
                break;
            case 'T':
                *(result+i) = 'A';
                break;
            case 'A':
                *(result+i) = 'U';
                break;
            
        }
    }
     
   
        return result; 
}