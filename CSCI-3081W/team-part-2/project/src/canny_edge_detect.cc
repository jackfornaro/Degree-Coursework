#include "canny_edge_detect.h"

using namespace std;


void CannyEdgeDetect(const std::vector<Image*>& ins, const std::vector<Image*>& outs, const std::vector<Image*>& forSobel){
    std::map<std::string, unique_ptr<Filter> > filters;
    filters["greyscale"] = unique_ptr<Filter>(new GreyScaleFilter());
    filters["gaussian_blur"] = unique_ptr<Filter>(new GaussianBlurFilter());
    filters["sobel"] = unique_ptr<Filter>(new SobelFilter());
    filters["non_maximum_suppression"] = unique_ptr<Filter>(new NonMaximumSuppressionFilter());
    filters["double_threshold"] = unique_ptr<Filter>(new DoubleThresholdFilter(0.3, 0.45));
    filters["hysteresis"] = unique_ptr<Filter>(new HysteresisFilter());
    


    filters["greyscale"]->Apply(ins, outs);
    filters["gaussian_blur"]->Apply(ins, outs);
    filters["sobel"]->Apply(ins, forSobel);
    filters["non_maximum_suppression"]->Apply(forSobel, outs);
    filters["double_threshold"]->Apply(outs, ins);
    filters["hysteresis"]->Apply(ins, outs);



}
