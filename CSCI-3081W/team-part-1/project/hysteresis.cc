/**
 * @file Hysteresis.cc
 *
 */

 /*******************************************************************************
 * Includes
 ******************************************************************************/
#include "hysteresis.h"

Hysteresis::Hysteresis() {}

/*******************************************************************************
 * Member Functions
 ******************************************************************************/
void Hysteresis::Apply(std::vector<Image*> &original, std::vector<Image*> &filtered) {
  float L; //luminance variable
  //loop through image array
  for(int k = 0; k < original.size(); k++) {
    *filtered[k] = *original[k];
    //loop through pixels
    for(int x = 0; x < original[k]->GetWidth(); x++) {
      for(int y = 0; y < original[k]->GetHeight(); y++) {
        L = original[k]->GetPixel(x, y).GetLuminance();
        Color col;
        //if the pixel is weak...
        if(L < 255) {
          //if a neighboring pixel is strong, make the current pixel strong
          if(original[k]->GetPixel(x + 1, y - 1).GetLuminance() == 255 || original[k]->GetPixel(x + 1, y).GetLuminance() == 255 || original[k]->GetPixel(x + 1, y + 1).GetLuminance() == 255
              || original[k]->GetPixel(x, y - 1).GetLuminance() == 255 || original[k]->GetPixel(x, y + 1).GetLuminance() == 255
              || original[k]->GetPixel(x - 1, y - 1).GetLuminance() == 255 || original[k]->GetPixel(x - 1, y).GetLuminance() == 255 ||original[k]->GetPixel(x - 1, y + 1).GetLuminance() == 255) {
                col.SetRed(255);
                col.SetGreen(255);
                col.SetBlue(255);
                col.SetAlpha(original[k]->GetPixel(x, y).GetAlpha());
                filtered[k]->SetPixel(x, y, col);
              }
          //otherwise, make pixel weak
          else {
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
}
