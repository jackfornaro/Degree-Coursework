#ifndef IMAGE_H_
#define IMAGE_H_
#include <fstream>
#include "color.h"

class Image {
    unsigned char* image;
    int width, height, components;
  public:
    Image();
    Image(int width, int height, int components);
    Image(const std::string filename);
    Image(const Image& image);
    ~Image();

    void operator=(const Image& image);
    void SaveAs(const std::string filename);
    int GetHeight();
    int GetWidth();
    int GetComponentNum();
    // unsigned char* GetPixel(int x, int y);
    Color GetPixel(int x, int y);
    // void SetPixel(int x, int y, int pixel[4]);
    void SetPixel(int x, int y, Color color);
};

#endif // IMAGE_H_
