#include <stdio.h>
#include <math.h>

double f(double x) {
    return x * x + 1;
}

double forward_difference(double y0, double y1, double x0, double x1) {
    return (y1 - y0) / (x1 - x0);
}

double backward_difference(double yn, double yn_1, double xn, double xn_1) {
    return (yn - yn_1) / (xn - xn_1);
}

double central_difference(double yi_plus_1, double yi_minus_1, double xi_plus_1, double xi_minus_1) {
    return (yi_plus_1 - yi_minus_1) / (xi_plus_1 - xi_minus_1);
}

int main() {
    double a = 0.0;
    double b = 2.0;
    int n = 10;
    double h = (b - a) / n;

    double x[n + 1];
    double y[n + 1];


    for (int i = 0; i <= n; i++) {
        x[i] = a + i * h;
        y[i] = f(x[i]); 
    }

    printf("x,\tForward Diff,\tCentral Diff,\tBackward Diff\n");


    printf("%.2lf,\t \t\t%.6lf,\t \n", x[0], central_difference(y[1], y[0], x[1], x[0]));
    for (int i = 1; i < n; i++) {
    printf("%.2lf,\t%.6lf,\t%.6lf,\t%.6lf\n", x[i], forward_difference(y[i - 1], y[i], x[i - 1], x[i]), central_difference(y[i + 1], y[i - 1], x[i + 1], x[i - 1]), backward_difference(y[i], y[i - 1], x[i], x[i - 1]));
    }
    printf("%.2lf,\t \t\t%.6lf,\t \n", x[n], central_difference(y[n], y[n - 1], x[n], x[n - 1]));

    return 0;
}

