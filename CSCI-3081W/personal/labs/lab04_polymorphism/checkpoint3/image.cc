#include "image.h"
#include <iostream>
#include "color.h"

//Reading images
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

//Writing images
#define STBI_MSC_SECURE_CRT
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb_image_write.h"

using namespace std;

Image::Image() {
  width = 0;
  height = 0;
  image = new unsigned char[width * height * 4];
}

Image::Image(int width, int height) {
    this->width = width;
    this->height = height;
    image = new unsigned char[width * height * 4];
}
//Image::Image(const char* fileN)
Image::Image(std::string fileN) {
    int components = 4;
    if(unsigned char *loadedImage = stbi_load(fileN.c_str(), &width, &height, &components, STBI_rgb_alpha)) {
      image = new unsigned char[width * height * 4];
      copy(loadedImage, loadedImage + width*height*4, image);
      stbi_image_free(loadedImage);
    } else {
      cout<<"No Such File"<<endl;
    }
}

// Image::Image(const Image& obj) {
//     image = NULL;
//     *this = obj;
// }

Image::~Image() {
    delete[] image;
}

void Image::operator=(const Image& obj) {
    this->width = obj.width;
    this->height = obj.height;
    int size = this->width * this->height * 4;
    delete[] this->image;
    this->image = new unsigned char[size];
    copy(obj.image, obj.image + size, this->image);
}

void Image::SaveAs(std::string filename) {
    stbi_write_png(filename.c_str(), width, height, 4, image, width*4);
}

int Image::GetWidth() {
    return width;
}

int Image::GetHeight() {
    return height;
}

int Image::GetComponentNum() {
    return 4;
}

unsigned char* Image::GetPixel(int x, int y) {
    return &image[(y * width + x)*4];
}

void Image::SetPixel(int x, int y, Color color1) {
    // unsigned char* pix2 = &image[(y*width + x)*4];
    // pix2[0] = pix[0];
    // pix2[1] = pix[1];
    // pix2[2] = pix[2];
    // pix2[3] = pix[3];
    unsigned char* color_ = &image[(y*width + x)*4];
    //Color color_ = &image[y*width + x)*4];
    color_[0] = color1.red;
    color_[1] = color1.green;
    color_[2] = color1.blue;
    color_[3] = color1.alpha;
}
