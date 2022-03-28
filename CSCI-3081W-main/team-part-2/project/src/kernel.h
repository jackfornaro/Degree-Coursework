#ifndef KERNEL_H_
#define KERNEL_H_

#include <vector>

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @brief The class for implementation of kernel
 */
class Kernel{
private:
    float* myKernel;
    int size;
public:
    /**
     * @brief This is a constructor with parameters to generate a kernel object with given size
     * @param size kernel's size
     * @return This constructor returns an object of kernel with given size
     */
    Kernel(int size);

    /**
     * @brief This is a constructor with parameters to generate a sobel kernel object with given size
     * @param c the first argument
     * @param size the second argument
     * @return This constructor returns an object of sobel kernel with given size
     */
    Kernel(char c, int size);

    /**
	 * @brief This is a default destructor to free dynamically allocated memory
	 */
    ~Kernel();

    friend class GaussianBlurFilter;
    friend class SobelFilter;
    friend class SharpenFilter;
};

#endif