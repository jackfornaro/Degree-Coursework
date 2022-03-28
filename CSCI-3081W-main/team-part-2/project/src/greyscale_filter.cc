#include "greyscale_filter.h"

GreyScaleFilter::GreyScaleFilter() {}

void GreyScaleFilter::Apply(const std::vector<Image*>& ins, const std::vector<Image*>& outs){
    for(int k = 0; k < ins.size(); k++){
        *outs[0] = *ins[0];
        int width = ins[0]->GetWidth();
        int height = ins[0]->GetHeight();
        float L;
        for(int i = 0; i < width; i++){
            for(int j = 0; j < height; j++){
                L = ins[0]->GetPixel(i, j).GetLuminance();
                outs[0]->SetPixel(i, j, Color(L, L, L, 1));
            }
        }
    }
    *ins[0] = *outs[0];
}
