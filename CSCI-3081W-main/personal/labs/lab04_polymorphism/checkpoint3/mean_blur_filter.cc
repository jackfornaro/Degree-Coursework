#include <vector>

#include "filter.h"
#include "mean_blur_filter.h"

void MeanBlurFilter::Apply(std::vector<Image*>& orig, std::vector<Image*>& filt) {
  *filt[0] = *orig[0];
  for(int i = 0; i < orig[0]->GetWidth(); i++) {
    for(int j = 0; j < orig[0]->GetHeight(); j++) {
      unsigned char* currPix = orig[0]->GetPixel(i, j);
      Color col;
      col.red = (1.0 / 9.0) * currPix[0];
      col.green = (1.0 / 9.0) * currPix[1];
      col.blue = (1.0 / 9.0) * currPix[2];
      col.alpha = currPix[3];
      for(int u = i - 1; u <= i + 1; u++) {
        for(int v = j - 1; v <= j + 1; v++) {
          unsigned char* currPix2 = orig[0]->GetPixel(u, v);
          if(u >= 0 && v >= 0 && u < orig[0]->GetWidth() && v < orig[0]->GetHeight()){
            col.red = col.red + (1.0 / 9.0) * currPix2[0];
            col.green = col.green + (1.0 / 9.0) * currPix2[1];
            col.blue = col.blue + (1.0 / 9.0) * currPix2[2];
          } else {
            col.red = col.red + (1.0 / 9.0) * 255;
            col.green = col.green + (1.0 / 9.0) * 255;
            col.blue = col.blue + (1.0 / 9.0) * 255;
          }
        }
      }
      filt[0]->SetPixel(i, j, col);
    }
  }
}
