#include<stdio.h>
#include<math.h>
#include <stdlib.h>
#define f(x) x*x
#define g(x) sqrt(x)
#define EPS 10.0e-6
#define h(x) (f(x)-g(x))

double bisection(double a, double b, int n) {
    double c;
    int i;
    if(h(a)*h(b)>0) exit(0);
   
    for(i = 1; i<n; i++) {
        c = (a+b)/2;
       
        if((fabs(h(c))<EPS)) {
            return c;
            
        }    
        if(h(a)*h(c)<0) b = c;
        else a = c;
        
    }
}

void trapezoidal(double h, double Sum_O, double Sum_E, double Sum_X) {
    double I = h*(Sum_X+2*(Sum_O+Sum_E))/2;
    
    printf("Area(Trapezoidal) = %lf\n", fabs(I));
}

double simpson(double a, double b, int n) {

    if(n%2!=0) n++;
    double x[n+1], y[n+1], I;
    
    double Sum_X = 0, Sum_O = 0, Sum_E = 0;

    double h =(double) (b-a)/n;


    for(int i=0; i<=n; i++) {
        x[i] = a + i*h;
        y[i] = h(x[i]);
    }

    for(int i=0; i<=n; i++) {
        if(i==0||i==n) Sum_X += y[i];
        else if(i%2 == 0) Sum_E += y[i];
        else Sum_O += y[i];
    }

    I = h*( Sum_X + 4*Sum_O + 2*Sum_E )/3;
    trapezoidal(h, Sum_O, Sum_E, Sum_X);
    return I;
}

int main() {
    double a = 0, b = bisection(0.5, 1.25, 100);
    printf("Root = %lf\n", b);
    int n = 10;
    printf("Area(Simpson's) = %lf\n", fabs(simpson(a, b, n)));
  
    // double area1 = simpson(a, b, n, f);
    // double area2 = simpson(a, b, n, g);
    // printf("%lf\n", fabs(area1-area2));
}