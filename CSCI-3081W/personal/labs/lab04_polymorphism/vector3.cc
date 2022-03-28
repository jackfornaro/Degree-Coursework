#include "vector3.h"

#include <iostream>
using namespace std;

Vector3::Vector3() {
	x = 0;
	y = 0;
	z = 0;
}

Vector3::Vector3(float xVal, float yVal, float zVal) {
	this->x = xVal;
	this->y = yVal;
	this->z = zVal;
}

Vector3 Vector3::operator+(Vector3 vec) {
	return Vector3(x + vec.x, y + vec.y, z + vec.z);
}

Vector3 Vector3::operator-(Vector3 vec) {
  return Vector3(x - vec.x, y - vec.y, z - vec.z);
}

Vector3 Vector3::operator*(float scal) {
	return Vector3(x * scal, y * scal, z * scal);
}

Vector3 Vector3::operator/(float scal) {
	return Vector3(x / scal, y / scal, z / scal);
}

void Vector3::Print() {
	cout << "[" << x << ", " << y << ", " << z << "]" << std::endl;
}
