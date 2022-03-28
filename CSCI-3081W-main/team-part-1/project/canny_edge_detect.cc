using namespace std;
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
#include "canny_edge_detect.h"
#include "greyscale_filter.h"
#include "gaussian_blur_filter.h"
#include "sobel_filter.h"
#include "non_max_suppression.h"
#include "double_threshold.h"
#include "hysteresis.h"
#include <cmath>

/*******************************************************************************
 * Member Functions
 ******************************************************************************/

 //Questions to ask:
 //Sobel <image*> filtered outputting error

CannyEdgeDetectFilter :: CannyEdgeDetectFilter() {}

void CannyEdgeDetectFilter::Apply(std::vector<Image*> &original, std::vector<Image*> &filtered) {
  std::vector<Image*> images1;
  std::vector<Image*> images2;

  // std::vector<Image*> dummy;
  for (int k = 0; k < original.size(); k++ ) {
    
    Image image1(*original[k]);
    Image image2(*original[k]);
    images1.push_back(&image1);
    images2.push_back(&image2);
    *filtered[k] = *original[k];

    Filter* greyscale = new GreyScaleFilter();
    greyscale->Apply(images1, images2);

    Filter* gaussian = new GaussianBlurFilter();
    gaussian->Apply(images2, images1);
    // *filtered[0] = *images1[0];

    Image output2;
    images2.push_back(&output2);

    Filter* sobel = new SobelFilter();
    sobel->Apply(images1, images2);
    // *filtered[0] = *images2[1];

    Filter* non_max = new NonMaxSup();
    non_max->Apply(images2, images1);
    // *filtered[0] = *images1[0];
    
    vector<Image*>::iterator l = images2.begin();
    images2.erase(l+1);

    Filter* double_threshold = new DoubleThreshold(0.2, 0.1);
    double_threshold->Apply(images1, images2);
    // *filtered[0] = *images2[0];

    Filter* hysteresis = new Hysteresis();
    hysteresis->Apply(images2, images1);
    
    *filtered[0] = *images1[0];

  }

}
