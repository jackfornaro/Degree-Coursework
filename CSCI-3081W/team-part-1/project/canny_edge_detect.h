#ifndef CANNY_EDGE_DETECT_H_
#define CANNY_EDGE_DETECT_H_
/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <iostream>
#include "filter.h"

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @brief The class for the generation of Canny Edge Detect filter.
 *
 *  Calls to \ref Apply function to output a new canny edge detect filter to
 *  vector<image*> filtered.
 */

class CannyEdgeDetectFilter : public Filter {
public:
  CannyEdgeDetectFilter();
  ~CannyEdgeDetectFilter(){}
 /**
  * @brief Apply the canny edge detect filter, takes in the <Image *> original vector and output to <Image *> filtered.
  *
  */
 void Apply(std::vector<Image*> &original, std::vector<Image*> &filtered);
};

#endif


