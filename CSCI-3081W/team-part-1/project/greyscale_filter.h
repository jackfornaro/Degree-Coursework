#ifndef GREYSCALE_H_
#define GREYSCALE_H_
/**
 * @file greyscale.h
 *
 */

/*******************************************************************************
* Includes
******************************************************************************/
#include <iostream>
#include "filter.h"

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @brief The class for the generation of greyscale filter.
 *
 *  Calls to \ref Apply function to output a new greyscale filter to vector<image*> filtered.
 */

class GreyScaleFilter : public Filter {
  public:
    GreyScaleFilter();
    ~GreyScaleFilter(){}
    /**
     * @brief Apply the gaussian blur filter, takes in the <Image *> original vector and output to <Image *> filtered.
     *
     */
    void Apply(std::vector<Image*> &original, std::vector<Image*> &filtered);
};

#endif
