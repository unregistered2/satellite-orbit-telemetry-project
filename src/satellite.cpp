#include "satellite.h"
#include <cmath>

Satellite::Satellite()
    : earthRadius_(6371000.0), // Earth's radius in meters
      altitude_(400000.0), // Altitude of 400 km
      mu_(3.986004418e14), // Standard gravitational parameter for Earth in m^3/s^2
      radius_(earthRadius_ + altitude_),
      speed_(std::sqrt(mu_ / radius_)), // Circular orbit speed
      omega_(speed_ / radius_), // Angular velocity
      theta_(0.0) // Initial angle
{
}

void Satellite::update(double dt)
{
    theta_ += omega_ * dt; // Update angle based on angular velocity and time step
}

Vec3 Satellite::position() const
{
    double x = radius_ * std::cos(theta_);
    double y = radius_ * std::sin(theta_);
    double z = 0.0; // Assuming orbit in the xy-plane

    return Vec3{x, y, z};
}

Vec3 Satellite::velocity() const
{
    double vx = -radius_ * std::sin(theta_);
    double vy = radius_ * std::cos(theta_);
    double vz = 0.0; // Assuming orbit in the xy-plane

    return Vec3{vx, vy, vz};
}

double Satellite::altitude() const
{
    return altitude_;
}

double Satellite::speed() const
{
    return speed_;
}