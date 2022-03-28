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
// ****************OLD CODE**********************
// void MeanBlurFilter::Apply(std::vector<Image*> &original, std::vector<Image*> &filtered) {
//   *filtered[0] = *original[0];
//   float red;
//   float green;
//   float blue;
//   unsigned char* current;
//   unsigned char* cpy_pixel = new unsigned char[4];
//   int width = original[0]->GetWidth();
//   int height = original[0]->GetHeight();
//   for (int x = 0; x < width; x++) {
//     for (int y = 0; y < height; y++) {
//       //average pixel in original[0]
//       red = 0;
//       green = 0;
//       blue = 0;
//       for (int i = x-3; i <= x+3; i++) {
//         for (int j = y-3; j <= y+3; j++) {
//           if ( i >= 0 && j >= 0 && i < width && j < height) {
//             current = original[0]->GetPixel(i, j);
//             red += current[0];
//             green += current[1];
//             blue += current[2];
//           } else {
//             red += 255;
//             green += 255;
//             blue += 255;
//           }
//         }
//       }
//       cpy_pixel[0] = (1.0/60.0) * red;
//       cpy_pixel[1] = (1.0/60.0) * green;
//       cpy_pixel[2] = (1.0/60.0) * blue;
//       cpy_pixel[3] = current[3];
//
//
//       filtered[0]->SetPixel(x, y, cpy_pixel);
//     }
//   }
//   delete[] cpy_pixel;
// }
