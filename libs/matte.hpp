#pragma once

#include "material.hpp"
#include "vectors.hpp"

class Matte: public Material{
private:
    Color3 color;
public:
    Matte(const Color3& _color):
              color(_color) {}
    
    bool scatter(const Ray&, Ray&, const Intersection&, Color3&) const override;
};