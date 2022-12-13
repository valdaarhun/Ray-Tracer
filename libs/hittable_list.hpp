#pragma once

#include <memory>
#include <vector>

#include "hittable.hpp"

using std::shared_ptr;
using std::vector;

class Hittable_List : public Hittable{
private:
    vector< shared_ptr< Hittable > > objects;

public:
    inline void clear(){
        objects.clear();
    }

    inline void add(shared_ptr< Hittable > object){
        objects.emplace_back(object);
    }

    bool hit(const Ray&, double, double, Intersection&) const;
};