/**
 * @file Entity.h
 *
 * @copyright 2021 Jack Fornaro, All rights reserved
 */

#ifndef ENTITY_H
#define ENTITY_H

/*******************************************************************************
 * Includes
 ******************************************************************************/

#include <iostream>
#include <string>
#include <vector>
#include <chrono>

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @brief The main class for the generation of a entity.
 *
 */

class Entity
{
    public:
      /**
       * @brief Instantiation of an entity with no position or velocity or name.
       *
       */
      Entity();
      /**
       * @brief Instantiation of an entity with a position, velocity and name.
       *
       */
      Entity(std::vector<double>position, std::vector<double>velocity, std::string name = "Unknown Entity");
      /**
       * @brief Entity destructor
       *
       */
      ~Entity();

      /**
       * @brief Updating the entity's position.
       *
       * @return entity's updated position
       *
       */
      void update(double dt);
      /**
       * @brief Prints a general report on the entity
       *
       */
      void report();
      /**
       * @brief Gets the lifetime of the entity.
       *
       * @return entity's lifetime
       *
       */

      double getLifeTime() const;

      /**
       * @brief Sets the position of the entity.
       *
       */
      void setPosition(std::vector<double> position);
      /**
       * @brief Sets the velocity of the entity.
       *
       */
      void setVelocity(std::vector<double> velocity);

      /**
       * @brief Gets the name of the entity.
       *
       * @return entity's name
       *
       */
      std::string getName() const;

      /**
       * @brief Gets the id of the entity.
       *
       * @return entity's id
       *
       */
      int getID() const;

      /**
       * @brief Gets the count of the entity.
       *
       * @return entity's count
       *
       */
      static int getEntityCount();

/*******************************************************************************
* Member Variables
******************************************************************************/
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
