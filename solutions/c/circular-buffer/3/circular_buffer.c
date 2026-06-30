#include "circular_buffer.h"
int16_t write(circular_buffer_t *buffer, int value){
    //If there's capacity write
    if(buffer->elem_count < buffer->capacity){
        buffer->values[buffer->write_idx] = value;
        buffer->elem_count++;
        buffer->write_idx = (buffer->write_idx + 1) % buffer->capacity;
        return 0;
    }
    errno = ENOBUFS;
    return 1;
}

int16_t read(circular_buffer_t *buffer, buffer_value_t* read_value){
    //If null or empty
    if(buffer == NULL || buffer->elem_count == 0){
        errno = ENODATA;
        return 1;
    }

   
    *read_value = buffer->values[buffer->read_idx];
    buffer->read_idx = (buffer->read_idx + 1 ) % buffer->capacity;
    buffer->elem_count--;
    return 0;
}

int16_t overwrite(circular_buffer_t *buffer, int value){
    // If not full, regular write
    if(buffer->elem_count < buffer->capacity){
        return write(buffer,value);
    } else{
        buffer->values[buffer->write_idx] = value;
        buffer->write_idx = (buffer->write_idx + 1) % buffer->capacity;
        buffer->read_idx = (buffer->read_idx+ 1)%buffer->capacity;
    }
    return 0;
}

circular_buffer_t* new_circular_buffer(int capacity){
    // allocate mem for buffer
    circular_buffer_t *new_buf = malloc(sizeof(circular_buffer_t));
    // Allocate memory for the values
    new_buf->values = malloc(sizeof(buffer_value_t) * capacity);
    for(int i = 0; i < capacity; i++){
        new_buf->values[i] = 0;
    }
    new_buf->read_idx = 0;
    new_buf->capacity = capacity;
    new_buf->write_idx = 0;
    new_buf->elem_count = 0;
    return new_buf;
}

void delete_buffer(circular_buffer_t* buffer){
    if(buffer != NULL){
        free(buffer);
    }
    buffer = NULL;
}

void clear_buffer(circular_buffer_t* buffer){
    for(int i = 0; i < buffer->capacity;i++){
        buffer->values[i] = 0;
    }
    buffer->read_idx = 0;
    buffer->write_idx = 0;
    buffer->elem_count = 0;
}