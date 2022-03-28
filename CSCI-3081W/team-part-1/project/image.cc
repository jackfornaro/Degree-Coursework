/**
 * @image.cc
 *
 */

/*******************************************************************************
* Includes
******************************************************************************/
#include <iostream>
// #include <fstream>
using namespace std;
#include <string>
// Needed for reading images
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"
#include "image.h"
// Needed for writing images
#define STBI_MSC_SECURE_CRT
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb_image_write.h"

/*******************************************************************************
 * Member Functions
 ******************************************************************************/
Image::Image() : width(0), height(0), components(0) {
  image = new unsigned char[width*height*components];
}

Image::Image(int width, int height, int components) : width(width), height(height), components(components) {
   image = new unsigned char[width*height*components];
}

Image::Image(const std::string filename) {
  if(unsigned char* loadedImage = stbi_load(filename.c_str(), &width, &height, &components, STBI_rgb_alpha)) {
    components = 4;
    image = new unsigned char[width*height*components];
    std::copy(loadedImage, loadedImage + width*height*components, image);
    cout << "File loaded successfully" << endl;
    stbi_image_free(loadedImage);
  } else {
    cout << "No such file" << endl;
  }
}

Image::Image(const Image &image) {
  this->image = NULL;
  *this = image;
}

Image::~Image() {
  delete[] image;
}

void Image::operator=(const Image &image) {
  this->width = image.width;
  this->height = image.height;
  this->components = image.components;
  delete[] this->image;
  this->image = new unsigned char[image.width * image.height * image.components];
  std::copy(image.image, image.image + image.width * image.height * image.components, this->image);
  //return *this;
}

void Image::SaveAs(const std::string filename) {
  stbi_write_png(filename.c_str(), width, height, components, image, width*4);
}

int Image::GetHeight() {
  return height;
}

int Image::GetWidth() {
  return width;
}

int Image::GetComponentNum() {
  return components;
}

Color Image::GetPixel(int x, int y) {
  unsigned char* pix = &image[(y*width + x)*4];
  Color color;
  color.SetRed(pix[0]);
  color.SetGreen(pix[1]);
  color.SetBlue(pix[2]);
  color.SetAlpha(pix[3]);
  return color;
}

float Image::GetPixelFloat(int x, int y) const {
  unsigned char* pix = &image[(y*width + x)*4];
  return *reinterpret_cast<float*>(pix);
}

void Image::SetPixel(int x, int y, Color color) {
  unsigned char* pix = &image[(y*width + x)*4];
  pix[0] = color.GetRed();
  pix[1] = color.GetGreen();
  pix[2] = color.GetBlue();
  pix[3] = color.GetAlpha();
}

void Image::SetPixelFloat(int x, int y, float value) {
  unsigned char* pix = &image[(y*width + x)*4];
  *reinterpret_cast<float*>(pix) = value;
}
