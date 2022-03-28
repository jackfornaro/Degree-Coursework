#ifndef DRONE_H_
#define DRONE_H_

#include <iostream>

using namespace std;

// A drone object that has a position and propellers
class Drone {
private:
    float x;
    float y;
    float z;
    double speed;
public:
    // Default Constructor
    Drone();
    Drone(float x, float y, float z, double speed);
    // Updates the drone position and other dynamic properties
    void Update(double dt);
    // Gets the drone position.  Index represents the 3D spatial component 
    // (e.g. index = 0 means the x value)
    double GetPosition(int index);
    // Gets the propeller speed.  The index represents the propeller number 0-4.
    // Speeds between 0-2 work well, where a speed of 2 is faster than 1.
    double GetPropellerSpeed(int index);
    // Sets the direction of the joystick.  For example x = 1, means move in the positive x direction and
    // x = -1 means move in the negative x direction. 
    void SetJoystick(double x, double y, double z, double rotate);
};

#endif
