#include "image.hpp"
#include <iostream>
using namespace std;

typedef unsigned char uchar;

int main(void){
    Image stap("stap.png");
    int N = stap.h * stap.w;
    int nk[256];
    int pk[256];
    int cdfk[256];
    int sk[256];
    Image histogram_image(stap.w, stap.h, 1);
    for(int y = 0; y < stap.h; y++){
        for(int x = 0; x < stap.w; x++){
            nk[stap.GetPixel(y, x, 1)]++;
        }
    }
    for(int k = 0; k < 256; k++){
        pk[k] = nk[k] / N;
    }
    cdfk[0] = pk[0];
    for(int k = 1; k < 256; k++){
        cdfk[k] = cdfk[k-1] + pk[k];
    }
    for(int k = 0; k < 256; k++){
        sk[k] = cdfk[k] * 255;
    }
    for(int y = 0; y < stap.h; y++){
        for(int x = 0; x < stap.w; x++){
            histogram_image.SetPixel(y, x, 1, cdfk[stap.GetPixel(y, x, 1)]);
        }
    }
    histogram_image.save("histogram.png");
}