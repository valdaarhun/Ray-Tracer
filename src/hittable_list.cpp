#include <memory>
#include <vector>

#include "hittable_list.hpp"

using std::shared_ptr;
using std::vector;

bool Hittable_List::hit(const Ray& r, double t_min, double t_max, Intersection& point) const{
    Intersection temp;
    bool is_hit = false;
    double t = t_max;

    for (const auto& object: objects){
        if (object -> hit(r, t_min, t, temp)){
            is_hit = true;
            t = temp.t;
            point = temp;
        }
    }

    return is_hit;
}
