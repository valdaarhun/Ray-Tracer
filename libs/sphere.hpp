#pragma once

#include "hittable.hpp"
#include "vectors.hpp"

using namespace Vector;

class Sphere: public Hittable{
private:
    Point3 center;
    double radius;

public:
    Sphere(const Point3&, double);

    bool hit(const Ray& r, double t_min, bool t_max, Intersection& point) const override;
};