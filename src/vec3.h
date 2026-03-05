# pragma once
#include <cmath>

struct Vec3
{
    double x{0.0};
    double y{0.0};
    double z{0.0};

    double norm_squared() const
    {
        return x * x + y * y + z * z;
    }

    double norm() const
    {
        return std::sqrt(norm_squared());
    }

    Vec3 operator+(const Vec3& other) const
    {
        return {x + other.x, y + other.y, z + other.z};
    }

    Vec3 operator-(const Vec3& other) const
    {
        return {x - other.x, y - other.y, z - other.z};
    }

    Vec3 operator*(double k) const
    {
        return {x * k, y * k, z * k};
    }

    friend Vec3 operator*(double k, const Vec3& v)
    {
        return v * k;
    }

    Vec3 & operator+=(const Vec3& other)
    {
        x += other.x;
        y += other.y;
        z += other.z;
        return *this;
    }

    Vec3 & operator-=(const Vec3& other)
    {
        x -= other.x;
        y -= other.y;
        z -= other.z;
        return *this;
    }

    Vec3 & operator*=(double k)
    {
        x *= k;
        y *= k;
        z *= k;
        return *this;
    }
};
