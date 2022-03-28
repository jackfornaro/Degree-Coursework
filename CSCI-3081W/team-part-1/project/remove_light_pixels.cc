/**
 * @file RemoveLightPixels.cc
 *
 */

 /*******************************************************************************
 * Includes
 ******************************************************************************/
#include "remove_light_pixels.h"

RemoveLightPixels::RemoveLightPixels() {}

/*******************************************************************************
 * Member Functions
 ******************************************************************************/
void RemoveLightPixels::Apply(std::vector<Image*> &original, std::vector<Image*> &filtered) {
  //loop through image array
  for(int k = 0; k < original.size(); k++) {
    *filtered[k] = *original[k];
    //loop through pixels
    for(int x = 0; x < original[k]->GetWidth(); x++) {
      for(int y = 0; y < original[k]->GetHeight(); y++) {
        Color col;
        //if a pixel is declared light, remove it
        if(original[k]->GetPixel(x, y).GetLuminance() > 200) {
          col.SetRed(0);
          col.SetGreen(0);
          col.SetBlue(0);
          col.SetAlpha(original[k]->GetPixel(x, y).GetAlpha());
          filtered[k]->SetPixel(x, y, col);
        }
      }
    }
  }
}
