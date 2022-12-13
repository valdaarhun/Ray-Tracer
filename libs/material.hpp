#pragma once

#include "hittable.hpp"
#include "vectors.hpp"
#include "vec_opers.hpp"

using namespace Vector;

class Material{
public:
    virtual bool scatter(const Ray&, Ray&, const Intersection&, Color3&) const = 0;
};