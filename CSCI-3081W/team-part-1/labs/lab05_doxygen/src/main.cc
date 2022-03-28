/**
 * @file main.cc
 *
 * @copyright 2021 3081W, All rights reserved.
 */


/*******************************************************************************
  * Includes
******************************************************************************/

#include <iostream>
#include <vector>

#include "EntityFactory.h"


/*******************************************************************************
 * Non-Member Functions
 ******************************************************************************/
int main() 
{
  // create an entity factory to generate random entities and stuff it into the vector
  EntityFactory* entityFactory = new EntityFactory();
  std::vector<Entity*> entities = entityFactory->Generate(3); // you can play around with Generate()'s input if you want

  // delete b/c we have no need for it anymore
  delete entityFactory;

  // after generating, report their initial positions and velocities
  std::cout << "========== INITIAL ENTITY VALUES ==========" << std::endl << std::endl;
  for (auto &iter : entities)
  {
    iter->report();
  }

  // run the simulation by doing stuff in the loop
  std::cout << "=========== RUNNING SIMULATION ===========" << std::endl << std::endl;
  for (int x = 0; x < 5; x++) 
  {
    std::cout << ">>> ITERATION: " << x+1 << std::endl;
    // iterate through the entities to update it
    for(auto &iter : entities) 
    {
      iter->update(1.25);
      iter->report();
    }
  }

  // when the simulation's done, delete everything in entities
  for (auto &iter : entities)
  {
    delete iter;
  }

  std::cout << "================= DONE =================" << std::endl;

  return 0;
}
