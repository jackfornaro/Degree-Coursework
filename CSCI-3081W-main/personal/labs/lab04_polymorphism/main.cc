#define _USE_MATH_DEFINES
#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include "drone.h"
#include "robot.h"
#include "tree.h"
#include "vector3.h"

int main(int argc, char**argv) {

  // Initialize the number of iterations and simulation dt
  int iterations = 3;
  double dt = 0.1;
  if (argc > 1) {
    iterations = std::atoi(argv[1]);
    dt = std::atof(argv[2]);
  }

  // Create two drones (Drone-A and Drone-X) and set their
  // initial velocity and rotation.
  Drone mainDrone("Drone-A");
  Drone* droneX = new Drone("Drone-X");
  // Vector3 velocity = new double[3];
  // velocity[0] = 1;
  // velocity[1] = 0;
  // velocity[2] = 1;
  mainDrone.SetVelocity(1, 0, 1);
  mainDrone.Rotate(M_PI/4.0);
  droneX->SetVelocity(1, 0, 1);
  // delete[] velocity;

  // Create a vector that holds entities (simulation entities).
  // This includes anything that inherits from Entity.
  // Add some entities to the vector.
  std::vector<Entity*> entities;
  entities.push_back(&mainDrone);
  entities.push_back(new Tree("Oak", 50.0, 50.0));
  entities.push_back(new Robot("Johnny-Five", 1.0));
  entities.push_back(new Tree("Maple", 100.0, 100.0));
  entities.push_back(droneX);
  entities.push_back(new Robot("Dave", 4));

  // Iteratively call several simulation steps (iterations)
  for (int iteration = 0; iteration < iterations; iteration++) {
    // Output the time step
    std::cout << "Time = " << (iteration*dt) << ":" << std::endl;
    std::cout << "--------------" << std::endl;

    // Loop through the entities
    for (int i = 0; i < entities.size(); i++) {
      // Print out the current entity
      Entity& entity = *entities[i];
      std::cout << entity.GetName();
      Vector3 pos = entity.GetPosition();
      std::cout << ", " << pos.x << ", " << pos.y;
      if(entity.dim == 3) {
        std::cout << ", "<< pos.z; //<< std::endl;
      }
      if(entity.isMovable) {
        MovableEntity* movable = dynamic_cast<MovableEntity*>(entities[i]);
        movable->Update(dt);
      }
      std::cout << std::endl;
      //<< pos.z << std::endl;
      // Update all movable entities (entities that have an update function)
      // E.g. Trees do not update, but drones and robots will.
      // MovableEntity* movable = dynamic_cast<MovableEntity*>(entities[i]);
      // movable->Update(dt);
    }
    std::cout << std::endl;
  }

  // Delete Entities
  for (int i = 0; i < entities.size(); i++) {
      // if (entities[i] != &mainDrone) {
      //   delete entities[i];
      // }
      if(i != 0) {
        delete entities[i];
      }
  }

  std::cout << "Simulation Complete" << std::endl;

  return 0;
}
