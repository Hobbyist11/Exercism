#include "dnd_character.h"
#include <math.h>
 #include <stdlib.h> // For rand() and srand()
    #include <time.h>   // For time() to seed the random number generator

int custom_round(double x) {
    if (x >= 0.0) {
        // Positive numbers: 0.5 rounds to 0 (truncate)
        // This is equivalent to rounding 'half toward zero'
        return (int)x; 
    } else {
        // Negative numbers: -3.5 rounds to -4 (rounds away from zero / down)
        // This is equivalent to a 'floor' function for negative numbers
        return (int)floor(x);
    }
}
int ability(void){
    int randomNumber = 3 + rand() % (18 - 3 + 1);
    return randomNumber;
}

int modifier(int score){
    // return (score-10)/2;
  score = custom_round((score-10.0)/2.0);
    return score;
}

dnd_character_t make_dnd_character(void){
    dnd_character_t my_character = {
     ability(),
         ability(),
             ability(),
                 ability(),
                     ability(),
                         ability(),0
                            
    };
    my_character.hitpoints = 10 + modifier(my_character.constitution);
    return my_character;
}