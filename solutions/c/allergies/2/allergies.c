#include "allergies.h"
bool is_allergic_to(allergen_t allergen,int number){
    return(number &(1<<allergen))!=0;
}

allergen_list_t get_allergens(int score){
    int count = 0;
    allergen_list_t result = {count,{false}};
    for(int i = 0; i < ALLERGEN_COUNT; i++){
        if(is_allergic_to(i,score)){
            result.count++;
            result.allergens[i] = true;
        }
    }
    return result;
}