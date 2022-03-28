#ifndef GAUSSIAN_BLUR_H_
#define GAUSSIAN_BLUR_H_
/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <iostream>
#include "filter.h"

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @brief The class for the generation of Gaussian blur filter.
 *
 *  Calls to \ref Apply function to output a new gaussian blur filter to vector<image*> filtered.
 */

class GaussianBlurFilter : public Filter {
  public:
    GaussianBlurFilter();
    ~GaussianBlurFilter(){}
    /**
     * @brief Apply the gaussian blur filter, takes in the <Image *> original vector and output to <Image *> filtered.
     *
     */
    void Apply(std::vector<Image*> &original, std::vector<Image*> &filtered);
};

#endif
