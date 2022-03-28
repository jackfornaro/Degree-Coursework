/**
 * @file non_max_suppression.cc
 *
 */

/*******************************************************************************
* Includes
******************************************************************************/
#include "non_max_suppression.h"
NonMaxSup::NonMaxSup(){
}

NonMaxSup::~NonMaxSup(){
}

/*******************************************************************************
 * Member Functions
 ******************************************************************************/

void NonMaxSup::Apply(std::vector<Image*> &original, std::vector<Image*> &filtered) {
    int width, height;
    //if the original dose not contain the direction image, throw error
    if (original.size() % 2 != 0){
        throw(1);
    }

    for (int k = 0; k < original.size(); k+=2){
        *filtered[k] = *original[k];
        Image* direction = original[k+1];
        //Set width, height equal to original image
        width = original[k]->GetWidth();
        height = original[k]->GetHeight();
        Color black = Color(0,0,0,255);
        float angle;
        float q;
        float r;
        for (int x = 0; x < width; x++) {
            for (int y = 0; y < height; y++) {
                angle = direction->GetPixel(x,y).GetRed();
                if (angle < 0){
                    angle += 180;
                }
                if(0 <= angle || 157.5 <= angle <= 180){
                    q = original[k]->GetPixel(x, y+1).GetRed();
                    r = original[k]->GetPixel(x, y-1).GetRed();
                }
                else if(22.5 <= angle < 67.5){
                    q = original[k]->GetPixel(x+1, y-1).GetRed();
                    r = original[k]->GetPixel(x-1, y+1).GetRed();
                }
                else if(67.5 <= angle < 112.5){
                    q = original[k]->GetPixel(x+1, y).GetRed();
                    r = original[k]->GetPixel(x-1, y).GetRed();
                }
                else if(112.5 <= angle < 157.5){
                    q = original[k]->GetPixel(x-1, y-1).GetRed();
                    r = original[k]->GetPixel(x+1, y+1).GetRed();
                }
                if(original[k]->GetPixel(x,y).GetRed() >= q && original[k]->GetPixel(x,y).GetRed() >= r){
                    filtered.back()->SetPixel(x,y,original[k]->GetPixel(x,y));
                }
                else{
                    filtered.back()->SetPixel(x,y,black);
                }

            }
        }
    }

}
