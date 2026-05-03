#include "scrabble_score.h"
#include <ctype.h>

unsigned int score(const char *word){
    char values[7][10] ={{'A','E','I','O','U','L','N','R','S','T'},{'D','G'},{'B','C','M','P'},{'F','H','V','W', 'Y'},{'K'},{'J','X'},{'Q','Z'}};

     int value_scores[7] = {1,2,3,4,5,8,10};
    int score = 0;

     while(*word != '\0'){
    for(int i = 0; i < 7; i++){
        for(int j = 0; j < 10; j++){
             if(toupper(*word) == values[i][j]){
               score+=value_scores[i]; 
            }
            continue; 
            }   
        }
         word++;
    }
    return score;
}