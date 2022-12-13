#include "metal.hpp"
#include "vectors.hpp"

Vec3 Metal::reflected_direction(const Vec3& vector, const Vec3 &normal) const{
    return vector - normal * dot(vector, normal) * 2;
}

bool Metal::scatter(const Ray& in, Ray& out, const Intersection& point, Color3& color) const{
    Vec3 scatter_direction = reflected_direction(in.get_direction().unit_vector(), point.normal);
    out = Ray(point.point, scatter_direction + random_unit_vector() * fuzz_ratio);
    color = this -> color;
    return (dot(point.normal, scatter_direction) > 0.0);
}