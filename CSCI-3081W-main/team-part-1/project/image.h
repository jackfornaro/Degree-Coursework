#ifndef IMAGE_H_
#define IMAGE_H_
/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <fstream>
#include "color.h"

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
 /**
  * @brief The main class for the generation of Image.
  *
  *  Calls to \ref This is the base class to create any image objects.
  */

class Image {
    unsigned char* image;
    int width, height, components;
  public:
    Image();
    /**
    * @brief Constructor that takes in the width, height, and components to construct an image object.
    */
    Image(int width, int height, int components);
    /**
    * @brief Constructor that takes in the filename of a png image and initialize the instance image variable.
    */
    Image(const std::string filename);
    /**
    * @brief Copy constructor takes in another image object as argument to create an identical image object.
    */
    Image(const Image& image);
    ~Image();
    /**
    * @brief Equal overloaded operator is used to set an image object equal to the input image object.
    */
    void operator=(const Image& image);
    /**
    * @brief SaveAs takes in a filename and save the file as "filename.png".
    */
    void SaveAs(const std::string filename);
    /**
    * @brief To get the height of the image object
    *
    * @return the height of the image
    */
    int GetHeight();
    /**
    * @brief To get the width of the image object
    *
    * @return the width of the image
    */
    int GetWidth();
    /**
    * @brief To get the compoenent value of the image object
    *
    * @return the components of the image
    */
    int GetComponentNum();
    // unsigned char* GetPixel(int x, int y);
    /**
    * @brief To get the Color object of the image object, the color object consist the values of float red, green, blue and alpha.
    *
    * @return the Color object of the pixel at the provided x and y location.
    */
    Color GetPixel(int x, int y);
    /**
    * @brief The method will cast the 4 bytes unsigned char* at location of the x and y pixel to 4 bytes float and return it.
    *
    * @return the float of the pixel at the provided x and y location.
    */
    float GetPixelFloat(int x, int y) const;
    // void SetPixel(int x, int y, int pixel[4]);
    /**
    * @brief Set the location of the x and y  pixel of the image to the color object that consist the values of float red, green, blue and alpha.
    *
    */
    void SetPixel(int x, int y, Color color);
    /**
    * @brief Set the location of the x and y pixel of the image to the provided float value.
    *
    */
    void SetPixelFloat(int x, int y, float value);

};

#endif // IMAGE_H_
