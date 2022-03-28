#include "sharpen_filter.h"

SharpenFilter::SharpenFilter(){}

void SharpenFilter::Apply(const std::vector<Image*>& ins, const std::vector<Image*>& outs){
	for(int k = 0; k < ins.size(); k++){
		*outs[k] = *ins[k];
		int width = ins[k]->GetWidth();
		int height = ins[k]->GetHeight();

		Kernel kernel(25);

		for(int i = 2;i < width-2; i++){
			for(int j = 2;j < height-2; j++){
				// set each pixel, use sum to calculate result after using kernel
				float sum = 0;  
				int index = 0;  
	            for ( int m = i-2; m < i+3; m++){  
	                for (int n = j-2; n < j+3; n++){  
	                	sum += ins[k]->GetPixel(m,n).GetLuminance() * kernel.myKernel[index++];
					}
				}
            	sum /= 273;  
            	if (sum > 1)  
                	sum = 1;  
            	if (sum < 0)  
                	sum = 0;  

                outs[k]->SetPixel(i, j, Color(1,1,1,sum));
			}
		}
	}

}

