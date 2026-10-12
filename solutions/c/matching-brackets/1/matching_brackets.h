#ifndef MATCHING_BRACKETS_H
#define MATCHING_BRACKETS_H

#include <stdbool.h>

bool is_paired(const char *input);

typedef struct{
    int top;
    int bottom;
    char array[20];
} Stack;

Stack* create_stack();
void push(Stack* s,char c);
void pop(Stack* s);
#endif
