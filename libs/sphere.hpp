#pragma once

#include <memory>

#include "hittable.hpp"
#include "vectors.hpp"

using namespace Vector;

class Sphere: public Hittable{
private:
    Point3 center;
    double radius;
    std::shared_ptr< Material > material;

public:
    Sphere(const Point3&, double, std::shared_ptr< Material >);

    bool hit(const Ray& r, double t_min, double t_max, Intersection& point) const override;
};