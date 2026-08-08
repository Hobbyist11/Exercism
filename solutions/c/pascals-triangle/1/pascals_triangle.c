#include "pascals_triangle.h"
#include <stdlib.h>

void free_triangle(uint8_t **triangle, size_t rows){
    //  // 4. Deallocate memory (Must free rows first, then the main pointer)
    // for (int i = 0; i < rows; i++) {
    //     free(matrix[i]);
    // }
    // free(matrix);
    for(size_t i = 0; i < rows; i++){
        for(size_t j = 0; j < rows; j++){
            triangle[i][j] = 0;
        }
    }
    free(triangle);
}
uint8_t **create_triangle(size_t rows){
   uint8_t **triangle = malloc(sizeof(uint8_t*)*rows);

    // Allocate for individual rows
    for(size_t i = 0; i < rows; i++){
       triangle[i] = malloc(rows * sizeof(uint8_t));
    }

    for(size_t i = 0; i < rows; i++){
        for(size_t j = 0; j < rows; j++){
            if(j == 0 ){
                triangle[i][j] = 1;
            } else if(i > 0 && j != 0){
                triangle[i][j] = triangle[i-1][j] + triangle[i-1][j-1];
            } else{

            triangle[i][j] = 0;
            }
        }
    }
return triangle;
}
