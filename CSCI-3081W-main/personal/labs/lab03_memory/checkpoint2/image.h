#ifndef IMAGE_H_
#define IMAGE_H_

#include <iostream>

using namespace std;

class Image {
private:
    int width, height;
    unsigned char* image;
public:
    Image(int width, int height);
    Image(const char* filename);
    Image(const Image& object);
    ~Image();
    void operator=(const Image& object);
    void SaveAs(const char* filename);
    int GetWidth();
    int GetHeight();
    int GetComponentNum();
    unsigned char* GetPixel(int x, int y);
    void SetPixel(int x, int y, unsigned char* pixel);
};

#endif
