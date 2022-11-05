#include "vectors.hpp"

using namespace Vector;

Ray::Ray(const Vec3& direction){
    this -> direction = direction;
}

Ray::Ray(const Vec3& origin, const Vec3& direction){
    this -> origin = origin;
    this -> direction = direction;
}

Vec3 Ray::point_on_ray(double t){
    return origin + direction * t;
}