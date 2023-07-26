#include<stdio.h>
#include<math.h>
#define PI 3.1416

int main() {
	float a = 0, b = 2*PI, h, x, sinx, n = 100;
	h = (b-a)/n;
	x = a;
	sinx = sin(x);
	printf("   \"x\"   , \"sin(x)\"\n");
	printf("%lf , %lf\n", x, sinx);
	for(int i = 1; i<=n; i++) {
		x += h;
		sinx = sin(x);
		printf("%lf , %lf\n", x, sinx);
	}
}
