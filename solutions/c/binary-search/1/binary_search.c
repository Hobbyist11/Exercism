#include "binary_search.h"
#include <stdlib.h>

const int *binary_search(int value, const int *arr, size_t length){
    // Do I need to use malloc?
    //int *result = (int*)malloc(sizeof(int));
int high = length-1;
int low = 0;

    const int *result = NULL;
     // Diff between the high and  low while  low != high 
    
    // What is our end condition?
while(low <= high){
    int mid = low + (high-low)/2;
        if(arr[mid] == value){
            return &arr[mid];
            // result = &arr[mid];
        } else if (arr[mid] > value){
            high = mid-1;       
        } else if (mid < value){
        low = mid +1;
        } else if(value < arr[0] || value > arr[length-1]){
            return NULL;
            // result = NULL;
        } 
}
  return result;
}