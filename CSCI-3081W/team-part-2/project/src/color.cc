#include "color.h"


Color::Color() {}

Color::Color(float r, float g, float b, float a) : red(r), green(g), blue(b), alpha(a) {}

float Color::Red() const {return red;}

float Color::Green() const {return green;}

float Color::Blue() const {return blue;}

float Color::Alpha() const {return alpha;}

float Color::GetLuminance() const {
    return 0.2126*red+ 0.7152*green + 0.0722*blue;
}

Color& Color::operator=(const Color& color){
    this->red = color.red;
    this->green = color.green;
    this->blue = color.blue;
    this->alpha = color.alpha;
    return *this;
}

Color& Color::operator+(const Color& color){
    this->red += color.red;
    this->green += color.green;
    this->blue += color.blue;
    this->alpha += color.alpha;
    return *this;
}

Color& Color::operator*(float scalar){
    this->red *= scalar;
    this->green *= scalar;
    this->blue *= scalar;
    this->alpha *= scalar;
    return *this;
}