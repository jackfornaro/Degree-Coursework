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
          Color rgb(0, 0, 0, (*original[k]).GetPixel(x, y).alpha);
          filtered[k]->SetPixel(x, y, rgb);
        } else {
          //white
          Color rgb(255, 255, 255, (*original[k]).GetPixel(x, y).alpha);
          filtered[k]->SetPixel(x, y, rgb);
        }
      }
    }
  }
}
// ****************OLD CODE**********************
// void ThresholdFilter::Apply(std::vector<Image*> &original, std::vector<Image*> &filtered) {
//   *filtered[0] = *original[0];
//   unsigned char* current;
//   unsigned char* cpy_pixel = new unsigned char[4];
//   float L;
//   for (int x = 0; x < original[0]->GetWidth(); x++) {
//     for (int y = 0; y < original[0]->GetHeight(); y++) {
//       current = original[0]->GetPixel(x, y);
//       //luminance
//       L = 0.2126 * (1.0 * current[0] / 255.0) + 0.7152 * (1.0 * current[1] / 255.0) + 0.0722 * (1.0 * current[2] / 255.0);
//       //std::cout<<"L : "<< L <<"threshold: "<< threshold <<std::endl;
//       if (L < threshold) {
//         //black
//         cpy_pixel[0] = 0;
//         cpy_pixel[1] = 0;
//         cpy_pixel[2] = 0;
//         cpy_pixel[3] = current[3];
//       } else {
//         //white
//         cpy_pixel[0] = 255;
//         cpy_pixel[1] = 255;
//         cpy_pixel[2] = 255;
//         cpy_pixel[3] = current[3];
//       }
//       filtered[0]->SetPixel(x, y, cpy_pixel);
//     }
//   }
//   delete[] cpy_pixel;
// }
