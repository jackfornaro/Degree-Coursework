#include "drone.h"
#include <iostream>

using namespace std;

Drone::Drone() {
    x = 0;
    y = 0;
    z = 0;
    speed = 0.0;
}

Drone::Drone(float xVal, float yVal, float zVal, double pace) {
    this->x = xVal;
    this->y = yVal;
    this->z = zVal;
    this->speed = pace;
}

void Drone::Update(double dt) {

}

double Drone::GetPosition(int index) {
    return 0.0;
}

double Drone::GetPropellerSpeed(int index) {
    return 0.0;
}

void Drone::SetJoystick(double x, double y, double z, double rotate) {

}
