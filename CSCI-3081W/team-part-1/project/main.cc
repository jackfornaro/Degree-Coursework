/**
 * @file main.cc
 *
 */

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <memory>
#include "image.h"
#include "filter.h"
#include "greyscale_filter.h"
#include "mean_blur_filter.h"
#include "threshold_filter.h"
#include "hysteresis.h"
#include "remove_light_pixels.h"
#include "gaussian_blur_filter.h"
#include "sobel_filter.h"
#include "non_max_suppression.h"
#include "double_threshold.h"
#include "canny_edge_detect.h"
#include "pixelate_filter.h"
using namespace std;
/*******************************************************************************
 * Non-Member Functions
 ******************************************************************************/
int main(int argc, const char* argv[]) {
    // Get input file, filter type, and output file from command line
    // argc = # of arguments
    // argv = an array of arguments
    std::string inputFile(argv[1]);
    std::string filterType(argv[2]);
    std::string outputFile(argv[3]);

    // Create available filters (unique_ptr handles dynamic memory)
    std::map<std::string, unique_ptr<Filter>> filters;
    filters["greyscale"] = unique_ptr<Filter>(new GreyScaleFilter());
    filters["threshold"] = unique_ptr<Filter>(new ThresholdFilter(0.5));
    filters["threshold-low"] = unique_ptr<Filter>(new ThresholdFilter(0.25));
    filters["threshold-high"] = unique_ptr<Filter>(new ThresholdFilter(0.75));
    filters["mean_blur"] = unique_ptr<Filter>(new MeanBlurFilter());
    filters["hysteresis"] = unique_ptr<Filter>(new Hysteresis());
    filters["remove_light_pixels"] = unique_ptr<Filter>(new RemoveLightPixels());
    filters["gaussian_blur"] = unique_ptr<Filter>(new GaussianBlurFilter());
    filters["sobel"] = unique_ptr<Filter>(new SobelFilter());
    filters["pixelate"] = unique_ptr<Filter>(new PixelateFilter());
    filters["non_max_suppression"] = unique_ptr<Filter>(new NonMaxSup());
    filters["canny_edge"] = unique_ptr<Filter>(new CannyEdgeDetectFilter());
 
    
    // Create input and output vectors
    Image input(inputFile);
    Image output;
    Image output2;
    std::vector<Image*> inputs;
    std::vector<Image*> outputs;
    
    inputs.push_back(&input);
    outputs.push_back(&output);
    outputs.push_back(&output2);
    // Apply filter based on filter type

    filters[filterType]->Apply(inputs, outputs);

    // Save output image
    output.SaveAs(outputFile);
}
