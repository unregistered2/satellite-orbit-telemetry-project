#include <iostream>
#include <vector>
#include "vec3.h"
#include "satellite.h"
// #include "Orbit.hpp"     // you'll create this later

int main() {
    
    Satellite satellite;

    const double dt = 1.0; // Time step in seconds
    const int steps = 10; // Number of simulation steps

    for (int i = 0; i < steps; ++i) {

        Vec3 pos = satellite.position();
        Vec3 vel = satellite.velocity();

        std::cout << "Time: " << i * dt << " s"
                  << "| Position: (" << pos.x << ", " << pos.y << ", " << pos.z << "), "
                  << "| Velocity: (" << vel.x << ", " << vel.y << ", " << vel.z << "), "
                  << "| Speed: " << satellite.speed() << " m/s, "
                  << "| Altitude: " << satellite.altitude() << " m"
                  << "\n";

        satellite.update(dt);
    }

    return 0;
}