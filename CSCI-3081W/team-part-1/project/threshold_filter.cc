#include "threshold_filter.h"


ThresholdFilter::ThresholdFilter(float threshold) : threshold(threshold*255) {}

void ThresholdFilter::Apply(std::vector<Image*> &original, std::vector<Image*> &filtered) {
  float L;
  int width, height;
  for (int k = 0; k < original.size(); k++) {
    *filtered[k] = *original[k];
    width = original[k]->GetWidth();
    height = original[k]->GetHeight();
    for (int x = 0; x < width; x++) {
      for (int y = 0; y < height; y++) {
        //luminance
        L = original[k]->GetPixel(x, y).GetLuminance();
        if (L < threshold) {
          //black
          Color rgb(0, 0, 0, (*original[k]).GetPixel(x, y).GetAlpha());
          filtered[k]->SetPixel(x, y, rgb);
        } else {
          //white
          Color rgb(255, 255, 255, (*original[k]).GetPixel(x, y).GetAlpha());
          filtered[k]->SetPixel(x, y, rgb);
        }
      }
    }
  }
}
