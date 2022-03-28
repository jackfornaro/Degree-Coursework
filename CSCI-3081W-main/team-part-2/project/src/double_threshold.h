#ifndef DOUBLE_THRESHOLD_FILTER_H_
#define DOUBLE_THRESHOLD_FILTER_H_

#include "filter.h"

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @brief This class is inherited from Filter class
 */
class DoubleThresholdFilter : public Filter {
public:
	/**
     * @brief This is a default constructor to generate a double threshold filter
	 * @param lowRatio the first argument
	 * @param highRatio the second argument
     * @return This default constructor returns an object of double threshold filter
     */
	DoubleThresholdFilter(float lowRatio, float highRatio);

	 /**
     * @brief A method of handling input images with double threshold filter to generate output images and saving the output images in the vector
     * @param ins the first argument
     * @param outs the second argument
     */
	void Apply(const std::vector<Image*>& ins, const std::vector<Image*>& outs);
private:
	float lowRatio;
	float highRatio;
};

#endif
