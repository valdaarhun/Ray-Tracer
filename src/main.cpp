#include <iostream>
#include <cmath>

#include "vectors.hpp"
#include "vec_opers.hpp"

using namespace std;
using namespace Vector;

/*
* (A + tB - C).(A + tB - C) = radius ^ 2
*/
double hit_sphere(const Point3& center, Ray& r, double rad){
    Point3 ray_origin = r.get_origin();
    Vec3 ray_direction = r.get_direction();
    Vec3 oc = ray_origin - center;

    double a = dot(ray_direction, ray_direction);
    double b = 2 * dot(ray_direction, oc);
    double c = dot(oc, oc) - rad * rad;
    double discriminant = b * b - 4 * a * c;
    if (discriminant >= 0){
        return (-b - sqrt(discriminant)) / 2 * a;
    }
    return -1;
}

Vec3 gen_color(Ray& r){
    double t = hit_sphere(Point3(0, 0, -1), r, 0.5);
    if (t >= 0){
        Vec3 normal = r.point_on_ray(t) - Point3(0, 0, -1);
        Vec3 n = normal.unit_vector();
        return Color3(normal[0] + 1, normal[1] + 1, normal[2] + 1) * 0.5;
    }
    Vec3 direction = r.get_direction().unit_vector();
    t = (direction[1] + 1.0) / 2;
    return Color3(1, 1, 1) * (1 - t) + Color3(0.5, 0.7, 1) * t;
}

void write_colour(ostream &out, Color3 color){
    out << static_cast< int >(color[0] * 255.99) << ' '
        << static_cast< int >(color[1] * 255.99) << ' '
        << static_cast< int >(color[2] * 255.99) << ' '
        << '\n';
}

int main(){
    int nx = 1000, ny = 500;
    cout << "P3\n" << nx << ' ' << ny << "\n255\n";

    Vec3 horizontal_vector(4, 0, 0);
    Vec3 vertical_vector(0, 2, 0);
    Point3 lower_left_corner(-2, -1, -1);
    Point3 origin(0, 0, 0);

    for(int j = ny - 1 ; j >= 0 ; j--){
        for(int i = 0 ; i < nx ; i++){
            double u = (double)j / ny, v = (double)i / nx;
            Ray ray(origin, lower_left_corner + vertical_vector * u + horizontal_vector * v);

            Color3 color = gen_color(ray);
            write_colour(cout, color);
        }
    }
}