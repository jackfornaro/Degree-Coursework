#ifndef GREYSCALE_FILTER_H_
#define GREYSCALE_FILTER_H_

#include <vector>
#include "filter.h"
#include "image.h"

class GreyScaleFilter : public Filter {
public:
  ~GreyScaleFilter() {};
  void Apply(std::vector<Image*>& original, std::vector<Image*>& filtered);
};

#endif
