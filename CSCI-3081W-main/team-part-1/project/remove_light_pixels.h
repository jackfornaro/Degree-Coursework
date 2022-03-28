/**
 * @file RemoveLightPixels.h
 */

#ifndef RemoveLightPixels_H_
#define RemoveLightPixels_H_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "filter.h"

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @brief The main class for the remove_light_pixels filter.
 *
 *  Calls to \ref Generate function to get the remove_light_pixels filter
 */
class RemoveLightPixels : public Filter {
public:
  RemoveLightPixels();
/**
 * @brief Filter destructor
 *
 */
  ~RemoveLightPixels(){}
/**
 * @brief Applies the filter from the input images to the output images
 *
 */
  void Apply(std::vector<Image*> &original, std::vector<Image*> &filtered);
};

#endif
