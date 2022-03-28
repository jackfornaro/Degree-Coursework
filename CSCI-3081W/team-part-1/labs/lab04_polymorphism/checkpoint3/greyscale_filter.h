#ifndef GREYSCALE_H_
#define GREYSCALE_H_
#include <iostream>
#include "filter.h"

// Represents a Tree in a physical system
class GreyScaleFilter : public Filter {
  public:
    GreyScaleFilter();
    ~GreyScaleFilter(){}
    void Apply(std::vector<Image*> &original, std::vector<Image*> &filtered);
};

#endif
