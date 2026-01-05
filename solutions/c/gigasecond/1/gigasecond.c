#include "gigasecond.h"

void gigasecond(time_t input, char *output, size_t size){
    // One giga second after 2011, 4, 25 is 2043 01 01 01:46:40
    
    // int kiloseconds = 1000;
    // int megaseconds = kiloseconds * 1000;
    const time_t gigaseconds = 1000000000;
    // char *temp;
 input += gigaseconds;
   struct tm* utc =  gmtime(&input);
   // char *output = asctime(utc);
   //  // printf("%s",output);
   //  for (size_t i = 0; i < size; i++) {
   //          printf("%c", output[i]);
   //      }
    strftime(output,size,"%F %T",utc);
}