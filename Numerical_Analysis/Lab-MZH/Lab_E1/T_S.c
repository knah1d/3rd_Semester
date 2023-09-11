#include<stdio.h>

#define F(x) ((x*x)+1)

double trapezoidal(double h, double Sum_O, double Sum_E, double Sum_X) {
    double I = h*(Sum_X+2*(Sum_O+Sum_E))/2;
    
    printf("Trapezoidal Rule...\n");
    printf("Integral value = %lf\n", I);
}

int main() {
    int a = 0, b = 2;
    int n = 10;
    if(n%2!=0) n++;
    double x[n+1], y[n+1], I;
    
    double Sum_X = 0, Sum_O = 0, Sum_E = 0;

    double h =(double) (b-a)/n;


    for(int i=0; i<=n; i++) {
        x[i] = a + i*h;
        //printf("%lf\t", x[i]);
        y[i] = F(x[i]);
        //printf("%lf\t", y[i]);
    }

    for(int i=0; i<=n; i++) {
        if(i==0||i==n) Sum_X += y[i];
        else if(i%2 == 0) Sum_E += y[i];
        else Sum_O += y[i];
    }

    I = h*( Sum_X + 4*Sum_O + 2*Sum_E )/3;

    printf("Simpson's 1/3 Rule...\n");
    printf("Integral value = %lf\n", I);
    printf("\n");
    trapezoidal(h, Sum_O, Sum_E, Sum_X);

}