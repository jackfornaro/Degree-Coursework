#ifndef Hysteresis_H_
#define Hysteresis_H_

#include <iostream>
#include "filter.h"

class Hysteresis : public Filter {
public:
  Hysteresis();
  ~Hysteresis(){}
  void Apply(std::vector<Image*> &original, std::vector<Image*> &filtered);
};


#endif
