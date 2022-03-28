#include <iostream>
#include "vector3.h"

Vector3::Vector3(){
	x = y = z =0;
}
Vector3::Vector3(double corX, double corY, double corZ)
	: x(corX), y(corY), z(corZ)
{
}

Vector3::Vector3(const Vector3 &v){
	x = v.x;
	y = v.y;
	z = v.z;
}

void Vector3::Print(){
	std::cout << "[" << x << ", " << y << ", " << z << "]" << std::endl;
}

Vector3 Vector3::operator+(Vector3 vec){
	return Vector3(x + vec.x, y + vec.y, z + vec.z);
}

Vector3 Vector3::operator-(Vector3 vec){
	return Vector3(x - vec.x, y - vec.y, z - vec.z);
}
Vector3 Vector3::operator*(double val){
	return Vector3(x * val, y * val, z * val);
}
Vector3 Vector3::operator/(double val){
	return Vector3(x / val, y / val, z / val);
}
