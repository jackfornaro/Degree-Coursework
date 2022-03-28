#include <string>
#include "image.h"
#include <iostream>
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

#define STBI_MSC_SECURE_CRT
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb_image_write.h"


Image::Image(){
  width = 640;
  height = 480;
  components = 4;
  image = new unsigned char[width*height*components];
}

Image::Image(int width, int height) : width(width), height(height){
  components = 4;
  image = new unsigned char[width*height*components];	
}

Image::Image(const char* filename){
  unsigned char *loadedImage = stbi_load(filename, &width, &height, &components, STBI_rgb_alpha);
  components = 4; 
  image = new unsigned char[width*height*components];
  std::copy(loadedImage, loadedImage + width*height*components, image); 
  stbi_image_free(loadedImage);
}

Image::~Image(){ delete[] image;}

Image::Image(const Image& img){
  image = NULL;
  *this = img;
}

Image& Image::operator= (const Image& img){
  this->width = img.width;
  this->height = img.height;
  this->components = img.components;
  delete[] this->image;
  this->image = new unsigned char[this->width*this->height*this->components];
  for(int i = 0; i < (width*height*components); i++){
    this->image[i] = img.image[i];
  }
  return *this;
}
/*
new image char*
iterator original..each pixel float 
RBGA

*/
void Image::SaveAs(const char* filename, bool isFloat){
  if(isFloat){
    Image newImage(this->width, this->height);
    for(int i = 0; i < width; i++){
      for(int j = 0; j < height; j++){
        float tempFloat = this->GetPixelFloat(i, j)*255.0;
        if(tempFloat > 255) tempFloat = 255;
        else if(tempFloat < 0) tempFloat = 0;

        unsigned char* temp = &newImage.image[(j*width + i)*4];
        temp[0] = tempFloat;
        temp[1] = tempFloat;
        temp[2] = tempFloat;
        temp[3] = 255;
      }
    }
    stbi_write_png(filename, width, height, components, newImage.image, width*4);
  }
  else{
    stbi_write_png(filename, width, height, components, image, width*4);
  }
}

int Image::GetHeight() const {return height;}

int Image::GetWidth() const {return width;}

Color Image::GetPixel(int x, int y) const {
  unsigned char* temp = &image[(y*width + x)*4];
  Color tempColor(1.0*temp[0]/255.0, 1.0*temp[1]/255.0, 1.0*temp[2]/255.0, 1.0*temp[3]/255.0);
	return tempColor;
}

float Image::GetPixelFloat(int x, int y) const {
  if(x < 0) x = 0;
  if(x >= width) x = width - 1;
  if(y < 0) y = 0;
  if(y >= height) y = height - 1;
  unsigned char* temp = &image[(y*width + x)*4];
  return *reinterpret_cast<float*>(temp);
}

void Image::SetPixel(int x, int y,  Color color){
  unsigned char* temp = &image[(y*width + x)*4];
	temp[0] = color.Red()*255.0;
	temp[1] = color.Green()*255.0;
	temp[2] = color.Blue()*255.0;
	temp[3] = color.Alpha()*255.0;
}

void Image::SetPixelFloat(int x, int y,  float value) const {
  unsigned char* temp = &image[(y*width + x)*4];
  *reinterpret_cast<float*>(temp) = value;
}

void Image::CharToFloat(Image& img){
  for(int i = 0; i < width; i++){
    for(int j = 0; j < height; j++){
      Color tempColor(0, 0, 0, 1);
      tempColor = img.GetPixel(i, j);
      img.SetPixelFloat(i, j, tempColor.red);
    }
  }
}