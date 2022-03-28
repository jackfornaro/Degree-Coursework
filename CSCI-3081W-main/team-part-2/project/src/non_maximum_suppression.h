#ifndef NON_MAXIMUM_SUPPRESSION_H_
#define NON_MAXIMUM_SUPPRESSION_H_

#include "filter.h"

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @brief This class is inherited from Filter class
 */
class NonMaximumSuppressionFilter : public Filter{
public:
    /**
     * @brief This is a default constructor to generate a Non-Maximum Suppression filter
     * @return This default constructor returns an object of Non-Maximum Suppression filter
     */
    NonMaximumSuppressionFilter();

    /**
     * @brief A method of handling input images with Non-Maximum Suppression filter to generate output images and saving the output images in the vector
     * @param ins the first argument
     * @param outs the second argument
     */
    void Apply(const std::vector<Image*>& ins, const std::vector<Image*>& outs);
};



#endif