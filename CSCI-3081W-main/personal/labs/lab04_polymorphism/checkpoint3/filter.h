#ifndef FILTER_H_
#define FILTER_H_

#include <vector>
#include "image.h"

class Filter {
public:
  virtual ~Filter() {};
  virtual void Apply(std::vector<Image*>& original, std::vector<Image*>& filtered) = 0;
};

#endif
