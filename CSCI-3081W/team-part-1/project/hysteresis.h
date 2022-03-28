/**
 * @file Hysteresis.h
 */

#ifndef Hysteresis_H_
#define Hysteresis_H_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <iostream>
#include "filter.h"

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @brief The main class for the hysteresis filter.
 *
 *  Calls to \ref Generate function to get the Hysteresis filter
 */
class Hysteresis : public Filter {
public:
  Hysteresis();
/**
 * @brief Filter destructor
 *
 */
  ~Hysteresis(){}
/**
 * @brief Applies the filter from the input images to the output images
 *
 */
  void Apply(std::vector<Image*> &original, std::vector<Image*> &filtered);
};


#endif
