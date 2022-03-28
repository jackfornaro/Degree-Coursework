#include "color.h"
Color::Color() {
    this->red = 0;
    this->green = 0;
    this->blue = 0;
    this->alpha = 255;
}

Color::Color(float red, float green, float blue, float alpha) {
    this->red = red;
    this->green = green;
    this->blue = blue;
    this->alpha = alpha;
}

Color::~Color() {}

Color Color::operator+ (const Color &color) {
    Color ret;
    ret.red = this->red + color.red;
    ret.green = this->green + color.green;
    ret.blue = this->blue + color.blue;
    return ret;
}

Color Color::operator+ (const float num) {
    Color ret;
    ret.red = this->red + num;
    ret.green = this->green + num;
    ret.blue = this->blue + num;
    return ret;
}

Color Color::operator- (const Color &color) {
  Color ret;
  ret.red = this->red - color.red;
  ret.green = this->green - color.green;
  ret.blue = this->blue - color.blue;
  return ret;
}

Color Color::operator* (const Color &color) {
  Color ret;
  ret.red = this->red * color.red;
  ret.green = this->green * color.green;
  ret.blue = this->blue * color.blue;
  return ret;
}

Color Color::operator* (const float num) {
  Color ret;
  ret.red = this->red * num;
  ret.green = this->green * num;
  ret.blue = this->blue * num;
  return ret;
}

Color Color::operator/ (const Color &color) {
  Color ret;
  ret.red = this->red / color.red;
  ret.green = this->green / color.green;
  ret.blue = this->blue / color.blue;
  return ret;
}

void Color::operator= (const Color &color) {
  this->red = color.red;
  this->green = color.green;
  this->blue = color.blue;
  this->alpha = color.alpha;
}

float Color::GetLuminance() {
  return 0.2126*red + 0.7152*green + 0.0722*blue;
}
