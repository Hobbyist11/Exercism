#include "rational_numbers.h"
rational_t add(rational_t r1, rational_t r2){
    rational_t result = {0,0};
    
    result.numerator = (r1.numerator * r2.denominator) + (r1.denominator * r2.numerator);
    result.denominator = (r1.denominator*r2.denominator);
    
    int gcd = gcd_recursive(abs(result.numerator), abs(result.denominator));
    
    result.numerator = result.numerator/gcd;
    result.denominator = result.denominator/gcd;
    return result;
}

rational_t subtract (rational_t r1, rational_t r2){
    rational_t result = {0,0};
   result.numerator = r1.numerator * r2.denominator - r1.denominator * r2.numerator;
    result.denominator = r1.denominator*r2.denominator;
    
    int gcd = gcd_recursive(abs(result.numerator), abs(result.denominator));
    
    result.numerator = result.numerator/gcd;
    result.denominator = result.denominator/gcd;
    return result;
}

rational_t multiply(rational_t r1, rational_t r2){
    rational_t result = {0,0};
    result.numerator = r1.numerator * r2.numerator;
result.denominator = r1.denominator * r2.denominator;
    
    int gcd = gcd_recursive(result.numerator,result.denominator);
    
    result.numerator = result.numerator/abs(gcd);
    result.denominator = result.denominator/abs(gcd);
    if(result.numerator < 0 && result.denominator < 0){
        result.numerator = abs(result.numerator);
        result.denominator = abs(result.denominator);
    }
    return result;
}

 rational_t divide(rational_t r1, rational_t r2){
   rational_t result = {0,0};
     if(r1.denominator != 0){
        result.numerator = r1.numerator * r2.denominator;
            result.denominator = r1.denominator * r2.numerator;
    
    int gcd = gcd_recursive(result.numerator,result.denominator);
    
    result.numerator = result.numerator/abs(gcd);
    result.denominator = result.denominator/abs(gcd);
    if( result.denominator < 0){
        result.numerator = -result.numerator;
        result.denominator = abs(result.denominator);
    }
     }
   
    return result;
}

 rational_t absolute(rational_t r){
     rational_t result = {0,0};
     int gcd = gcd_recursive(abs(r.numerator), abs(r.denominator));
     result.numerator = abs(r.numerator/gcd);
     result.denominator = abs(r.denominator/gcd);
     return result;
 }

 rational_t exp_rational(rational_t r, int16_t n){
      rational_t result = {0,0};
     if(n > 0){
         result.numerator = pow(r.numerator,n);
         result.denominator = pow(r.denominator, n);
     } else{
         result.numerator = pow(r.denominator,abs(n));
         result.denominator = pow(r.numerator,abs(n));
     }
     int gcd = gcd_recursive(abs(r.numerator), abs(r.denominator));
     result.numerator = result.numerator/gcd;
     result.denominator = result.denominator/gcd;
      if( result.denominator < 0){
        result.numerator = -result.numerator;
        result.denominator = abs(result.denominator);
    }
     return result;
}

float exp_real(int16_t x, rational_t r){
    float result = 0.0;
    result = pow(pow(x,r.numerator),1.0/r.denominator);
    
    return result;
}

rational_t reduce(rational_t r){
    rational_t result = {0,0};
    int gcd = gcd_recursive(r.numerator,r.denominator);
    result.numerator = r.numerator/gcd;
    result.denominator = r.denominator/gcd;
    if( result.denominator < 0){
        result.numerator = -result.numerator;
        result.denominator = abs(result.denominator);
    }
    return result;
}

// Recursive function to return gcd of a and b
int gcd_recursive(int a, int b) {
    if (b == 0) {
        return a;
    }
    return gcd_recursive(b, a % b);
}
