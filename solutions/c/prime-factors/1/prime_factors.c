#include "prime_factors.h"

size_t find_factors(uint64_t n, uint64_t factors[static MAXFACTORS]){
    size_t i = 0;
    for(uint64_t divisor = 2; divisor <= n; divisor++){
        while(n%divisor == 0){
           n /= divisor;
            factors[i] = divisor;
            i++;
        }
            continue;
        
    }
    return i;
}