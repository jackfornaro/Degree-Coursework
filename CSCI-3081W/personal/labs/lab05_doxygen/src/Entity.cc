#include "Entity.h"

#include <iostream>
#include <string>


int Entity::count = 0;

Entity::Entity() : position({0,0,0}), velocity({0,0,0}), name("Unknown Entity")
{
  startTime = std::chrono::system_clock::now();
  id = count++;
}

Entity::Entity(std::vector<double> position, std::vector<double> velocity, std::string name) : position(position), velocity(velocity), name(name)
{
  startTime = std::chrono::system_clock::now();
  id = count++;
}

Entity::~Entity()
{
  position.clear();
  velocity.clear();
}

void Entity::update(double dt) 
{
  for (int x = 0; x < 3; x++)
  {
    position[x] = position[x] + (velocity[x] * dt);
  }
}

void Entity::report() 
{
  auto print = [&](std::vector<double> v) { return (std::to_string(v[0]) + " " + std::to_string(v[1]) + " " + std::to_string(v[2])); };

  std::cout << "Entity [" << this->id << "]: " << this->name << std::endl
            << "Position: " << print(position) << std::endl
            << "Velocity: " << print(velocity) << std::endl
            << "Age: " << this->getLifeTime() << " seconds" << std::endl << std::endl;
}

double Entity::getLifeTime() const // in seconds
{
  std::chrono::time_point<std::chrono::system_clock> callTime = std::chrono::system_clock::now();

  return std::chrono::duration_cast<std::chrono::milliseconds>(callTime - this->startTime).count() / 1000.0;
}

void Entity::setPosition(std::vector<double>position)
{
  this->position = position;
}

void Entity::setVelocity(std::vector<double>velocity)
{
  this->position = position;
}

std::string Entity::getName() const
{
  return this->name;
}

int Entity::getID() const
{
  return this->id;
}

int Entity::getEntityCount()
{
  return count;
}