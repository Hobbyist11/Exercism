#include "space_age.h"
float age(planet_t planet, int64_t seconds){
    float age;
    float years = seconds / 60 / 60 / 24 / 365.25;
   
    switch (planet){
        case MERCURY:
            age = years/0.2408466;
            break;
        case VENUS:
            age = years / 0.61519726;
            break;
        case EARTH:
            age = years / 1.0;
            break;
        case MARS:
            age = years / 1.8808158;
            break;
        case JUPITER:
            age = years / 11.862615;
            break;
        case SATURN:
            age = years/29.447498;
            break;
        case URANUS:
            age = years / 84.016846;
            break;
        case NEPTUNE:
            age = years / 164.79132;
            break;
        default:
            age = -1;
            break;
    }
    return age;
}