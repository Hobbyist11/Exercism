#include "yacht.h"
int score(dice_t dice, category_t category){
    int final_score = 0;
    switch(category){
        case ONES:
            for(int i = 0; i < 5; i++){
                if(dice.faces[i] != 1){
                    continue;
                }
                final_score += dice.faces[i];
            }
            break;
        case TWOS:
            for(int i = 0; i < 5; i++){
                if(dice.faces[i] != 2){
                    continue;
                }
                final_score += dice.faces[i];
            }
            break;
        case THREES:
            for(int i = 0; i < 5; i++){
                if(dice.faces[i] != 3){
                    continue;
                }
                final_score += dice.faces[i];
            }
            break;
        case FOURS:
            for(int i = 0; i < 5; i++){
                if(dice.faces[i] != 4){
                    continue;
                }
                final_score += dice.faces[i];
            }
            break;
        case FIVES:
            for(int i = 0; i < 5; i++){
                if(dice.faces[i] != 5){
                    continue;
                }
                final_score += dice.faces[i];
            }
            break;
        case SIXES:
            for(int i = 0; i < 5; i++){
                if(dice.faces[i] != 6){
                    continue;
                }
                final_score += dice.faces[i];
            }
            break;
        case FULL_HOUSE: {
            int first_digit = 0;
            int second_digit = 0;
            int first_count = 0; // Three of this
            int second_count = 0; // or two of this
            for(int i = 0; i < 5; i++){
                // Find first digit
                if (first_digit == 0){
                    first_digit = dice.faces[i];
                    first_count++;
                    continue;
                }
                // Find second digit
                if(second_digit==0 && dice.faces[i] != first_digit && first_digit != 0){
                    second_digit = dice.faces[i];
                    second_count++;
                    continue;
                }
                if(dice.faces[i] == first_digit){
                    first_count++;
                } else if(dice.faces[i] == second_digit){
                    second_count++;
                }

                // Test if first_count == 2 && second_count == 3 || 
                if( (first_count == 2 && second_count == 3) || (first_count == 3 && second_count == 2)){
                     final_score = (first_digit*first_count) + (second_digit*second_count);
                } else{
                     final_score = 0;
                }
            }
        }
            
            break;

        case FOUR_OF_A_KIND:{
            int kind = 0;
            int kind_count = 0;
            for(int i = 0; i < 5; i++){
                if(kind == 0){
                    kind = dice.faces[i];
                    kind_count++;
                    continue;
                }
                if(dice.faces[i] == kind){
                    kind_count++;
                }
            }
            if (kind_count >= 4) {
                return kind * 4;
            } else{
                return 0;
            }
        }
            break;

        case LITTLE_STRAIGHT:{
            int digits[5] = {1,2,3,4,5};
            int digit_count[5] = {0,0,0,0,0};
            for(int i = 0; i < 5; i++){
                for(int j = 0; j < 5; j++){
                        if(dice.faces[i] == digits[j]){
                            digit_count[j]++;
                        } else{
                            continue;
                        }  
                }
            }
            // If digits_count is all one then little straight
            for(int i = 0; i < 5; i++){
                if(digit_count[i] != 1){
                    return 0;
                } else{
                    final_score = 30;
                }
            }
        }
            break;
            
        case BIG_STRAIGHT:{
            int digits[5] = {2,3,4,5,6};
            int digit_count[5] = {0,0,0,0,0};
            for(int i = 0; i < 5; i++){
                for(int j = 0; j < 5; j++){
                        if(dice.faces[i] == digits[j]){
                            digit_count[j]++;
                        } else{
                            continue;
                        }  
                }
            }
            // If digits_count is all one then little straight
            for(int i = 0; i < 5; i++){
                if(digit_count[i] != 1){
                    return 0;
                } else{
                    final_score = 30;
                }
            }
        }
            break;
        case CHOICE:
             for(int i = 0; i < 5; i++){
                final_score += dice.faces[i];
            }
            break;
        case YACHT:
            for(int i = 0; i < 5; i++){
                final_score += 10;
                if(final_score % dice.faces[i] != 0){
                    return 0;
                }
            }
    }
    return final_score;
}