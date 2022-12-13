#pragma once

#include "material.hpp"
#include "vectors.hpp"

class Dielectric: public Material{
private:
    double refractive_index;

    Vec3 refracted_direction(const Vec3&, const Vec3&, double) const;
    Vec3 reflected_direction(const Vec3&, const Vec3&) const;
    double reflectance(const double, const double) const;

public:
    Dielectric(const double _refractive_index):
              refractive_index(_refractive_index) {}
    
    bool scatter(const Ray&, Ray&, const Intersection&, Color3&) const override;
};