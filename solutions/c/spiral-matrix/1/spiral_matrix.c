#include "spiral_matrix.h"
#include <stdlib.h>
spiral_matrix_t* spiral_matrix_create(int number){
    if (number == 0) {
       spiral_matrix_t *result = malloc(sizeof(spiral_matrix_t));
        result->size = 0;
        result->matrix = NULL;
        return result;
    }
    
    int **matrix = malloc(number * sizeof(int*));
    
        for(int i = 0; i < number; i++){
            matrix[i] = malloc(number * sizeof(int));
        }
    spiral_matrix_t *result = malloc(sizeof(spiral_matrix_t));
    if (result != NULL){
        result->size = number;
        result->matrix = matrix;
    }

// int counter = 1;
// int j = 0
    // while(counter <= number * number){
    //     for(int i = 0; i < number; i++){
    //         while(j < number && i == 0){
    //             result->matrix[i][j] = counter;
    //             counter++;
    //              j++;
    //         }
    //     }
    //     counter++;
    // }
    int top = 0;
    int left = 0;
    
    int bottom = number - 1;
    int right = number - 1;
   

    int counter = 1;
    while(counter <= number*number){
        // Left to right top
        for(int i = left; i <= right; i++){
            matrix[top][i] = counter;
            counter++;
        }
        top++; // Shrink the top boundy
        
        // Right to bottom
        for(int i = top; i <= bottom; i++){
            matrix[i][right] = counter;
            counter++;
        }
        right--; // Shrinnk right boundery

        // Bottom right to left
        if(top <= bottom){
            for(int i = right; i >= left; i--){
                matrix[bottom][i] = counter;
                counter++;
            }
            bottom--; // shrink the bottom
        }

        //Left to top
        if (left <= right){
            for(int i = bottom; i >= top; i--){
                matrix[i][left] = counter;
                counter++;
            }
            left++;
        }   
    }
    
    return result;
}

void spiral_matrix_destroy(spiral_matrix_t* actual){
    if(actual->matrix != NULL){
        for(int i = 0; i < actual->size; i++){
            free(actual->matrix[i]);
        }
        free(actual->matrix);
    }
    free(actual);
    actual = NULL;
}