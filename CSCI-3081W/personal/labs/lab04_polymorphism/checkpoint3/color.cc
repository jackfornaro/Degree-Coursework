#include "color.h"

Color::Color() {
  this->red = 0;
  this->green = 0;
  this->blue = 0;
  this->alpha = 0;
}

Color::Color(float r, float g, float b, float a) {
  this->red = r;
  this->green = g;
  this->blue = b;
  this->alpha = a;
}

Color Color::operator+(Color color) {
  return Color(red + color.red, green + color.green, blue + color.blue, alpha + color.alpha);
}

Color Color::operator-(Color color) {
  return Color(red - color.red, green - color.green, blue - color.blue, alpha - color.alpha);
}

Color Color::operator*(float scal) {
  return Color(red * scal, green * scal, blue * scal, alpha * scal);
}

Color Color::operator/(float scal) {
  return Color(red / scal, green / scal, blue / scal, alpha / scal);
}
