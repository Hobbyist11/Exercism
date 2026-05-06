#include "sublist.h"
comparison_result_t check_lists(int *list_to_compare, int *base_list, size_t list_to_compare_element_count,size_t base_list_element_count){
// this serves as our counter 
    size_t counter = 0;
    if(list_to_compare ==NULL && base_list == NULL){
        return EQUAL;
    }
    
 // find the bigger of the two lists, then start i on the BIGGER list
    //sublist case
    if(base_list_element_count > list_to_compare_element_count){
        // Empty list case
        if(list_to_compare == NULL){
            return SUBLIST;
        }

   
        size_t i = 0;
         for(; i < base_list_element_count - list_to_compare_element_count + 1;i++){
            for(size_t j = 0; j < list_to_compare_element_count;j++){
                if(base_list[j+i] != list_to_compare[j]){
                    counter = 0;
                    continue;
                } else {
                    counter++;
                }
                if (counter == list_to_compare_element_count){return SUBLIST;}
            }
        }
        if (counter == list_to_compare_element_count){
            return SUBLIST;
        } else if (counter == base_list_element_count){
            return SUPERLIST;
        } else if(counter == base_list_element_count && counter == list_to_compare_element_count ){
            return EQUAL;
        } else{
            return UNEQUAL;
        }
    } else {
        // Empty list case
        if(base_list == NULL){
            return SUPERLIST;
        }

        size_t j = 0;
        for(size_t i = 0; i < base_list_element_count;i++){
            for(; j < list_to_compare_element_count;j++){
                if(base_list[j] != list_to_compare[i]){
                    continue;
                } else{
                    counter++;
                    j++;
                    break;
                }
            }
        }
        if (counter == list_to_compare_element_count && counter != list_to_compare_element_count){
            return SUBLIST;
        } else if (counter == base_list_element_count  && counter != list_to_compare_element_count){
            return SUPERLIST;
        } else if(counter == base_list_element_count && counter == list_to_compare_element_count ){
            return EQUAL;
        } else{ 
            return UNEQUAL;
        }
    
    }
}