#pragma once

#include "vectors.hpp"

using namespace Vector;

inline double dot(const Vec3& a, const Vec3& b){
    double res = a[0] * b[0] +
                 a[1] * b[1] +
                 a[2] * b[2];
    return res;
}

inline Vec3 cross(const Vec3& a, const Vec3& b){
    double x = a[1] * b[2] - b[1] * a[2];
    double y = a[2] * b[0] - b[2] * a[0];
    double z = a[0] * b[1] - b[0] * a[1];
    Vec3 res(x, y, z);
    return res;
}

inline void operator+=(Vec3& vector1, const Vec3& vector2){
    vector1[0] += vector2[0];
    vector1[1] += vector2[1];
    vector1[2] += vector2[2];
}

inline Vec3 random_unit_vector(){
    while(true){
        Vec3 vec = Vec3::random_vector(-1.0, 1.0);
        if (vec.length_squared() >= 1) continue;
        return vec;
    }
}