/**
 * @file sobel_filter.h
 *
 */

 /*******************************************************************************
  * Includes
******************************************************************************/
#ifndef SOBEL_FILTER_H_
#define SOBEL_FILTER_H_
#include <cmath>
#include <vector>
#include <iostream>
#include "filter.h"

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @brief The class for the generation of sobel filter.
 *
 * Calls to \ref Apply function to output a new sobel filter to vector<image*> filtered.
 */
class SobelFilter : public Filter {
  public:
    SobelFilter() {};
    ~SobelFilter() {};
    /**
     * @brief Apply the sobel filter, takes in the <Image *> original vector and output to <Image *> filtered.
     *
     */
    void Apply(std::vector<Image*> &original, std::vector<Image*> &filtered);
};

#endif
