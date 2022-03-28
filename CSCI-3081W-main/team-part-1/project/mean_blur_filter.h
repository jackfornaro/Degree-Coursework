#ifndef MeanBlurFilter_H_
#define MeanBlurFilter_H_

#include "filter.h"

// Represents a Tree in a physical system
class MeanBlurFilter : public Filter {
  public:
    MeanBlurFilter();
    ~MeanBlurFilter(){}
    void Apply(std::vector<Image*> &original, std::vector<Image*> &filtered);
};


#endif
