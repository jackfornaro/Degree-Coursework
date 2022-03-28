#define _USE_MATH_DEFINES
#include "robot.h"
#include <cmath>

Robot::Robot(const std::string& name, float radius) : name(name), angle(0.0), radius(radius) {
    pos.x = radius*std::cos(angle);
    pos.y = radius*std::sin(angle);
    dim = 2;
    isMovable = true;
}

void Robot::Update(double dt) {
    angle += dt;
    pos.x = radius*std::cos(angle);
    pos.y = radius*std::sin(angle);
}
