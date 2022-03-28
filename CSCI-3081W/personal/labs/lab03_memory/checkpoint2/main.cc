#include "image.h"
#include "stb_image.h"
#include "stb_image_write.h"
#include <iostream>

using namespace std;

int main(int argc, char* argv[]) {

    // Step 1:
    // Create an image by loading in "data/statue.png"
    // Save the image as "data/statue_copy.png"
    Image statue_image = Image("data/statue.png");
    cout << statue_image.GetWidth() << " " << statue_image.GetHeight() << endl;
    statue_image.SaveAs("data/statue_copy.png");

    // Step 2:
    // Create an image of size 256 x 256.
    // Set each pixel to Red or [255, 0, 0, 255] => [red, green, blue, alpha]
    // Save the image as "data/red.png"
    unsigned char* currP;
    Image img = Image(256, 256);

    for(int i = 0; i < img.GetWidth(); i++) {
        for(int j = 0; j < img.GetHeight(); j++) {
            currP = img.GetPixel(i,j); //= img.GetPixel(i, j);
            currP[0] = 255;
            currP[1] = 0;
            currP[2] = 0;
            currP[3] = 255;
            img.SetPixel(i, j, currP);
        }
    }

    img.SaveAs("data/red.png");

    // Step 3:
    // Create an image of size 256 x 32
    // Edit the image to create a gradient
    // Save the image as "data/green_gradient.png"
    Image img2 = Image(256, 32);

    for(int i = 0; i < img2.GetWidth(); i++) {
        for(int j = 0; j < img2.GetHeight(); j++) {
            currP = img.GetPixel(i,j);
            currP[0] = 0;
            currP[1] = i;
            currP[2] = 0;
            currP[3] = 255;
            img2.SetPixel(i, j, currP);
        }
    }

    img2.SaveAs("data/green_gradient.png");
    return 0;
}
