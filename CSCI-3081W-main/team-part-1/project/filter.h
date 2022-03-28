#ifndef FILTER_H_
#define FILTER_H_
/*******************************************************************************
 * Includes
 ******************************************************************************/

#include <string>
#include <vector>
#include "image.h"
#include "kernel.h"

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @brief The main class for the generation of Filter.
 *
 *  Calls to \ref This is the base class that is used to generate any filter.
 */

class Filter {
public:
    virtual ~Filter() {}
    /**
    * @brief Apply the filter, takes in the <Image *> original vector and output to <Image *> filtered.
    *
    */
    virtual void Apply(std::vector<Image*> &original, std::vector<Image*> &filtered) = 0;
};

#endif
