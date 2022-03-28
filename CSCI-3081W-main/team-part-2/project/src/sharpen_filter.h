#ifndef SHARPEN_FILTER_H_
#define SHARPEN_FILTER_H_

#include "filter.h"


/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @brief This class is inherited from Filter class
 */

class SharpenFilter : public Filter{
public:
	/**
     * @brief This is a default constructor to generate a sharpen filter
     * @return This default constructor returns an object of sharpen filter
     */
	SharpenFilter();

	/**
     * @brief A method of handling input images with sharpen filter to generate output images and saving the output images in the vector
     * @param ins the first argument
     * @param outs the second argument
     */
	void Apply(const std::vector<Image*>& ins, const std::vector<Image*>& outs);
};

#endif

