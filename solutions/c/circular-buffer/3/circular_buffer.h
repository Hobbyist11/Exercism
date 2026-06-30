#ifndef CIRCULAR_BUFFER_H
#define CIRCULAR_BUFFER_H
#include<stdint.h>
#include<stdlib.h>
#include<errno.h>
typedef int buffer_value_t;
typedef struct{
    int capacity;
    int elem_count;
    int write_idx;
    int read_idx;
    buffer_value_t *values;
} circular_buffer_t;

circular_buffer_t* new_circular_buffer(int capacity);
int16_t write(circular_buffer_t *buffer, int value);

int16_t read(circular_buffer_t *buffer, buffer_value_t* read_value);

int16_t overwrite(circular_buffer_t *buffer, int value);

void delete_buffer(circular_buffer_t* buffer);

void clear_buffer(circular_buffer_t* buffer);

#endif
