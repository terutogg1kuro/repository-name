#include "image.hpp"

typedef unsigned char uchar;

int main(void){
    Image grey("grey.png");
    int histogram[255] = {0};
     for(int y = 0; y < grey.h; y++){
        for(int x = 0; x < grey.w; x++){
            uchar v = grey.GetPixel(y, x, 1);
            histogram[v]++;
        }
     }
     int ms;
     for(int v = 0; v < 255; v++){
        ms = ms + histogram[v] * v;
     }
     uchar mt = ms / grey.h / grey.w;
     uchar m1, m2;
     int m1s, m2s;
     int ω1, ω2;
     for(int t = 0; t < 255; t++){
        for(int v = 0; v <= t; v++){
            m1s = m1s + histogram[v] * v;
            ω1 = ω1 + histogram[v];
        }
        for(int v = t; v < 255; v++){
            m2s = m2s + histogram[v] * v;
            ω2 = ω2 + histogram[v];
        }
     }
}