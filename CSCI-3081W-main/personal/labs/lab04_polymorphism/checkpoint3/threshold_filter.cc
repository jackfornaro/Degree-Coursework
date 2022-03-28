#include <vector>

#include "filter.h"
#include "threshold_filter.h"

ThresholdFilter::ThresholdFilter(float threshold) {
  this->threshold = threshold;
}

void ThresholdFilter::Apply(std::vector<Image*>& orig, std::vector<Image*>& filt) {
  *filt[0] = *orig[0];
  for(int i = 0; i < orig[0]->GetWidth(); i++) {
    for(int j = 0; j < orig[0]->GetHeight(); j++) {
      unsigned char* currPix = orig[0]->GetPixel(i, j);
      Color col;
      col.red = currPix[0];
      col.green = currPix[1];
      col.blue = currPix[2];

      col.red = 1.0 * (col.red)/255.0;
      col.green = 1.0 * (col.green)/255.0;
      col.blue = 1.0 * (col.blue)/255.0;

      float luminance = .2126*col.red + .7152*col.green + .0722*col.blue;

      if(luminance < threshold) {
        col.red = 0;
        col.green = 0;
        col.blue = 0;
      }
      else {
        col.red = 255;
        col.green = 255;
        col.blue = 255;
      }
      // col.red = col.red*255;
      // col.green = col.green*255;
      // col.blue = col.blue*255;
      col.alpha = currPix[3];
      filt[0]->SetPixel(i, j, col);
    }
  }
}
