#include "nth_prime.h"
#include "math.h"
#include "stdlib.h"
#include "stdio.h"
#include "stdbool.h"
uint32_t nth(uint32_t n){
   
 if(n == 0)return 0;
    uint32_t index = 1;
    // int size = 0;
    uint32_t *primes = (uint32_t*)calloc(n,sizeof(uint32_t));
    if(primes == NULL){
        printf("Memory not allocated");
    }
    primes[0] = 2;
    uint32_t cur = 1;

    while(index<n){
        cur = cur + 2;
        uint32_t sqrt_cur = sqrt(cur);
        bool is_prime = true;
        
        for(uint32_t i = 0; i < index; i++){
            if(primes[i]>sqrt_cur){
                break;
            }
            if(cur % primes[i] == 0){
                is_prime = false;
                break;
            }
        }
        
            if(is_prime){
                primes[index] = cur;
                 index++;
            }
               
       // cur+=2;
    }

    return primes[n-1];
   
  
    
}