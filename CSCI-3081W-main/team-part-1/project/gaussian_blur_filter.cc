using namespace std;
/*******************************************************************************
* Includes
******************************************************************************/
#include "gaussian_blur_filter.h"
#include <cmath>

/*******************************************************************************
 * Member Functions
 ******************************************************************************/
GaussianBlurFilter :: GaussianBlurFilter() {}

void GaussianBlurFilter::Apply(std::vector<Image*> &original, std::vector<Image*> &filtered) {
  //Set width, height equal to original image, set kernel size to k_size
  int width, height, k_size;
  //counter variables to keep track of kernel position
  int kx, ky;

  //Initialize the kernel
  Kernel kernel(2);
  //setting kernel to Gaussian blur kernel
  kernel.sigma = 8.0;
  kernel.GaussianKernel();
  k_size = kernel.GetKSize();

  //iterate through each of the image from original
  for (int k = 0; k < original.size(); k++) {
    *filtered[k] = *original[k];
    width = original[k]->GetWidth();
    height = original[k]->GetHeight();
    //Convolution
    for (int x = 0; x < width; x++) {
      for (int y = 0; y < height; y++) {
        Color rgb;
        kx = 0;
        for (int i = x-k_size; i <= x+k_size; i++) {
          ky = 0;
          for (int j = y-k_size; j <= y+k_size; j++) {
            if ( i >= 0 && j >= 0 && i < width && j < height) {
              rgb = rgb + (*original[k]).GetPixel(i, j) * kernel.gaussian_kernel[ky][kx];
            }
            ky++;
          }
          kx++;
        }
        filtered[k]->SetPixel(x, y, rgb);
      }
    }
  }

}
