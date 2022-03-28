#include <vector>

#include "filter.h"
#include "image.h"
#include "greyscale_filter.h"
#include "color.h"

void GreyScaleFilter::Apply(std::vector<Image*>& orig, std::vector<Image*>& filt) {
  *filt[0] = *orig[0];
  for(int i = 0; i < orig[0]->GetWidth(); i++) {
    for(int j = 0; j < orig[0]->GetHeight(); j++) {
      unsigned char* currPix = orig[0]->GetPixel(i, j);
      Color col;
      col.red = 1.0 * (currPix[0])/255.0;
      col.green = 1.0 * (currPix[1])/255.0;
      col.blue = 1.0 * (currPix[2])/255.0;

      float luminance = .2126*col.red + .7152*col.green + .0722*col.blue;

      col.red = luminance;
      col.green = luminance;
      col.blue = luminance;

      col.red = col.red*255;
      col.green = col.green*255;
      col.blue = col.blue*255;
      col.alpha = currPix[3];

      // currPixel[0] = //.2126*red + .7152*green + .0722*blue
      // currPixel[1] = //.2126*red + .7152*green + .0722*blue
      // currPixel[2] = //.2126*red + .7152*green + .0722*blue
      // currPixel[3] = //.2126*red + .7152*green + .0722*blue
      filt[0]->SetPixel(i, j, col);
    }
  }
}
