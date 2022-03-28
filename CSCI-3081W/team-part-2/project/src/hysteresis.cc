#include "hysteresis.h"

HysteresisFilter::HysteresisFilter() {}

void HysteresisFilter::Apply(const std::vector<Image*>& ins, const std::vector<Image*>& outs) {
    for(int k = 0; k < ins.size(); k++){
        *outs[k] = *ins[k];
        int width=ins[k]->GetWidth();
	    int height=ins[k]->GetHeight();

        for(int i = 0; i < width; i++){
            for(int j = 0; j < height; j++){
                if(ins[k]->GetPixelFloat(i, j) == 25){
                    if((ins[k]->GetPixelFloat(i+1, j-1) == 255) || (ins[k]->GetPixelFloat(i+1, j) == 255) ||
                        (ins[k]->GetPixelFloat(i+1, j+1) == 255) || (ins[k]->GetPixelFloat(i, j-1) == 255) ||
                        (ins[k]->GetPixelFloat(i, j+1) == 255) || (ins[k]->GetPixelFloat(i-1, j-1) == 255) ||
                        (ins[k]->GetPixelFloat(i-1, j) == 255) || (ins[k]->GetPixelFloat(i-1, j+1) == 255))
                    {
                        outs[k]->SetPixelFloat(i, j, 255);
                    }
                    else{
                        outs[k]->SetPixelFloat(i, j, 0);
                    }
                }  
            }
        }
    }
}
