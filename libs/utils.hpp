#pragma once

#include <limits>
#include <random>

const double inf = std::numeric_limits< double >::infinity();
const double pi = 3.1415926535897932385;
const auto epsilon = 1e-16;

inline double degree_to_radians(double degrees){
    return pi * degrees / 180;
}

inline double radians_to_degree(double radians){
    return 180 * radians / pi;
}

inline double random_double(){
    /*
    * uniform_real_distribution is a class
    * P(x|{a, b}) = 1 / (b - a), a <= x < b
    * a and b are arguments of the constructor
    */
    static std::uniform_real_distribution< double > distribution(0.0, 1.0);
    static std::mt19937 mersenne_twister;

    return distribution(mersenne_twister);
}

inline double random_double_range(double a, double b){
    /*
    * uniform_real_distribution is a class
    * P(x|a, b) = 1 / (b - a), a <= x < b
    * a and b are arguments of the constructor
    */
    static std::uniform_real_distribution< double > distribution(a, b);
    static std::mt19937 mersenne_twister;

    return distribution(mersenne_twister);
}