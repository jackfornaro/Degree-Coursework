#include "non_maximum_suppression.h"

NonMaximumSuppressionFilter::NonMaximumSuppressionFilter() {}

void NonMaximumSuppressionFilter::Apply(const std::vector<Image*>& ins, const std::vector<Image*>& outs){
    for(int k = 0; k < 1; k++){
        *outs[0] = *ins[0];
        int width = ins[0]->GetWidth();
        int height = ins[0]->GetHeight();
        Image intensity = *ins[0];
        Image direction = *ins[1];
        intensity.CharToFloat(intensity);
        direction.CharToFloat(direction);
        
        for(int i = 0; i < width; i++){
            for(int j = 0; j < height; j++){
                float angle = direction.GetPixelFloat(i, j) *(180 / M_PI);
                if(angle < 0) {angle += 180;}
                float q = 255;
                float r = 255;
                if((0 <= angle && angle < 22.5) || (157.5 <= angle && angle <= 180)){
                    q = intensity.GetPixelFloat(i, j+1);
                    r = intensity.GetPixelFloat(i, j-1);
                }
                else if(22.5 <= angle && angle < 67.5){
                    q = intensity.GetPixelFloat(i+1, j-1);
                    r = intensity.GetPixelFloat(i-1, j+1);
                } 
                else if(67.5 <= angle && angle < 112.5){
                    q = intensity.GetPixelFloat(i+1, j);
                    r = intensity.GetPixelFloat(i-1, j);
                } 
                else if(112.5 <= angle && angle < 157.5){
                    q = intensity.GetPixelFloat(i-1, j-1);
                    r = intensity.GetPixelFloat(i+1, j+1);
                } 

                if((intensity.GetPixelFloat(i, j) >= q) && (intensity.GetPixelFloat(i, j) >= r)){
                    outs[0]->SetPixelFloat(i, j, intensity.GetPixelFloat(i, j));
                }
                else{
                    outs[0]->SetPixelFloat(i, j, 0);
                }
            }
        }
    }
}
