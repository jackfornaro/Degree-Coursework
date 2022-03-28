using namespace std;
/*******************************************************************************
* Includes
******************************************************************************/
#include "greyscale_filter.h"

GreyScaleFilter::GreyScaleFilter() {}

/*******************************************************************************
 * Member Functions
 ******************************************************************************/
void GreyScaleFilter::Apply(std::vector<Image*> &original, std::vector<Image*> &filtered) {
  //Luminance value
  float L;
  int width, height;
  for (int k = 0; k < original.size(); k++) {
    *filtered[k] = *original[k];
    width = original[k]->GetWidth();
    height = original[k]->GetHeight();
    //Convolution
    for (int x = 0; x < width; x++) {
      for (int y = 0; y < height; y++) {


        L = original[0]->GetPixel(x, y).GetLuminance();
        Color rgb(L, L, L, (*original[k]).GetPixel(x, y).GetAlpha());
        filtered[0]->SetPixel(x, y, rgb);
      }
    }
  }
}
