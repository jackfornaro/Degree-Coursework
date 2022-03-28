#include <iostream>
#include <string>

// Needed for reading images
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

// Needed for writing images
#define STBI_MSC_SECURE_CRT
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb_image_write.h"

int main(int argc, char**argv) {
  // Load in an image
  int width, height, components;
	unsigned char *loadedImage = stbi_load("data/input.png", &width, &height, &components, STBI_rgb_alpha);
  components = 4; // Images may have less components, but we are forcing alpha with STBI_rgb_alpha

  // Copy the image data into a local image buffer and free the image
  unsigned char* image = new unsigned char[width*height*components];
	std::copy(loadedImage, loadedImage + width*height*components, image); // copy allows us to copy one byte array to another
  stbi_image_free(loadedImage);

  // Loop through the image pixels and modify values
  for (int x = 0; x < width; x++) {
    for (int y = 0; y < height; y++) {
      // Get the pixel as a byte array
      unsigned char* pixel = &image[(y*width + x)*4];

      // Edit these [red, green, blue, alpha / transparency] values below (values between 0 and 255):
      pixel[0] = 255*x/width;
      //pixel[1] = 0;      
      //pixel[2] = 0;
      //pixel[3] = 255;
    }
  }

  // Save the output image
  stbi_write_png("data/output.png", width, height, components, image, width*4);

  // Delete the local image buffer
  delete[] image;
}
