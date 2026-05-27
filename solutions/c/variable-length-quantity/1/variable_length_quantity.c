#include "variable_length_quantity.h"

int encode(const uint32_t *integers, size_t integers_len, uint8_t *output)
{
    int output_length = 0;
    int total_output = 0;
    // write to `output`, return final output's length
    // `output` buffer should be enough to hold the full result
    size_t size = 0;
    uint8_t temp[5];
    for (size_t i = 0; i < integers_len; i++)
    {
        uint32_t value = integers[i];
        
        do {
            temp[size] = (value & 0x7F); // Get the last 7 bits
            value >>= 7;               // Shift right by 7 bits
            if (size > 0)
            {
                temp[size] |= 0x80; // Set the continuation bit
            }
            size++;
            output_length++;
        } while (value > 0);
        for (size_t j = 0; j < size; j++)
        {
            //Should not be in reverse
            output[total_output] = temp[size-j -1]; // Write in reverse order
            total_output++;
        }
        
    size = 0;
    }

    return output_length;
}

int decode(const uint8_t *bytes, size_t buffer_len, uint32_t *output)
{
   // write to `output`, return final output's length
   // return -1 if error
   // `output` buffer should be enough to hold the full result

    int size = 0;
    *output = 0;

    for (size_t i = 0; i < buffer_len; i++)
    {
         if ((bytes[i] & (1<<7))!= 0 && buffer_len <= 1){
            return -1;
        }
        *output = (*output << 7) | (bytes[i] & 0x7F);
    
         if (!(bytes[i] & 0x80)){
            size++;
            output++;
            if(i > 0){
               *output=0; 
            }
            continue;
        }
  
    }
    return size;
}
