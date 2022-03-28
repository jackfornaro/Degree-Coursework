/**
 * @file pixelate_filter
 *
 */

 /*******************************************************************************
  * Includes
******************************************************************************/

#ifndef PixelateFilter_H_
#define PixelateFilter_H_

#include "filter.h"


/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @brief The class for the generation of pixelate_filter filter
 *
 * Calls to \ref Apply function to output a new pixelate_filter filter to vector<image*> filtered.
 */


// Represents a Tree in a physical system
class PixelateFilter : public Filter {
  public:
    PixelateFilter();
    ~PixelateFilter(){}

/**
 * @brief Apply the pixelate_filter, takes in the <Image *> original vector and output to <Image *> filtered.
 *
 */

    void Apply(std::vector<Image*> &original, std::vector<Image*> &filtered);
};


#endif
