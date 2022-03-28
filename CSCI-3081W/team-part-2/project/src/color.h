#ifndef COLOR_H_
#define COLOR_H_

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @brief The class for implementation of color
 */
class Color{
private:
    float red, green, blue, alpha;
public:
    /**
     * @brief This is a default constructor to generate a color object
     * @return This default constructor returns an object of color
     */
    Color();

    /**
     * @brief This is a constructor with parameters to generate a color object with given values
     * @param r the first argument
     * @param g the second argument
     * @param b the third argument
     * @param a the fourth argument
     * @return This constructor returns an object of color with given values
     */
    Color(float r, float g, float b, float a);

    /**
     * @brief This is a method to retrieve its red value of the color object
     * @return It returns the value of red as a float
     */
    float Red() const;

    /**
     * @brief This is a method to retrieve its green value of the color object
     * @return It returns the value of green as a float
     */
    float Green() const;

    /**
     * @brief This is a method to retrieve its blue value of the color object
     * @return It returns the value of blue as a float
     */
    float Blue() const;

    /**
     * @brief This is a method to retrieve its alpha value of the color object
     * @return It returns the value of alpha as a float
     */
    float Alpha() const;

    /**
     * @brief This is a method to get the luminance value after applying a math equation
     * @return It returns the value of luminance as a float
     */
    float GetLuminance() const;

    /**
     * @brief This is a method to enable assignment operator 
     * @param color an color object
     * @return It updates a color object with new value
     */
    Color& operator=(const Color& color);

    /**
     * @brief This is a method to enable add operator between two color object
     * @param color an color object
     * @return It updates a color object with new value
     */
    Color& operator+(const Color& color);

    /**
     * @brief This is a method to enable multiply operator between two color object
     * @param scalar a scalar
     * @return It updates a color object with new value
     */
    Color& operator*(float scalar);

    friend class Image;
};



#endif //  COLOR_H_