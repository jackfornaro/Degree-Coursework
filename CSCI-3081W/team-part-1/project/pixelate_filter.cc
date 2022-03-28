/**
 * @file pixelate_filter.cc
 *
 */

/*******************************************************************************
* Includes
******************************************************************************/
#include "pixelate_filter.h"
#include <iostream>
using namespace std;
PixelateFilter::PixelateFilter() {}


/*******************************************************************************
 * Member Functions
 ******************************************************************************/

void PixelateFilter::Apply(std::vector<Image*> &original, std::vector<Image*> &filtered) {
 
  int width, height,a=0;
  float L=0;
  int one=1;

  for (int k = 0; k < original.size(); k++){
      *filtered[k] = *original[k];
      width = original[k]->GetWidth();
      height = original[k]->GetHeight();

      Color rgba;

    for(int i=0; i<= width-16; i+=16){     //  (4*) 4 * 160 = 640  639
      for(int j=0; j<= height-12; j+=12){   // (4*) 3 * 160 = 480   479
          // int count=0;
              rgba = original[0] -> GetPixel(i,j);
          for(int x=i;x<i+16;x++){
            for(int y=j;y<j+12;y++){
              filtered[0]->SetPixel(x, y, rgba);
              //get pixel color here
              // count++;  
            }
          }
          
        }
                          
    }
  }
}
  
 