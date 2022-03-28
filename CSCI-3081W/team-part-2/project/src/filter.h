#ifndef FILTER_H_
#define FILTER_H_

#include "image.h"
#include "color.h"
#include "kernel.h"
#include <cmath>
#include <vector>

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @brief This Filter class is an abstract class
 */
class Filter{
public:
    /**
	 * @brief This is an virtual method
     */
    virtual void Apply(const std::vector<Image*>& ins, const std::vector<Image*>& outs) = 0;
};


#endif // !FILTER_H_