#pragma once

#include "vectors.hpp"

inline double dot(const Vector::Vec3& a, const Vector::Vec3& b){
    double res = a[0] * b[0] +
                 a[1] * b[1] +
                 a[2] * b[2];
    return res;
}