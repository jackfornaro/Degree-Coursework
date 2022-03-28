#ifndef THRESHOLD_FILTER_H_
#define THRESHOLD_FILTER_H_

#include <vector>
#include "filter.h"
#include "image.h"

class ThresholdFilter : public Filter {
private:
  float threshold;
public:
  ~ThresholdFilter() {};
  ThresholdFilter(float threshold);
  void Apply(std::vector<Image*>& original, std::vector<Image*>& filtered);
};

#endif
