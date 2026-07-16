#ifndef SADDLE_POINTS_H
#define SADDLE_POINTS_H
#include <stddef.h>
#include <stdint.h>

typedef struct {
    int row;
    int column;
} saddle_point_t;

typedef struct {
    int count;
    saddle_point_t *points;
} saddle_points_t;

saddle_points_t *saddle_points(int row, int column, uint8_t matrix[row][column]);

void  free_saddle_points(saddle_points_t* actual);
#endif
