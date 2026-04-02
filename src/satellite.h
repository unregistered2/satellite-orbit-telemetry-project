#pragma once
#include "vec3.h"

class Satellite
{
    public:
        Satellite();
        void update(double dt);

        Vec3 position() const;
        Vec3 velocity() const;

        double altitude() const;
        double speed() const;

    private:
        double earthRadius_;
        double altitude_;
        double mu_; // standard gravitational parameter

        double radius_;
        double speed_;
        double omega_; // angular velocity

        double theta_; // current angle in radians

};