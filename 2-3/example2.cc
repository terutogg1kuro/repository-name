#include <iostream>
#include <cmath>
using namespace std;



double f1(double x){
    return(exp(x) + x - 5);
}

double f2(double x){
    return(cbrt(x));
}



int main(void){
    double a, b;
    a = 0;
    b = 2;
    double middle = 10;
    int count = 0;
    double difference = b - a;
    while(difference < -1e-12 || difference > 1e-12){
         /*cout << count << " " << a << " " << b << " " << middle << " " << difference << endl;*/
        difference = b - a;
        middle = (a + b) / 2;
        count++;
        if(f1(middle) > 0){
            b = middle;
        }else if(f1(middle) < 0){
            a = middle;
        }else{
            middle = 0;
        }
       

    }
    cout << middle << count << endl;
}