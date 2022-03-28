/*******************************************************************************
 * Includes
 ******************************************************************************/

#include "color.h"

/*******************************************************************************
 * Member Functions
 ******************************************************************************/
 
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
    ret.alpha = this->alpha;
    return ret;
}

Color Color::operator+ (const float num) {
    Color ret;
    ret.red = this->red + num;
    ret.green = this->green + num;
    ret.blue = this->blue + num;
    ret.alpha = this->alpha;
    return ret;
}

Color Color::operator- (const Color &color) {
  Color ret;
  ret.red = this->red - color.red;
  ret.green = this->green - color.green;
  ret.blue = this->blue - color.blue;
  ret.alpha = this->alpha;
  return ret;
}

Color Color::operator* (const Color &color) {
  Color ret;
  ret.red = this->red * color.red;
  ret.green = this->green * color.green;
  ret.blue = this->blue * color.blue;
  ret.alpha = this->alpha;
  return ret;
}

Color Color::operator* (const float num) {
  Color ret;
  ret.red = this->red * num;
  ret.green = this->green * num;
  ret.blue = this->blue * num;
  ret.alpha = this->alpha;
  return ret;
}

Color Color::operator/ (const Color &color) {
  Color ret;
  ret.red = this->red / color.red;
  ret.green = this->green / color.green;
  ret.blue = this->blue / color.blue;
  ret.alpha = this->alpha;
  return ret;
}

Color Color::operator/ (const float num) {
  Color ret;
  ret.red = this->red / num;
  ret.green = this->green / num;
  ret.blue = this->blue / num;
  ret.alpha = this->alpha;
  return ret;
}

void Color::operator= (const Color &color) {
  this->red = color.red;
  this->green = color.green;
  this->blue = color.blue;
  this->alpha = color.alpha;
}

void Color::operator= (const float num) {
  this->red = this->red * num;
  this->green = this->green * num;
  this->blue = this->blue * num;
}


float Color::GetLuminance() {
  return 0.2126*red + 0.7152*green + 0.0722*blue;
}

float Color::GetRed() {
  return red;
}

float Color::GetGreen() {
  return green;
}

float Color::GetBlue() {
  return blue;
}

float Color::GetAlpha() {
  return alpha;
}

void Color::SetRed(float num) {
  this->red = num;
}

void Color::SetGreen(float num) {
  this->green = num;
}

void Color::SetBlue(float num) {
  this->blue = num;
}

void Color::SetAlpha(float num) {
  this->alpha = num;
}
