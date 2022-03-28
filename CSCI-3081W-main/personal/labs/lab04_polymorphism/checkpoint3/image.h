#ifndef IMAGE_H_
#define IMAGE_H_

#include <iostream>
#include <string>
#include <vector>
#include "color.h"

using namespace std;

class Image {
private:
    int width, height;
    unsigned char* image;
public:
    Image();
    Image(int width, int height);
    Image(std::string filename);
    //Image(const Image& object);
    ~Image();
    void operator=(const Image& object);
    void SaveAs(std::string filename);
    int GetWidth();
    int GetHeight();
    int GetComponentNum();
    unsigned char* GetPixel(int x, int y);
    void SetPixel(int x, int y, Color color1);
};

#endif
