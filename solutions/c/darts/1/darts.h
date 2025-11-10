#ifndef DARTS_H
#define DARTS_H

typedef struct {
    float x;
    float y;
} coordinate_t;

typedef enum{
    OUTSIDE =0,
    OUTER = 1,
    MIDDLE = 5,
    INNER = 10,
} dart_board_t;

int score(coordinate_t position);
float power_of2(float num);
#endif
