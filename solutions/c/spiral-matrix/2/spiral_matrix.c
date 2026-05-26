#include "spiral_matrix.h"
#include <stdlib.h>

spiral_matrix_t* spiral_matrix_create(int n){
        if (n == 0) {
       spiral_matrix_t *result = malloc(sizeof(spiral_matrix_t));
        result->size = 0;
        result->matrix = NULL;
        return result;
    }
    
    // Create memory for the matrix
    int **matrix = malloc(n * sizeof(int*));
    
    for(int i = 0; i < n; i++){
        matrix[i] = malloc(n*sizeof(int));
    }
    
       // Create spiral matrix pointer
    spiral_matrix_t* spiral = malloc(sizeof(spiral_matrix_t));
    // // Add the size of the spiral
    if (spiral != NULL){
        spiral->size = n;
    spiral->matrix = matrix;
    }
    

    
    int top = 0;
    int left = 0;
    
     int bottom = n-1;
    int right = n-1;
   
    
    int counter = 1;
    while(counter <= n*n){
        // For left to right top row
        for(int i = left; i <= right; i++){
            matrix[top][i] = counter;
            counter++;
        }
        //decrease top row
        top++;

           // For top to bottom right side
        for(int i = top; i <= bottom; i++){
            matrix[i][right] = counter;
            counter++;
        }
        // Decrease right side
        right--;

           // For bottom right to left
        if(top <= bottom){
            for(int i = right; i >= left; i--){
               matrix[bottom][i] = counter;
            counter++;
        }
        // Decrease bottom
        bottom--; 
        }

        // For left bottom to top
        if(left <= right){
            for(int i = bottom; i >= top; i--){
              matrix[i][left] = counter;
            counter++;
        }
        // Decrease left
        left++;
        }
    }
    
    return spiral;
}

void spiral_matrix_destroy(spiral_matrix_t* matrix){
    if (matrix->matrix != NULL){
        for (int i = 0; i < matrix->size; i++){
            free(matrix->matrix[i]);
        }
        free(matrix->matrix);
    }
    free(matrix);
    matrix = NULL;
}