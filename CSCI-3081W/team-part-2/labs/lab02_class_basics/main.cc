/**
Includes Vector3 header class
some systems might need "../Vector3.h"
mine needs :  #include "lab2/Vector3.h"
*/
#include "vector3.h"
#include <iostream>

int main(int argc, char**argv) {
  // this is how to print in cpp
  std::cout << "CSCI3081W Lab 2" << std::endl;

  // Default constructor and constructor with parameters
  Vector3 vector1 = Vector3();
  Vector3 vector2 = Vector3(1,1,1);
  Vector3 vector3 = Vector3(3,4,5);

  // Print
  std::cout << "Vector 1 contains the following: " << std::endl;
  vector1.Print();
  std::cout << "Vector 2 contains the following: " << std::endl;
  vector2.Print();
  std::cout << "Vector 3 contains the following: " << std::endl;
  vector3.Print();

  // Addition
  Vector3 vector4 = vector2 + vector3;
  std::cout << "Vector 4 contains the following: " << std::endl;
  vector4.Print();

  // Subtraction
  Vector3 vector5 = vector3 - vector2;
  std::cout << "Vector 5 contains the following: " << std::endl;
  vector5.Print();

  // Multiplication
  Vector3 vector6 = vector3*3;
  std::cout << "Vector 6 contains the following: " << std::endl;
  vector6.Print();

  // Division
  Vector3 vector7 = vector3/2;
  std::cout << "Vector 7 contains the following: " << std::endl;
  vector7.Print();

  // Euler's Integration Example
  Vector3 position = Vector3();
  Vector3 velocity = Vector3(1.0, 1.0, 0.0);
  float dt = 0.1;
  std::cout << "Initial Position: ";
  position.Print();
  std::cout << "Velocity: ";
  velocity.Print();
  std::cout << "dt: "<< dt << std::endl;
  for (int i = 0; i < 10; i++) {
    position = position + velocity * dt;
    std::cout << "Position at i=" << i << ": ";
    position.Print();
  }
}
