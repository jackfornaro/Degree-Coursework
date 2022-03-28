#define _USE_MATH_DEFINES
#include "drone.h"
#include "vector3.h"
#include <cmath>

Drone::Drone(const std::string& name) : name(name) {
    // Drones have 3 components x,y,z
    position = {0.0, 0.0, 0.0};
    // position[0] = 0.0;
    // position[1] = 0.0;
    // position[2] = 0.0;
    // position = new double[3];
    velocity = {0.0, 0.0, 0.0};
    dim = 3;
    isMovable = true;
}

// Drone::~Drone() {
//     // Delete dynamically allocated variables
//     // for(int i = 0; i < 3; i++) {
//     //   delete position[i];
//     // }
//     delete[] position;
// }

void Drone::SetVelocity(float x, float y, float z) {
    // Copy the velocity data into the member variable array.
    velocity.x = x;
    velocity.y = y;
    velocity.z = z;
}

void Drone::Update(double dt) {
    // Updates the drone position based on velocity and change in time

    // for (int i = 0; i < 3; i++) {
    //     position[i] = position[i] + velocity[i]*dt;
    // }
    // position[0] = position[0] + velocity.x*dt;
    // position[1] = position[1] + velocity.y*dt;
    // position[2] = position[2] + velocity.z*dt;
    position.x = position.x + velocity.x*dt;
    position.y = position.y + velocity.y*dt;
    position.z = position.z + velocity.z*dt;
}

void Drone::Rotate(double angle) {
    // Rotates the drone by changing the velocity by a
    // specified angle.
    double x = velocity.x;
    double y = velocity.y;
    //velocity[0] = x*std::cos(angle) - y*std::sin(angle);
    //velocity[1] = x*std::sin(angle) + y*std::cos(angle);
    velocity.x = x*std::cos(angle) - y*std::sin(angle);
    velocity.y = x*std::sin(angle) + y*std::cos(angle);
}
