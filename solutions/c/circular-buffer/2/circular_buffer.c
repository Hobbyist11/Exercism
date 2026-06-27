#include "circular_buffer.h"
#include <stdio.h>


int16_t read(circular_buffer_t *buffer, buffer_value_t *read_value) {
  if (buffer == NULL || read_value == NULL || buffer->count_elements == 0) {
    errno = ENODATA;
    return 1;
  }
  // If empty, return 61
  if (buffer->value[buffer->read_index] == 0) {
    // returns correct status
    errno = ENODATA;
    return 1;
  }
  *read_value = buffer->value[buffer->read_index];
  printf("read index:%d val:%d\n", buffer->read_index,buffer->value[buffer->read_index]);
  buffer->read_index = (buffer->read_index + 1) % buffer->capacity; 
  buffer->count_elements--;

  return 0;
}

int16_t write(circular_buffer_t *buffer, int value) {
  if (errno == 0 && buffer->count_elements < buffer->capacity) {
    buffer->value[buffer->write_index] = value;

        // Should only read item once
    buffer->write_index = (buffer->write_index + 1) % buffer->capacity; 
    buffer->count_elements++;

    return 0;
  } else {
    errno = ENOBUFS;
    return 1;
  }
}

int16_t overwrite(circular_buffer_t *buffer, buffer_value_t value) {
  // overwrite non-full is write
  if (errno == 0 && buffer->count_elements < buffer->capacity) {
    buffer->value[buffer->write_index] = value;
    buffer->write_index = (buffer->write_index + 1) % buffer->capacity;
    buffer->count_elements++;

    return 0;

  } else {

    buffer->value[buffer->write_index] = value;
    buffer->read_index = ((buffer->read_index + 1 ) % buffer->capacity);
    // buffer->value[buffer->write_index  % buffer->capacity] =  buffer->value[(buffer->write_index + 1) % buffer->capacity];

    buffer->write_index = (buffer->write_index + 1) % buffer->capacity;

    // buffer->value[buffer->write_index] = value;

    return 0;
  }
}

circular_buffer_t *new_circular_buffer(size_t capacity) {
  circular_buffer_t *circular_buffer =
  // allocatae only a single buffer
      malloc(sizeof(circular_buffer_t) );

      // Allocate for the values
circular_buffer->value = malloc(sizeof(buffer_value_t) * capacity);

 for (size_t i = 0; i < capacity; i++) {
    // circular_buffer->value[i] = 0;
    *(circular_buffer->value + i) = 0;
  }

  // Init state
  circular_buffer->capacity = capacity;
  circular_buffer->count_elements = 0;
 
  circular_buffer->read_index = 0;
  circular_buffer->write_index = 0;
  return circular_buffer;
}

void delete_buffer(circular_buffer_t *buffer) {
  if (buffer != NULL) {
    free(buffer);
  }
  buffer = NULL;
  errno = 0;
}

void clear_buffer(circular_buffer_t *buffer) {
  for (int i = 0; i < buffer->capacity; i++) {
    buffer->value[i] = 0;
  }
  buffer->read_index = 0;
  buffer->write_index = 0;
  buffer->count_elements = 0;
}


