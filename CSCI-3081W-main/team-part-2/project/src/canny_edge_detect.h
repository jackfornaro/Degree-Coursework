#ifndef CANNY_EDGE_DETECT_H_
#define CANNY_EDGE_DETECT_H_

#include "image.h"
#include "filter.h"
#include "greyscale_filter.h"
#include "gaussian_blur_filter.h"
#include "sobel_filter.h"
#include "non_maximum_suppression.h"
#include "double_threshold.h"
#include "hysteresis.h"
#include <iostream>
#include <map>
#include <memory>
#include <vector>
#include <string>

/**
 * @brief This is a method to detect image's edges via several filters 
 * @param ins the first argument
 * @param outs the second argument
 * @param forSobel the third argument
 */
void CannyEdgeDetect(const std::vector<Image*>& ins, const std::vector<Image*>& outs, const std::vector<Image*>& forSobel);


#endif