#include "remove_light_pixels.h"

RemoveLightPixels::RemoveLightPixels() {}

void RemoveLightPixels::Apply(std::vector<Image*> &original, std::vector<Image*> &filtered) {
  for(int k = 0; k < original.size(); k++) {
    *filtered[k] = *original[k];
    for(int x = 0; x < original[k]->GetWidth(); x++) {
      for(int y = 0; y < original[k]->GetHeight(); y++) {
        Color col;
        if(original[k]->GetPixel(x, y).GetLuminance() > 200) {
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
