#include <cmath>

#include "vectors.hpp"

using namespace Vector;

Vec3::Vec3(double x, double y, double z){
    this -> x = x;
    this -> y = y;
    this -> z = z;
}

//TODO: Error if out-of-bound access attempted
double Vec3::operator[](int idx) const{
    if (idx == 0) return x;
    if (idx == 1) return y;
    return z;
}

//TODO: Error if out-of-bound access attempted
double& Vec3::operator[](int idx){
    if (idx == 0) return x;
    if (idx == 1) return y;
    return z;
}

Vec3 Vec3::operator+(const Vec3& vector) const{
    Vec3 vec;
    vec.x = x + vector.x;
    vec.y = y + vector.y;
    vec.z = z + vector.z;
    return vec;
}

Vec3 Vec3::operator-(const Vec3& vector) const{
    Vec3 vec;
    vec.x = x - vector.x;
    vec.y = y - vector.y;
    vec.z = z - vector.z;
    return vec;
}

Vec3 Vec3::operator*(const double k) const{
    Vec3 vec;
    vec.x = x * k;
    vec.y = y * k;
    vec.z = z * k;
    return vec;
}

Vec3 Vec3::operator*(const Vec3& vector) const{
    Vec3 vec;
    vec.x = x * vector.x;
    vec.y = y * vector.y;
    vec.z = z * vector.z;
    return vec;
}

Vec3 Vec3::operator/(const double k) const{
    Vec3 vec;
    vec.x = x / k;
    vec.y = y / k;
    vec.z = z / k;
    return vec;
}

void Vec3::operator-=(Vec3& vector){
    this -> x -= vector.x;
    this -> y -= vector.y;
    this -> z -= vector.z;
}

void Vec3::operator*=(double k){
    this -> x *= k;
    this -> y *= k;
    this -> z *= k;
}

double Vec3::length_squared(){
    return x * x +
           y * y +
           z * z;
}

Vec3 Vec3::unit_vector(){
    Vec3 vec;
    double length = sqrt(length_squared());
    vec.x = x / length;
    vec.y = y / length;
    vec.z = z / length;
    return vec;
}

bool Vec3::is_near_zero(){
    return length_squared() < epsilon;
}