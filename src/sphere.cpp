#include <cmath>
#include <memory>

#include "sphere.hpp"
#include "vectors.hpp"
#include "vec_opers.hpp"

Sphere::Sphere(const Point3& center, double radius, std::shared_ptr< Material > material){
    this -> center = center;
    this -> radius = radius;
    this -> material = material;
}

/*
* (A + tB - C).(A + tB - C) = radius ^ 2
*/
bool Sphere::hit(const Ray& r, double t_min, double t_max, Intersection& point) const{
    Point3 ray_origin = r.get_origin();
    Vec3 ray_direction = r.get_direction();
    Vec3 oc = ray_origin - center;

    double a = ray_direction.length_squared();
    double half_b = dot(ray_direction, oc);
    double c = oc.length_squared() - radius * radius;
    double half_discriminant = half_b * half_b - a * c;
    if (half_discriminant < 0){
        return false;
    }
    double t = (-half_b - sqrt(half_discriminant)) / a;
    if (t < t_min || t > t_max){
        t = (-half_b + sqrt(half_discriminant)) / a;
        if (t < t_min || t > t_max){
            return false;
        }
    }

    point.t = t;
    point.point = r.point_on_ray(t);
    Vec3 normal = (point.point - center) / radius;
    point.set_front_side(r, normal);
    point.material = material;

    return true;
}