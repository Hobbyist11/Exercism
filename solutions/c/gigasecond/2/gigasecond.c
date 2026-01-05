#include "gigasecond.h"
#include <stdio.h>
const time_t giga = 1000 * 1000000;
void gigasecond(time_t input, char *output, size_t size){
    // Add a gigasecond to the input then write
    input += giga;
    // result to output
    strftime(output,size,"%F %T",gmtime(&input));
}