#include "double_threshold.h"

DoubleThresholdFilter::DoubleThresholdFilter(float low, float high):lowRatio(low), highRatio(high){
}

void DoubleThresholdFilter::Apply(const std::vector<Image*>& ins, const std::vector<Image*>& outs){
	for(int k = 0; k < ins.size(); k++){
		*outs[k] = *ins[k];
		int width = ins[k]->GetWidth();
		int height = ins[k]->GetHeight();
		float maxValue = 0;

		for(int i = 0; i < width; i++){
			for(int j = 0; j < height; j++){
				if(ins[k]->GetPixelFloat(i,j) > maxValue){
					maxValue = ins[k]->GetPixelFloat(i,j);
				}
			}
		}

		float highThreshold = maxValue * (1 - highRatio);
		float lowThreshold = highThreshold * (1 - lowRatio);

		for(int i = 0; i < width; i++){
			for(int j = 0; j < height; j++){
				if(ins[k]->GetPixelFloat(i, j) >= highThreshold){
					outs[k]->SetPixelFloat(i, j, 255);
				}
				else if(ins[k]->GetPixelFloat(i, j) >= lowThreshold & ins[k]->GetPixelFloat(i, j) < highThreshold){
					outs[k]->SetPixelFloat(i, j, 25);
				}
				else{
					outs[k]->SetPixelFloat(i, j, 0);
				}
			}
		}

	}
}
