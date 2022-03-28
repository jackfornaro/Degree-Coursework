#include "gaussian_blur_filter.h"


GaussianBlurFilter::GaussianBlurFilter() {}

void GaussianBlurFilter::Apply(const std::vector<Image*>& ins, const std::vector<Image*>& outs){
    for(int k = 0; k < ins.size(); k++){
        *outs[0] = *ins[0];
        int width = ins[0]->GetWidth();
        int height = ins[0]->GetHeight();
        Kernel kernel(5);
        for(int i = 2; i < width-2; i++){
            for(int j = 2; j < height-2; j++){
                Color tempColor(0, 0, 0, 1);
                for(int x = 0; x < 5; x++){
                    for(int y = 0; y < 5; y++){
                        int xCor = i + x - 2;
                        int yCor = j + y - 2;
                        tempColor = tempColor + ins[0]->GetPixel(xCor, yCor) * (kernel.myKernel[x*kernel.size+y]);
                    }
                }
                outs[0]->SetPixel(i, j, tempColor);
            }
        }
        *ins[0] = *outs[0];
    }
}