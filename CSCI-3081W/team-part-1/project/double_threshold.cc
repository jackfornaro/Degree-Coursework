/**
 * @file double_threshold.cc
 *
 */

/*******************************************************************************
* Includes
******************************************************************************/
#include "double_threshold.h"
#include "threshold_filter.h"

/*******************************************************************************
 * Member Functions
 ******************************************************************************/


DoubleThreshold::DoubleThreshold(float high,float low){
    this->high = high;
    this->low = low;
}

DoubleThreshold::~DoubleThreshold(){
}

void DoubleThreshold::Apply(std::vector<Image*> &original, std::vector<Image*> &filtered){
    //copy the original and filtered
    Color strong(255,255,255,255);
    Color weak(25,25,25,255);
    Color zero(0,0,0,255);

    for (int k = 0; k < original.size(); k++){
        
         *filtered[k] = *original[k];
        int width, height;
        width = original[k]->GetWidth();
        height = original[k]->GetHeight();
        for (int x = 0; x < width; x++) {
            for (int y = 0; y < height; y++) {
                if(original[k]->GetPixel(x,y).GetRed() > high*255){
                    filtered[k]->SetPixel(x,y,strong); 
                }else if(low*255 < original[k]->GetPixel(x,y).GetRed() <= high*255){
                    filtered[k]->SetPixel(x,y,weak);
                }else if(original[k]->GetPixel(x,y).GetRed() < low*255){
                    filtered[k]->SetPixel(x,y,zero);
                }
            }
            
        }
        
    }

    

}