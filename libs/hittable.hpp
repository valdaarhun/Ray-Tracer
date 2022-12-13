#pragma once

#include <memory>

#include "vectors.hpp"
#include "vec_opers.hpp"

using namespace Vector;

class Material;

struct Intersection{
    double t;
    Point3 point;
    Vec3 normal;
    bool front_side;
    std::shared_ptr< Material > material;

    inline void set_front_side(const Ray& r, const Vec3& n){
        front_side = dot(r.get_direction(), n) < 0.0;
        normal = front_side ? n : Vec3(0, 0, 0) - n;
    }
};

class Hittable{
public:
    virtual bool hit(const Ray&, double, double, Intersection&) const = 0;
};