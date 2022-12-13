#pragma once

#include "material.hpp"
#include "vectors.hpp"

class Metal: public Material{
private:
    Color3 color;
    double fuzz_ratio;

    Vec3 reflected_direction(const Vec3&, const Vec3&) const;

public:
    Metal(const Color3& _color, const double _fuzz_ratio):
              color(_color), fuzz_ratio(_fuzz_ratio < 1 ? _fuzz_ratio : 1) {}
    
    bool scatter(const Ray&, Ray&, const Intersection&, Color3&) const override;
};