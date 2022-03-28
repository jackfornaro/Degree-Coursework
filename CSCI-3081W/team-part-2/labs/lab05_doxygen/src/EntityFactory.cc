#ifndef ENTITYFACTORY_C
#define ENTITYFACTORY_C

/**
 * @file passenger_factory.cc
 *
 * @copyright 2021 3081W, All rights reserved.
 */

/*******************************************************************************
* Includes
******************************************************************************/
#include <random>
#include <string>

#include "EntityFactory.h"

// Here I will create an array of prefixes to help generate names.
// I am banking on multiplication to ensure a large number of names
// by using 7 prefixes and 20 stems, and 16 suffixes I should be able to
// create about 7 * 20 * 16 = 2240 names out of 312 bytes of data.

static const char* NamePrefixArray[7] = {
"",  // who said we need to add a prefix?
"bel",  // lets say that means "the good"
"nar",  // "The not so good as Bel"
"xan",  //" The evil"
"bell",  // "the good"
"natr",  // "the neutral/natral"
"ev",  // Man am I original
};

static const char* NameSuffixArray[16] = {
"", "us", "ix", "ox", "ith",
"ath", "um", "ator", "or", "axia",
"imus", "ais", "itur", "orex", "o",
"y"
};

static const char* NameStemsArray[20] = {
"adur", "aes", "anim", "apoll", "imac",
"educ", "equis", "extr", "guius", "hann",
"equi", "amora", "hum", "iace", "ille",
"inept", "iuv", "obe", "ocul", "orbis"
};

/*******************************************************************************
 * Member Functions
 ******************************************************************************/
// Code for name generation adapted from:
// https://www.dreamincode.net/forums/topic/27024-data-modeling-for-games-in-c-part-ii/

std::vector<Entity*> EntityFactory::Generate(int amount = 1) 
{
  std::random_device randomDevice;
  std::mt19937 gen(randomDevice());
  std::uniform_real_distribution<> dist(-50.0, 50.0);
  
  std::vector<Entity*> tempVector;

  for (int x = 0; x < amount; x++)
  {
    tempVector.push_back(new Entity( {dist(gen), dist(gen), dist(gen)}, {dist(gen)/10, dist(gen)/10, dist(gen)/10}, NameGeneration() ));
  }

  return tempVector;
}

std::string EntityFactory::NameGeneration() 
{
  std::random_device dev;
  std::mt19937 e(dev());
  std::uniform_int_distribution<std::mt19937::result_type> dist(1, 100);

  // assume rand is seeded
  std::string name = std::string (NamePrefixArray[(dist(e) % 7)]) + std::string (NameStemsArray[(dist(e) % 20)])
  + std::string(NameSuffixArray[(dist(e) % 16)]);
  name[0] = toupper(name[0]);  // don't forget to capitalize
  return name;
}

#endif