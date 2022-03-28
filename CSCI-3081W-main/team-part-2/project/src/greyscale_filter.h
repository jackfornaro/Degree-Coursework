#ifndef GREYSCALE_FILTER_H_
#define GREYSCALE_FILTER_H_

#include "filter.h"

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @brief This class is inherited from Filter class
 */
class GreyScaleFilter : public Filter{
public:
    /**
     * @brief This is a default constructor to generate a greyscale filter
     * @return This default constructor returns an object of greyscale filter
     */
    GreyScaleFilter();

    /**
     * @brief A method of handling input images with greyscale filter to generate output images and saving the output images in the vector
     * @param ins the first argument
     * @param outs the second argument
     */
    void Apply(const std::vector<Image*>& ins, const std::vector<Image*>& outs);
};

#endif