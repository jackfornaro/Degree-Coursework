#ifndef ThresholdFilter_H_
#define ThresholdFilter_H_
#include <iostream>
#include "filter.h"

// Represents a Tree in a physical system
class ThresholdFilter : public Filter {
  float threshold;
  public:
    ThresholdFilter(float threshold);
    ~ThresholdFilter(){}
    void Apply(std::vector<Image*> &original, std::vector<Image*> &filtered);
};


#endif
