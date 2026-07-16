#include "saddle_points.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

saddle_points_t *saddle_points(int row, int column, uint8_t matrix[row][column]){
// If empty
    if((row == 0 && column == 0) || matrix == NULL){
        saddle_points_t *result = malloc(sizeof(saddle_points_t));
        result->count = 0;
        return result;
    }
// Allocate space for the result
saddle_points_t *result = malloc(sizeof(saddle_points_t));

// Find max in row
    int max_row[row];
    int max_temp = 0;
    for(int i = 0; i < row; i++){
        for(int j = 0; j < column; j++){
            // How do we handle duplicates which don't end up being the max??
            if(matrix[i][j]>=max_temp){
                max_temp = matrix[i][j];
            }
        }
        max_row[i] = max_temp;
        max_temp = 0;
    }

// Find min in column
    int min_col[9];
    int min_temp = 10;
    for(int j = 0; j < column; j++){
        for(int i = 0; i < row; i++){
            // How do we handle duplicates which don't end up being the min??
            if(matrix[i][j]<=min_temp){
                min_temp = matrix[i][j];
            }
        }
        min_col[j] = min_temp;
        min_temp = 10;
    }

    // Allocate this later after we find the correct number of points
   int max_possible_points = row * column;
saddle_point_t* arr2d = malloc(max_possible_points* sizeof(saddle_point_t));
    arr2d->row = 0;
    arr2d->column = 0;
    
// If max in row && min in column, add to result 
for(int i = 0; i < row; i++){
        for(int j = 0; j < column; j++){
            if(matrix[i][j] == max_row[i] && matrix[i][j] == min_col[j]){
                arr2d[result->count] = (saddle_point_t){.row = i+1, .column = j+1};
                result->count++;
            }
        }
    }

    result->points = arr2d;
 
    return result;
}


void  free_saddle_points(saddle_points_t* actual){
    actual->points = NULL;
    actual->count = 0;
    free(actual);
    actual = NULL;
}