#include "image.hpp"
#include <iostream>
using namespace std;

typedef unsigned char uchar;

int main(void){
    Image grey("grey.png");
    int histogram[256] = {0};
     for(int y = 0; y < grey.h; y++){
        for(int x = 0; x < grey.w; x++){
            uchar v = grey.GetPixel(y, x, 1);
            histogram[v]++;
        }
     }
     int ms = 0;
     for(int v = 0; v < 256; v++){
        ms = ms + histogram[v] * v;
     }
     uchar mt = ms / grey.h / grey.w;
     uchar m1, m2;
     int m1s, m2s;
     int ω1, ω2;
     uchar max_t = 0;
     int dispersion[256];
     for(int t = 0; t < 256; t++){
        m1s = 0;
        m2s = 0;
        ω1 = 0;
        ω2 = 0;

        for(int v = 0; v <= t; v++){
            m1s = m1s + histogram[v] * v;
            ω1 = ω1 + histogram[v];
        }
        for(int v = t; v < 256; v++){
            m2s = m2s + histogram[v] * v;
            ω2 = ω2 + histogram[v];
        }
        m1 = m1s / ω1;
        m2 = m2s / ω2;
        dispersion[t] =  (ω1*pow(m1 - mt,2)) + (ω2*pow(m2 - mt,2)) / (ω1 + ω2);
        cout << dispersion[t] << endl;
     }
     for(int t = 1; t < 256; t++){
        if(dispersion[max_t] < dispersion[t]){
            max_t = t;
        }
     }
     cout << endl;
     cout << max_t << endl;
}

//各ｔにおけるクラス間分散が求められなかった。