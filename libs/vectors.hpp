#pragma once

namespace Vector{
    class Vec3{
    private:
        double x;
        double y;
        double z;

    public:
        Vec3():
            x(0), y(0), z(0) {}

        Vec3(double, double, double);

        double operator[](int) const;
        double& operator[](int);

        Vec3 operator+(const Vec3&);
        Vec3 operator-(const Vec3&);
        Vec3 operator*(const double);
        void operator+=(Vec3&);
        void operator-=(Vec3&);
        void operator*=(double);

        double length_squared();
        Vec3 unit_vector();
    };

    using Point3 = Vec3;
    using Color3 = Vec3;

    class Ray{
    private:
        Point3 origin;
        Vec3 direction;
        double t;

    public:
        Ray(const Vec3&);
        Ray(const Point3&, const Vec3&);

        Point3 point_on_ray(double);
        Point3 get_origin() const;
        Vec3 get_direction() const;
    };
}