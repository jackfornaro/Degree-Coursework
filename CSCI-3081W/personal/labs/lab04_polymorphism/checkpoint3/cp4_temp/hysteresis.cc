#include "hysteresis.h"

Hysteresis::Hysteresis() {}

void Hysteresis::Apply(std::vector<Image*> &original, std::vector<Image*> &filtered) {
  float L;
  for(int k = 0; k < original.size(); k++) {
    *filtered[k] = *original[k];
    for(int x = 0; x < original[k]->GetWidth(); x++) {
      for(int y = 0; y < original[k]->GetHeight(); y++) {
        L = original[k]->GetPixel(x, y).GetLuminance();
        Color col;
        if(L < 255) {
          if(original[k]->GetPixel(x + 1, y - 1).GetLuminance() == 255 || original[k]->GetPixel(x + 1, y).GetLuminance() == 255 || original[k]->GetPixel(x + 1, y + 1).GetLuminance() == 255
              || original[k]->GetPixel(x, y - 1).GetLuminance() == 255 || original[k]->GetPixel(x, y + 1).GetLuminance() == 255
              || original[k]->GetPixel(x - 1, y - 1).GetLuminance() == 255 || original[k]->GetPixel(x - 1, y).GetLuminance() == 255 ||original[k]->GetPixel(x - 1, y + 1).GetLuminance() == 255) {
                col.red = 255;
                col.green = 255;
                col.blue = 255;
                col.alpha = original[k]->GetPixel(x, y).alpha;
                filtered[k]->SetPixel(x, y, col);
              }
          else {
            col.red = 0;
            col.green = 0;
            col.blue = 0;
            col.alpha = original[k]->GetPixel(x, y).alpha;
            filtered[k]->SetPixel(x, y, col);
          }
        }
      }
    }
  }
}
