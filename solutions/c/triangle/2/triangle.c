#include "triangle.h"
bool is_equilateral(triangle_t sides) {
    // Treat the struct as an array of 3 doubles
    const double *v = (const double *)&sides;

    // Iterate for validation (e.g., Triangle Inequality or side length > 0)
    for (int i = 0; i < 3; i++) {
        if (v[i] <= 0) return false;
    }

    // Direct access for the logic
    return (sides.a == sides.b && sides.b == sides.c);
}
bool is_isosceles(triangle_t sides){
    if(sides.a + sides.b < sides.c || sides.a + sides.c < sides.b || sides.b + sides.c < sides.a){
        return false;
    }

    // Direct access for the logic
    return (sides.a == sides.b || sides.b == sides.c || sides.a == sides.c);
}
bool is_scalene(triangle_t sides){
     if(sides.a + sides.b < sides.c || sides.a + sides.c < sides.b || sides.b + sides.c < sides.a){
        return false;
    }

    // Direct access for the logic
    return (sides.a != sides.b && sides.b != sides.c && sides.a != sides.c);
}