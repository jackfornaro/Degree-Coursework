#ifndef ENTITY_H
#define ENTITY_H

#include <iostream>
#include <string>
#include <vector>
#include <chrono>

class Entity
{ 
    public:

      Entity();

      Entity(std::vector<double>position, std::vector<double>velocity, std::string name = "Unknown Entity");

      ~Entity();

      void update(double dt);

      void report();

      double getLifeTime() const;

      void setPosition(std::vector<double> position);

      void setVelocity(std::vector<double> velocity);

      std::string getName() const;

      int getID() const;

      static int getEntityCount();
    
    private:

      std::string name;
      std::vector<double> position;
      std::vector<double> velocity;

      std::chrono::time_point<std::chrono::system_clock> startTime;
      std::chrono::time_point<std::chrono::system_clock> endTime;

      int id;
      static int count;  // global count, used to set ID for new instances
  
};

#endif