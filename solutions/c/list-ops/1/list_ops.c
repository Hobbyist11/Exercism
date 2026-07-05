#include "list_ops.h"


// constructs a new list
list_t *new_list(size_t length, list_element_t elements[]){\
    // Allocate memory for a single list
    list_t *result = malloc(sizeof(list_t) + (length * sizeof(list_element_t)));
    // Allocate memory for the elements
    // result->elements[length];
    // Set the values for the elements
    for(size_t i = 0; i < length; i++){
        result->elements[i] = elements[i];
    }
    result->length = length;
    return result;
}

// append entries to a list and return the new list
list_t *append_list(list_t *list1, list_t *list2){
    list_t *result = new_list(list1->length+list2->length, list1->elements);
    
    size_t i = 0;
    if(list1->length == 0){
        for(size_t j=0; j < list2->length;j++){
        result->elements[i] = list2->elements[j];
            i++;
        }
        return result;
    }else if(list2->length == 0){
        for(size_t j=0; j < list1->length;j++){
        result->elements[i] = list1->elements[j];
            i++;
        }
        return result;
    }
        
    // Put elements from first list
     while(i < list1->length){
        result->elements[i] = list1->elements[i];
     i++;
        }
    
    // Put elements from second list
    for(size_t j=0; j < list2->length;j++){
        result->elements[i] = list2->elements[j];
        i++;
    }
    return result;
}

// filter list returning only values that satisfy the filter function
list_t *filter_list(list_t *list, bool (*filter)(list_element_t)){
    // list_t *result = new_list(5,list->elements);
    // If list is empty
    if(*filter == 0){
        list_t *result = new_list(list->length,list->elements);
    return result;
     } else{
        int i = 0;
        // Safe default value, can be optimized by creating  dynamic size
        list_element_t added_elems[list->length]; 
    for(size_t j = 0; j < list->length; j++){
        if(filter(list->elements[j]) == 1){
            added_elems[i] = list->elements[j];
            i++;
        }
    }
        list_t *result = new_list(i,added_elems);
             return result;
    }
    
}

// returns the length of the list
size_t length_list(list_t *list){
    size_t result = list->length;
    return result;
}

// return a list of elements whose values equal the list value transformed by
// the mapping function
list_t *map_list(list_t *list, list_element_t (*map)(list_element_t)){
    // Empty case
    if(list->length == 0){
        list_t *result = new_list(0,list->elements);
        return result;
    } else {
        list_t *result = new_list(list->length,list->elements);
        for(size_t i = 0; i < list->length; i++){
            result->elements[i] = map(list->elements[i]);
        }
        return result;
    }
}

// folds (reduces) the given list from the left with a function
list_element_t foldl_list(list_t *list, list_element_t initial, list_element_t (*foldl)(list_element_t, list_element_t)){
    list_element_t init = initial;
    if(list->length == 0){
       list_element_t init = initial;
        return init;
    }
    for(size_t i = 0; i < list->length; i++){
        init = foldl(init,list->elements[i]);
    }
  return init; 
        
}

// folds (reduces) the given list from the right with a function
list_element_t foldr_list(list_t *list, list_element_t initial, list_element_t (*foldr)(list_element_t,list_element_t)){
   list_element_t init = initial;
    if(list->length == 0){
       list_element_t init = initial;
        return init;
    }
    for(size_t i = list->length - 1; i < list->length; i--){
        init = foldr(list->elements[i],init);
    }
  return init; 
}

// reverse the elements of the list
list_t *reverse_list(list_t *list){
     list_t *result = new_list(list->length, list->elements);
    for(size_t i = list->length - 1, j = 0; j < list->length; i--,j++){
        result->elements[j] = list->elements[i];
    }
    return result;
}

// destroy the entire list
// list will be a dangling pointer after calling this method on it
void delete_list(list_t *list){
    free(list);
    list = NULL;
}
