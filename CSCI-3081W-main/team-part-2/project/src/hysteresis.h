#ifndef HYSTERESIS_H_
#define HYSTERESIS_H_

#include "filter.h"

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @brief This class is inherited from Filter class
 */

class HysteresisFilter : public Filter{
public:
    /**
     * @brief This is a default constructor to generate a hysteresis filter
     * @return This default constructor returns an object of hysteresis filter
     */
    HysteresisFilter();

    /**
     * @brief A method of handling input images with hysteresis filter to generate output images and saving the output images in the vector
     * @param ins the first argument
     * @param outs the second argument
     */
    void Apply(const std::vector<Image*>& ins, const std::vector<Image*>& outs);
};

#endif