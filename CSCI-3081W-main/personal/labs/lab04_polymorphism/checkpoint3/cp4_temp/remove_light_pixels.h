#ifndef RemoveLightPixels_H_
#define RemoveLightPixels_H_

#include "filter.h"

class RemoveLightPixels : public Filter {
public:
  RemoveLightPixels();
  ~RemoveLightPixels(){}
  void Apply(std::vector<Image*> &original, std::vector<Image*> &filtered);
};

#endif
