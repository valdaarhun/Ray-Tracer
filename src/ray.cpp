#include "vectors.hpp"

using namespace Vector;

Ray::Ray(const Vec3& direction){
    this -> direction = direction;
}

Ray::Ray(const Point3& origin, const Vec3& direction){
    this -> origin = origin;
    this -> direction = direction;
}

Point3 Ray::point_on_ray(double t) const{
    return origin + direction * t;
}

Point3 Ray::get_origin() const {
    return origin;
}

Vec3 Ray::get_direction() const {
    return direction;
}
