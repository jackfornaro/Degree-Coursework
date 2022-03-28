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

using namespace std;

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

    // Create input and output vectors
    Image input(inputFile);
    Image output;
    std::vector<Image*> inputs;
    std::vector<Image*> outputs;
    inputs.push_back(&input);
    outputs.push_back(&output);

    // Apply filter based on filter type
    filters[filterType]->Apply(inputs, outputs);

    // Save output image
    output.SaveAs(outputFile);
}
