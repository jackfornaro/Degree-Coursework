#ifndef DRONE_H_
#define DRONE_H_

#include "entity.h"
#include "vector3.h"

// Represents a drone in a physical system.
// Drones move using euler integration based on a specified
// velocity and direction.
class Drone : public MovableEntity {
public:
    // Drones are created with a name
    Drone(const std::string& name);
    // Destructor
    //~Drone();
    // Gets the drone name
    const std::string& GetName() { return name; }
    // Gets the drone position
    Vector3 GetPosition() { return position; }
    // Updates the drone's position
    void Update(double dt);
    // Sets the drone's velocity
    void SetVelocity(float x, float y, float z);
    // Rotates a drone
    void Rotate(double angle);

    // Removing the copy constructor and assignment operator
    // so that drones cannot be coppied.
    Drone(const Drone& drone) = delete;
    Drone& operator=(const Drone& drone) = delete;

private:
    std::string name;
    Vector3 position;
    Vector3 velocity;
};

#endif
