#include<stdio.h>

#define F(x) ((x*x)+1)

int main() {
    int a = 0, b = 2;
    int n = 10;
    double x[n+1], y[n+1], I;
    double Sum_X = 0, Sum_I = 0;

    double h =(double) (b-a)/n;


    for(int i=0; i<=n; i++) {
        x[i] = a + i*h;
        //printf("%lf\t", x[i]);
        y[i] = F(x[i]);
        //printf("%lf\t", y[i]);
    }

    for(int i=0; i<=n; i++) {
        if(i==0||i==n) Sum_X += y[i];
        else Sum_I += y[i];
    }

    I = h*(Sum_X+2*Sum_I)/2;
    printf("Trapezoidal Rule...\n");
    printf("Integral value = %lf\n", I);

}