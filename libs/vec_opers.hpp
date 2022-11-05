#include "vectors.hpp"

inline double dot(Vector::Vec3& a, Vector::Vec3& b){
    double res = a[0] * b[0] +
                 a[1] * b[1] +
                 a[2] * b[2];
    return res;
}