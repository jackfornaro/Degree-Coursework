/**
 * @file non_max_suppression
 *
 */

 /*******************************************************************************
  * Includes
******************************************************************************/
#ifndef NONMAXSUP_H_
#define NONMAXSUP_H_
#include <cmath>
#include "filter.h"

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @brief The class for the generation of non max suppression.
 *
 * Calls to \ref Apply function to output a new non max suppression to vector<image*> filtered.
 */
class NonMaxSup : public Filter{
public:
    NonMaxSup();
    ~NonMaxSup();
    /**
     * @brief Apply the non max suppression filter, takes in the <Image *> original vector and output to <Image *> filtered.
     *
     */
    void Apply(std::vector<Image*> &original, std::vector<Image*> &filtered);

};

#endif