/**
 * @file double_threshold
 *
 */

 /*******************************************************************************
  * Includes
******************************************************************************/
#ifndef DOUBLETHRESHOLD_H_
#define DOUBLETHRESHOLD_H_
#include "filter.h"
/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @brief The class for the generation of double threshold filter
 *
 * Calls to \ref Apply function to output a new double threshold filter to vector<image*> filtered.
 */
class DoubleThreshold : public Filter{
private:
    float high;
    float low;

public:
/**
 * @brief constrcutor that take two threshold values.
 *
 */
DoubleThreshold(float high,float low);
~DoubleThreshold();
/**
 * @brief Apply the double threshold filter, takes in the <Image *> original vector and output to <Image *> filtered.
 *
 */
void Apply(std::vector<Image*> &original, std::vector<Image*> &filtered);

};
#endif