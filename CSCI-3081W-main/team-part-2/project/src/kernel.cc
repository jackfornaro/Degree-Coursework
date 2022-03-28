#include "kernel.h"

float gaussianBlurKernel[5][5] = {
    {1/256.0, 4/256.0, 6/256.0, 4/256.0, 1/256.0},
    {4/256.0, 16/256.0, 24/256.0, 16/256.0, 4/256.0},
    {6/256.0, 24/256.0, 36/256.0, 24/256.0, 6/256.0},
    {4/256.0, 16/256.0, 24/256.0, 16/256.0, 4/256.0},
    {1/256.0, 4/256.0, 6/256.0, 4/256.0, 1/256.0}
};

float sobelKernelx[3][3] = {
    {-1, 0, 1},
    {-2, 0, 2},
    {-1, 0, 1}
};

float sobelKernely[3][3] = {
    {1, 2, 1},
    {0, 0, 0},
    {-1, -2, -1}
};

Kernel::Kernel(int size) : size(size){
    myKernel = new float[size*size];
    if(size == 3){
        for(int i = 0; i < size; i++){
            for(int j = 0; j < size; j++){
                myKernel[i*size+j] = 1/9;
            }
        }
    }
    else if(size == 5){
        for(int i = 0; i < size; i++){
            for(int j = 0; j < size; j++){
                myKernel[i*size+j] = gaussianBlurKernel[i][j];
            }
        }
    }
}

Kernel::Kernel(char c, int size) : size(size){
    myKernel = new float[size*size];
    if(c == 'x'){
        for(int i = 0; i < 3; i++){
            for(int j = 0; j < 3; j++){
                myKernel[i*size+j] = sobelKernelx[i][j];
            }
        }
    }
    else if(c == 'y'){
        for(int i = 0; i < 3; i++){
            for(int j = 0; j < 3; j++){
                myKernel[i*size+j] = sobelKernely[i][j];
            }
        }
    }
}

Kernel::~Kernel() { delete[] myKernel; }