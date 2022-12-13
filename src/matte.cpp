#include "matte.hpp"
#include "vectors.hpp"

bool Matte::scatter(const Ray& in, Ray& out, const Intersection& point, Color3& color) const {
    Vec3 scatter_direction = point.normal + random_unit_vector();
    if (scatter_direction.is_near_zero()){
        scatter_direction = point.normal;
    }

    out = Ray(point.point, scatter_direction);
    color = this -> color;
    return true;
}