#ifndef MEAN_BLUR_FILTER_H_
#define MEAN_BLUR_FILTER_H_

#include <vector>
#include "image.h"
#include "filter.h"

class MeanBlurFilter : public Filter {
public:
  ~MeanBlurFilter() {};
  void Apply(std::vector<Image*>& original, std::vector<Image*>& filtered);
};

#endif
