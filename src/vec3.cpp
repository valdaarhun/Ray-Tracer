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
    if (idx == 2) return z;
}

//TODO: Error if out-of-bound access attempted
double& Vec3::operator[](int idx){
    if (idx == 0) return x;
    if (idx == 1) return y;
    if (idx == 2) return z;
}

Vec3 Vec3::operator+(const Vec3& vector){
    Vec3 vec;
    vec.x = x + vector[0];
    vec.y = y + vector[1];
    vec.z = z + vector[2];
    return vec;
}

Vec3 Vec3::operator-(const Vec3& vector){
    Vec3 vec;
    vec.x = x - vector[0];
    vec.y = y - vector[1];
    vec.z = z - vector[2];
    return vec;
}

Vec3 Vec3::operator*(const double k){
    Vec3 vec;
    vec.x = x * k;
    vec.y = y * k;
    vec.z = z * k;
    return vec;
}

void Vec3::operator+=(Vec3& vector){
    this -> x += vector[0];
    this -> y += vector[1];
    this -> z += vector[2];
}

void Vec3::operator-=(Vec3& vector){
    this -> x -= vector[0];
    this -> y -= vector[1];
    this -> z -= vector[2];
}

void Vec3::operator*=(double k){
    this -> x *= k;
    this -> y *= k;
    this -> z *= k;
}