/**
 * @kernel.cc
 *
 */

/*******************************************************************************
* Includes
******************************************************************************/
#include "kernel.h"
#include <iostream>


/*******************************************************************************
 * Member Functions
 ******************************************************************************/

void Kernel::SetKSize(int size) {
  this->ksize = size;
}

int Kernel::GetKSize() {
  return this->ksize;
}

void Kernel::operator= (const Kernel &kernel) {
  this->ksize = kernel.ksize;
  this->sigma = kernel.sigma;
  this->gaussian_kernel = kernel.gaussian_kernel;
}

Kernel Kernel::operator/ (float num) {
  Kernel ret;
  ret.ksize = this->ksize;
  ret.sigma = this->sigma;
  ret.gaussian_kernel = this->gaussian_kernel;
  return ret;
}

void Kernel::GaussianKernel() {
  int k_size = 2 * ksize + 1;
  float base = 1 / (2.0 * M_PI * (sigma * sigma));
  float numerator, denominator, value, sum;
  //setting up values
  for (int x = 0; x < k_size; x++) {
    std::vector<float> row;
    for(int y = 0; y < k_size; y++) {
      numerator = (x - (ksize + 1.0)) * (x - (ksize + 1.0)) + (y - (ksize + 1.0)) * (y - (ksize + 1.0));
      denominator = 2.0 * (sigma * sigma);
      value = pow(base, -1 * (numerator/denominator));
      row.push_back(value);
      sum += value;
    }
    gaussian_kernel.push_back(row);
  }
  for (int x = 0; x < k_size; x++) {
    for(int y = 0; y < k_size; y++) {
      gaussian_kernel[x][y] /= sum;
    }
  }
}

void Kernel::SobelKernel() {
  sobel_kx_kernel = { {-1, 0, 1},
                      {-2, 0, 2},
                      {-1, 0, 1}};

  sobel_ky_kernel = { {1, 2, 1},
                      {0, 0, 0},
                      {-1, -2, -1}};
}
