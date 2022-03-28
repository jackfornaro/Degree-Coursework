#ifndef IMAGE_H_
#define IMAGE_H_

#include "color.h"

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @brief The class for implementation of image
 */
class Image{
private:
	int width, height;
	int components;
	unsigned char* image;
	
public:
	/**
     * @brief This is a default constructor to generate a image object
     * @return This default constructor returns an object of image
     */
	Image();

	/**
     * @brief This is a constructor with parameters to generate a image object with given values
     * @param width the width of the image
     * @param height the height of the image
     * @return This constructor returns an object of image with given values
     */
	Image(int width, int height);

	/**
     * @brief This is a constructor to generate a image object based on given png file
     * @param filename a string representing image file's name
     * @return This constructor returns an object of image with values of the png file
     */
	Image(const char* filename);

	/**
	 * @brief This is a default destructor to free dynamically allocated memory
	 */
	~Image();

	/**
     * @brief This is a copy constructor to get a copy of given image
     * @param img an image should be copied
     * @return It returns a copy of the image
     */
	Image(const Image& img);

	/**
     * @brief This is a copy assignment operator to set values
     * @param img an image should be copied
     * @return It updates the copied image with given values
     */
	Image& operator= (const Image& img);

	/**
     * @brief This is method to save an image in order to generate an output png file
     * @param filename a string representing image file's name
     */
	void SaveAs(const char* filename, bool isFloat);

	/**
     * @brief This is a method to get the height of the image
     * @return It returns image's height as an int
     */
	int GetHeight() const;

	/**
     * @brief This is a method to get the width of the image
     * @return It returns image's width as an int
     */
	int GetWidth() const;

	/**
     * @brief This is a method to get the pixel of the image at position (x, y)
     * @param x the first argument representing the row
     * @param y the second argument representing the column
     * @return It returns the pixel as a color object
     */
	Color GetPixel(int x, int y) const;

	/**
     * @brief This is a method to get the pixel of the image at position (x, y)
     * @param x the first argument representing the row
     * @param y the second argument representing the column
     * @return It returns the pixel as a float number
     */
	float GetPixelFloat(int x, int y) const;

	/**
     * @brief This is a method to set the pixel's value of the image at position (x, y), it treats each pixel as a color object
     * @param x the first argument representing the row
     * @param y the second argument representing the column
     * @param color the third argument representing the pixel's color
     */
	void SetPixel(int x, int y, Color color);

	/**
     * @brief This is a method to set the pixel's value of the image at position (x, y), it treats each pixel as a float number
     * @param x the first argument representing the row
     * @param y the second argument representing the column
     * @param color the third argument 
     */
	void SetPixelFloat(int x, int y,  float value) const;

	/**
     * @brief This is a method to convert an unsigned char* type image to be float type
     * @param img an image
     */
	void CharToFloat(Image& img);

	friend class SobelFilter;
};
	

#endif