#ifndef COLOR_H_
#define COLOR_H_
/*******************************************************************************
 * Includes
 ******************************************************************************/

 /*******************************************************************************
  * Class Definitions
  ******************************************************************************/
 /**
  * @brief The class is used to set the unsigned char* pixel to a color object that
  * contains values of float red, green, blue, and alpha.
  *
  *  Calls to \ref This is the class that is used to store the color values for the pixels.
  */
class Color {
  float red;
  float green;
  float blue;
  float alpha;
public:
  /**
  * @brief The default Constructor will initialize the object to the deafult RGBA values.
  */
  Color();
  /**
  * @brief Constructor that takes in the RGBA values and intilize the object to those values.
  */
  Color(float red, float green, float blue, float alpha);
  /**
  * @brief The deafult destructor
  */
  ~Color();
  /**
  * @brief Below are a list of overloaded operators that allow us to take the Color object
  * and do common operations such as (+, -, *, /) to another Color object or float number.
  * @return Return the result of of the opertion to a Color object.
  */
  Color operator+ (const Color &color);
  Color operator+ (const float num);
  Color operator- (const Color &color);
  Color operator* (const Color &color);
  Color operator* (const float num);
  Color operator/ (const Color &color);
  Color operator/ (const float num);
  /**
  * @brief The overloaded equal operator that will set the Color object values to another Color object values.
  */
  void operator= (const Color &color);
  void operator= (const float num);
  /**
  * @brief Calling this method will give us the luminance value of the current pixel.
  *
  * @return Return the float value of the luminance value at the current pixel.
  */
  float GetLuminance();
  /**
  * @brief Calling this method will give us the red value of the current pixel.
  *
  * @return Return the float value of the red value at the current pixel.
  */
  float GetRed();
  /**
  * @brief Calling this method will give us the green value of the current pixel.
  *
  * @return Return the float value of the green value at the current pixel.
  */
  float GetGreen();
  /**
  * @brief Calling this method will give us the blue value of the current pixel.
  *
  * @return Return the float value of the blue value at the current pixel.
  */
  float GetBlue();
  /**
  * @brief Calling this method will give us the alpha value of the current pixel.
  *
  * @return Return the float value of the alpha value at the current pixel.
  */
  float GetAlpha();
  /**
  * @brief Set the current Color object instance red variable to the float number in the argument.
  */
  void SetRed(float num);
  /**
  * @brief Set the current Color object instance green variable to the float number in the argument.
  */
  void SetGreen(float num);
  /**
  * @brief Set the current Color object instance blue variable to the float number in the argument.
  */
  void SetBlue(float num);
  /**
  * @brief Set the current Color object instance alpha variable to the float number in the argument.
  */
  void SetAlpha(float num);

};

#endif
