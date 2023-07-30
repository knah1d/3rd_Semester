#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define EPS 10.0e-6
#define F(x) ((x)*(x)*(x)+4*(x)*(x)-10)
void bisec(double a, double b) {
    int n = 100, i;
    double c;

    if(F(a)*F(b)>0) exit(0);
    printf("Iter     a           b          c        f(a)       f(b)       f(c)\n");
    for(i = 1; i<n; i++) {
        c = (a+b)/2;
        printf("%3d %10.6lf %10.6lf %10.6lf %10.6lf %10.6lf %10.6lf\n", i, a, b, c, F(a), F(b), F(c) );
        if((fabs(F(c))<EPS)) {
            printf("Root = %lf\n", c);
            exit(0);
        }    
        if(F(a)*F(c)<0) b = c;
        else a = c;
        
    }
}
int main(void) {
    int i;
    double A = -5.0, B = 5.0, a, b, h;
	h = (B-A)/6;
    a = A;
	for(int j = 0; j<6; j++) {
    	
    	
    	b = a+h;
    	bisec(a, b);
    	a = b;


    }
}
