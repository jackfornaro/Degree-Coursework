#ifndef FILTER_H_
#define FILTER_H_
#include <string>
#include <vector>
#include "image.h"

// Entity is the base class for any simulation object
class Filter {
public:
    virtual ~Filter() {}
    virtual void Apply(std::vector<Image*> &original, std::vector<Image*> &filtered) = 0;
    // Destructor
};

#endif
