#include "camera.hpp"
#include "vectors.hpp"
#include "vec_opers.hpp"
#include "utils.hpp"

using namespace Vector;

Camera::Camera(Point3 from, Point3 to, Vec3 up, double vfov, double aspect_ratio){
    double h = tan(degree_to_radians(vfov) / 2);
    double viewport_height = 2 * h;
    double viewport_width = aspect_ratio * viewport_height;
    
    double focal_length = 1.0;

    Vec3 w = (from - to).unit_vector();
    Vec3 u = cross(up, w).unit_vector();
    Vec3 v = cross(w, u).unit_vector();

    origin = from;
    horizontal = u * viewport_width;
    vertical = v * viewport_height;
    lower_left_corner = origin - horizontal / 2 - vertical / 2 - w;
}

Ray Camera::get_ray(double u, double v) const{
    return Ray(origin, lower_left_corner + vertical * u + horizontal * v - origin);
}
