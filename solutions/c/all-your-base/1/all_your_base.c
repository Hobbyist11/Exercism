#include "all_your_base.h"
#include <math.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

size_t rebase(int8_t *digits, int16_t input_base, int16_t output_base,
              size_t input_length)
{
    if(input_base < 0){
        return 0;
    }

  size_t count = 0;

    if(output_base >= 2){
        int16_t temp_digits[DIGITS_ARRAY_SIZE];
  int16_t number = 0;

  // This is the case where we convert from binary to decimal
  // I convert it to decimal first

  if (input_base != 10)
  {
    for (size_t i = 0, powoff = input_length - 1; i < input_length; i++)
    {
     if((digits[i]<0 || digits[i] > 1) && input_base == 2){
         return 0;
     }
      number += digits[i] * pow(input_base, powoff - i);
    }
  } else{
      for (size_t i = 0; i < input_length; i++){
          number = number * 10 + digits[i];
      } 
  }

  int16_t temp = abs(number);
    if(temp == 0 && input_length > 0 && input_base > 1){
        return 1;
    }
  // This is in reverse order
  while (temp > 0)
  {
    temp_digits[count] = temp % output_base;
    temp /= output_base;
    count++;
  }
        
  // for (int i = count - 1; i >= 0; i--)
  // {
  //   printf("temp:%d\n", temp_digits[i]);
  // }

  // Add proper digits to the array
  for (int i = count - 1, j = 0; i >= 0; i--, j++)
  {
    // printf("temp i:%d val:[%d]\n", i, temp_digits[i]);
    digits[j] = temp_digits[i];
  }
    } else {
        return 0;
    }
  


  return count;
}