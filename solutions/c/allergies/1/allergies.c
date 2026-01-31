#include "allergies.h"

bool is_allergic_to(allergen_t allergen, int score){
    int allergen_value = 1 << allergen;
if((score&allergen_value) != 0){
    return true;
}else{
    return false;
}
}

allergen_list_t get_allergens(int score){
    // allergen_t allergen = 1;
    allergen_list_t result = {0};

    for(int i = 0; i < 8; i++){
        int allergen_value = 1 << i;
    if((score&allergen_value)!=0){
        result.count++;
        result.allergens[i]=true;
    } 
    }
   
    
    return result;
}