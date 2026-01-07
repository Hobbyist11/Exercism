#include "sieve.h"
#include <math.h>
#include <stdbool.h>
#include <stdlib.h>
uint32_t sieve(uint32_t limit, uint32_t *primes, size_t max_primes){
    //let A be an array of Boolean values, indexed by integers 2 to n,
    bool* A = (bool*)malloc(limit * sizeof(bool));
   
    // initially all set to true.
    for (size_t i = 0; i <=limit; i++) {
        A[i] = true;
    }

    /*for i = 2, 3, 4, ..., not exceeding √n do
        if A[i] is true
            for j = i2, i2+i, i2+2i, i2+3i, ..., not exceeding n do
                set A[j] := false

    
    */
    for(uint32_t i = 2, index = 0; i <= limit;i++){
        if(A[i] == true){
            for(uint32_t j = i*2; j <= limit; j+=i){
                A[j] = false;
            }
            primes[index] = i;
            index++;
        }
    }

    uint32_t result = 0;
    //return all i such that A[i] is true.
    
    if (max_primes < 1000) {
    for (size_t i = 0; i < max_primes; i++) {
      if (A[i] == true) {
        result++;
      }
    }
  } else {
    // return all i such that A[i] is true.
    for (uint32_t i = 2; i <= limit; i++) {
      if (A[i] == true) {
        result++;
      }
    }
  }
    return result;
}