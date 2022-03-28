#include "greyscale_filter.h"
using namespace std;

GreyScaleFilter::GreyScaleFilter() {

}

void GreyScaleFilter::Apply(std::vector<Image*> &original, std::vector<Image*> &filtered) {
  float L;
  int width, height;
  for (int k = 0; k < original.size(); k++) {
    *filtered[k] = *original[k];
    width = original[k]->GetWidth();
    height = original[k]->GetHeight();
    for (int x = 0; x < width; x++) {
      for (int y = 0; y < height; y++) {
        L = original[0]->GetPixel(x, y).GetLuminance();
        Color rgb(L, L, L, (*original[k]).GetPixel(x, y).alpha);
        filtered[0]->SetPixel(x, y, rgb);
      }
    }
  }
}
// ****************OLD CODE**********************
// void GreyScaleFilter::Apply(std::vector<Image*> &original, std::vector<Image*> &filtered) {
//   *filtered[0] = *original[0];
//   unsigned char* current;
//   unsigned char* cpy_pixel = new unsigned char[4];
//   unsigned char L;
//   for (int x = 0; x < original[0]->GetWidth(); x++) {
//     for (int y = 0; y < original[0]->GetHeight(); y++) {
//       current = original[0]->GetPixel(x, y);
//       L = (0.2126 * current[0] + 0.7152 * current[1] + 0.0722 * current[2]);
//       cpy_pixel[0] = L;
//       cpy_pixel[1] = L;
//       cpy_pixel[2] = L;
//       cpy_pixel[3] = current[3];
//       filtered[0]->SetPixel(x, y, cpy_pixel);
//     }
//   }
//   delete[] cpy_pixel;
// }
