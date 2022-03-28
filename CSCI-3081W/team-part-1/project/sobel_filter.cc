/**
 * @file sobel_filter.cc
 *
 */

/*******************************************************************************
* Includes
******************************************************************************/
#include "sobel_filter.h"

/*******************************************************************************
 * Member Functions
 ******************************************************************************/

void SobelFilter::Apply(std::vector<Image*> &original, std::vector<Image*> &filtered) {
  //Set width, height equal to original image, set kernel size to k_size
  int width, height, k_size;
  //counter variables to keep track of kernel position
  int counter_x = 0, counter_y = 0;
  //Initialize the kernel
  Kernel kernel(1);
  //setting kernel to Sobel kernel
  kernel.SobelKernel();
  k_size = kernel.GetKSize();
  // std::cout << filtered.size() << std::endl;


  //iterate through each of the image from original
  for (int k = 0; k < original.size(); k+=2) {
    //Initialize the horizontal and vertical sobel filter to store the values
    Image sobel_kx(*original[k]);
    Image sobel_ky(*original[k]);
   
    *filtered[k] = *original[k];
    *filtered[k+1] = *original[k];
    
    width = original[k]->GetWidth();
    height = original[k]->GetHeight();

    //Setting each unsigned char pixel to float pixel
    for (int x = 0; x < width; x++) { 
      for (int y = 0; y < height; y++) {
        float temp = sobel_kx.GetPixel(x, y).GetRed();
        float temp2 = sobel_ky.GetPixel(x, y).GetRed();
        sobel_kx.SetPixelFloat(x, y, temp);
        sobel_ky.SetPixelFloat(x, y, temp2);
      }
    }
    //Convolution
    for (int x = 0; x < width; x++) {
      for (int y = 0; y < height; y++) {
        float sum1 = 0, sum2 = 0;
        counter_x = 0;
        for (int i = x-k_size; i <= x+k_size; i++) {
          counter_y = 0;
          for (int j = y-k_size; j <= y+k_size; j++) {
            if ( i >= 0 && j >= 0 && i < width && j < height) {
                sum1 = sum1 + (*original[k]).GetPixel(i, j).GetRed() * kernel.sobel_kx_kernel[counter_x][counter_y];
                sum2 = sum2 + (*original[k]).GetPixel(i, j).GetRed() * kernel.sobel_ky_kernel[counter_x][counter_y];
            }
            counter_y++;
          }
          counter_x++;
        }
        //Adding limit to float values
        if (sum1 > 255) {
          sum1 = 255;
        } else if (sum1 < 0) {
          sum1 = 0;
        }
        if (sum2 > 255) {
          sum2 = 255;
        } else if (sum2 < 0) {
          sum2 = 0;
        }
        sobel_kx.SetPixelFloat(x, y, sum1);
        sobel_ky.SetPixelFloat(x, y, sum2);
      }
    }
    
    //Combine the two image
    for (int x = 0; x < width; x++) {
      for (int y = 0; y < height; y++) {
        kernel.G = sqrt(sobel_kx.GetPixelFloat(x, y) * sobel_kx.GetPixelFloat(x, y) + sobel_ky.GetPixelFloat(x, y) * sobel_ky.GetPixelFloat(x, y));
        kernel.theta = atan2(sobel_ky.GetPixelFloat(x, y), sobel_kx.GetPixelFloat(x, y)) * (180/M_PI);
        // if (kernel.theta == 255){
        //   std::cout << kernel.theta << std::endl;
        // }
        
        //SAVING THE VALUES TO TWO IMAGE OBJECTS
        if ( kernel.theta < 0 ) {
          kernel.theta += 180;
        }
        // if ( kernel.theta > 255 ) {
        //   kernel.theta = 255;
        // }
        // filtered[k]->SetPixelFloat(x, y, kernel.G);
        // filtered[k+1]->SetPixelFloat(x, y, kernel.theta);
        //Adding limit to each pixel

        Color rgb3(kernel.G, kernel.G, kernel.G, (*original[k]).GetPixel(x, y).GetAlpha());
        Color rgb4(kernel.theta, kernel.theta, kernel.theta, (*original[k]).GetPixel(x, y).GetAlpha());

        filtered[k]->SetPixel(x, y, rgb3);
        filtered[k+1]->SetPixel(x, y, rgb4);
      }
    }
  }

}
