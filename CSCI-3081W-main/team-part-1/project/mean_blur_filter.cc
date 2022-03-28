#include "mean_blur_filter.h"

MeanBlurFilter::MeanBlurFilter() {}

void MeanBlurFilter::Apply(std::vector<Image*> &original, std::vector<Image*> &filtered) {
  int width, height;
  for (int k = 0; k < original.size(); k++){
    *filtered[k] = *original[k];
    width = original[k]->GetWidth();
    height = original[k]->GetHeight();
    for (int x = 0; x < width; x++) {
      for (int y = 0; y < height; y++) {
        //average pixel in original[0]
        Color rgb;
        for (int i = x-6; i <= x+6; i++) {
          for (int j = y-6; j <= y+6; j++) {
            if ( i >= 0 && j >= 0 && i < width && j < height) {
              rgb = rgb + (*original[k]).GetPixel(i, j) * (1.0/360.0);
            } else {
              rgb = rgb + 255 * (1.0/360.0);
            }
          }
        }
        filtered[0]->SetPixel(x, y, rgb);
      }
    }
  }
}
