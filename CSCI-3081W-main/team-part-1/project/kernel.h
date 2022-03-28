#ifndef KERNEL_H_
#define KERNEL_H_
/**
 * @kernel.h
 *
 */

/*******************************************************************************
* Includes
******************************************************************************/
#include <cmath>
#include <vector>
/**
 * @brief The main class for the generation of kernel for different filters.
 *
 *  Calls to \ref This is the base class that is used to generate kernel.
 */
class Kernel {
  int ksize;
public:
  //Gaussian
  float sigma;
  std::vector<std::vector<float>> gaussian_kernel;
  //Sobel
  float G;
  float theta;
  std::vector<std::vector<float>> sobel_kx_kernel;
  std::vector<std::vector<float>> sobel_ky_kernel;
  /**
   * @brief The deafult constructor, set the kernel size to 0
   */
  Kernel() : ksize(0) {}
  /**
   * @brief The constructor, set the kernel size to the input int parameter
   */
  Kernel(int ksize) : ksize(ksize) {}
  /**
   * @brief The destructor
   */
  ~Kernel() {}
  /**
   * @brief The overloaded equal operator that is used to set the Kernel object to the input kernel object.
   */
  void operator= (const Kernel &kernel);
  /**
   * @brief The overloaded division operator that is used to divide the Kernel object to the input float number.
   */
  Kernel operator/ (float num);
  /**
   * @brief This method is used to initialize the gasussian kernel vector.
   */
  void GaussianKernel();
  /**
   * @brief This method is used to initialize the sobel kernel vector.
   */
  void SobelKernel();

  /**
  * @brief To get the size of the kernel object.
  *
  * @return the int size of the kernel.
  */
  int GetKSize();
  /**
  * @brief Set the size of the kernel object by the input size parameter.
  */
  void SetKSize(int size);

};

#endif
