#include <iomanip>
#include <iostream>
#include <cmath>

#include "camera.hpp"
#include "dielectric.hpp"
#include "hittable.hpp"
#include "hittable_list.hpp"
#include "matte.hpp"
#include "metal.hpp"
#include "sphere.hpp"
#include "vectors.hpp"
#include "vec_opers.hpp"
#include "utils.hpp"

using namespace std;
using namespace Vector;

Vec3 gen_color(Ray& r, Hittable& world, int depth){
    if (depth <= 0){
        return Color3(0, 0, 0);
    }

    Intersection point;
    if (world.hit(r, 0.001, inf, point)){
        Ray scattered_ray;
        Color3 color;
        if (point.material -> scatter(r, scattered_ray, point, color)){
            return color * gen_color(scattered_ray, world, depth - 1);
        }
        return Color3(0, 0, 0);
    }
    Vec3 direction = r.get_direction().unit_vector();
    auto t = (direction[1] + 1.0) / 2;
    return Color3(1, 1, 1) * (1 - t) + Color3(0.5, 0.7, 1) * t;
}

void write_colour(ostream &out, Color3 color_orig){
    Color3 color;
    color[0] = sqrt(color_orig[0]);
    color[1] = sqrt(color_orig[1]);
    color[2] = sqrt(color_orig[2]);

    out << static_cast< int >(color[0] * 255.99) << ' '
        << static_cast< int >(color[1] * 255.99) << ' '
        << static_cast< int >(color[2] * 255.99) << ' '
        << '\n';
}

int main(){
    int nx = 800, ny = 400;
    cout << "P3\n" << nx << ' ' << ny << "\n255\n";

    Camera camera(Point3(-2, 2, 1), Point3(0, 0, -1), Vec3(0, 1, 0), 20, 2);

    auto material_center = make_shared< Matte >(Color3(0.1, 0.2, 0.5));
    auto material_left = make_shared< Dielectric >(1.5);
    auto material_right = make_shared< Metal >(Color3(0.8, 0.6, 0.2), 0.6);
    auto material_ground = make_shared< Matte >(Color3(0.8, 0.8, 0));

    Hittable_List world;
    world.add(make_shared< Sphere >(Point3(0, 0, -1), 0.5, material_center));
    world.add(make_shared< Sphere >(Point3(-1, 0, -1), 0.5, material_left));
    world.add(make_shared< Sphere >(Point3(-1, 0, -1), -0.45, material_left));
    world.add(make_shared< Sphere >(Point3(1, 0, -1), 0.5, material_right));
    world.add(make_shared< Sphere >(Point3(0, -100.5, -1), 100, material_ground));

    const int sample_size = 50;
    const int max_depth = 50;

    for(int j = ny - 1 ; j >= 0 ; j--){
        cerr << "\rScanlines left: " << setw(3) << j + 1;
        for(int i = 0 ; i < nx ; i++){
            Color3 color(0, 0, 0);
            for(int k = 0 ; k < sample_size ; k++){
                double u = (j + random_double()) / (ny - 1), v = (i + random_double()) / (nx - 1);
                Ray ray = camera.get_ray(u, v);
                color += gen_color(ray, world, max_depth);
            }
            color *= (double)1 / sample_size;
            write_colour(cout, color);
        }
    }
    cerr << "\nDone\n";
}