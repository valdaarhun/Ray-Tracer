#include "dielectric.hpp"
#include "vectors.hpp"
#include "utils.hpp"

Vec3 Dielectric::reflected_direction(const Vec3& vector, const Vec3 &normal) const{
    return vector - normal * dot(vector, normal) * 2;
}

Vec3 Dielectric::refracted_direction(const Vec3& incident_vector, const Vec3& normal, const double etaI_by_etaT) const{
    double cos_theta = fmin(-dot(incident_vector, normal), 1.0);
    Vec3 t_perpendicular = (incident_vector + normal * cos_theta) * etaI_by_etaT; // perpendicular to normal
    Vec3 t_parallel = normal * (-sqrt(fabs(1 - t_perpendicular.length_squared()))); // parallel to normal
    return t_perpendicular + t_parallel;
}

double Dielectric::reflectance(const double cos_theta, const double etaI_by_etaT) const{
    double t = (1 - etaI_by_etaT) / (1 + etaI_by_etaT);
    t *= t;
    return t + (1 - t) * pow(1 - cos_theta, 5);
}

// Schlick's approximation for reflectance
bool Dielectric::scatter(const Ray& in, Ray& out, const Intersection& point, Color3& color) const{
    color = Color3(1, 1, 1);
    double etaI_by_etaT = point.front_side ? 1.0 / refractive_index : refractive_index;
    double cos_theta = fmin(-dot(in.get_direction().unit_vector(), point.normal), 1.0); // fmin(x, 1.0) takes care of cases when x is marginally greater than 1
    double sin_theta = sqrt(1 - cos_theta * cos_theta);
    Vec3 scatter_direction;
    if (etaI_by_etaT * sin_theta > 1.0 || reflectance(cos_theta, etaI_by_etaT) > random_double()){
        // Total internal reflection
        scatter_direction = reflected_direction(in.get_direction().unit_vector(), point.normal);
    }
    else{
        scatter_direction = refracted_direction(in.get_direction().unit_vector(), point.normal, etaI_by_etaT);
    }
    out = Ray(point.point, scatter_direction);
    return true;
}