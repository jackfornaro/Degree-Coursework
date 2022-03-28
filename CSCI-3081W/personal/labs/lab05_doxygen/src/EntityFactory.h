/**
 * @file EntityFactory.h
 *
 * @copyright 2021 3081W, All rights reserved.
 */

#ifndef SRC_ENTITY_FACTORY_H
#define SRC_ENTITY_FACTORY_H


/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <string>

#include "Entity.h"

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @brief The main class for the generation of entities.
 *
 *  Calls to \ref Generate function to get a new instance of an entity.
 *  This is a static call, not requiring an instance to invoke the method.
 */
class EntityFactory 
{
  public:
 /**
  * @brief Generation of an entity with a randomized name and random location within bounds.
  *
  * @return Entities vector of size int where each Entity is some random name at some random location.
  */
  static std::vector<Entity*> Generate(int);

 private:
 /**
  * @brief Generation of randomized entity name from prefix, stems and suffixes.
  *
  * @return Randomized entity name.
  */
  static std::string NameGeneration();
};

#endif
