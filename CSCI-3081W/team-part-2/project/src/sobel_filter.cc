#include "sobel_filter.h"

SobelFilter::SobelFilter() {}

void SobelFilter::Apply(const std::vector<Image*>& ins, const std::vector<Image*>& outs){
    for(int k = 0; k < ins.size(); k++){
        *outs[0] = *ins[0];
        *outs[1] = *ins[0];
        int width = ins[0]->GetWidth();
        int height = ins[0]->GetHeight();
        Kernel k_x('x', 3);
        Kernel k_y('y', 3);
        ins[0]->CharToFloat(*ins[0]);
        
        for(int i = 1; i < width - 1; i++){
            for(int j = 1; j < height - 1; j++){
                float Ix = 0.0;
                float Iy = 0.0;
                int off_x;
                int off_y;
                for(int x = 0; x < 3; x++){
                    for(int y = 0; y < 3; y++){
                        off_x = i + x - 1;
                        off_y = j + y - 1;
                        float tempFloat = ins[0]->GetPixelFloat(off_x, off_y);
                        Ix += tempFloat * k_x.myKernel[y * k_x.size + x];
                        Iy += tempFloat * k_y.myKernel[y * k_y.size + x];
                    }
                }

                float intensity = sqrt(Ix * Ix + Iy * Iy);
                outs[0]->SetPixelFloat(off_x, off_y, intensity);
                float theta = atan2(Iy, Ix);
                outs[1]->SetPixelFloat(off_x, off_y, theta);
            }
        }
        Image newImage1(width, height);
        Image newImage2(width, height);
        for(int i = 0; i < width; i++){
            for(int j = 0; j < height; j++){
                float tempFloat1 = outs[0]->GetPixelFloat(i, j)*255.0;
                if(tempFloat1 > 255) tempFloat1 = 255;
                else if(tempFloat1 < 0) tempFloat1 = 0;
                float tempFloat2 = outs[1]->GetPixelFloat(i, j)*255.0;
                if(tempFloat2 > 255) tempFloat2 = 255;
                else if(tempFloat2 < 0) tempFloat2 = 0;

                unsigned char* temp1 = &newImage1.image[(j*width + i)*4];
                temp1[0] = tempFloat1;
                temp1[1] = tempFloat1;
                temp1[2] = tempFloat1;
                temp1[3] = 255;
                unsigned char* temp2 = &newImage2.image[(j*width + i)*4];
                temp2[0] = tempFloat2;
                temp2[1] = tempFloat2;
                temp2[2] = tempFloat2;
                temp2[3] = 255;
            }
        }
        *outs[0] = newImage1;
        *outs[1] = newImage2;
    }
}
