#include <stdio.h>
#include <math.h>

double f(double x) {
    return x * x * x + 4 * x * x - 10;
}

double bisection(double left, double right, double tolerance, int maxIterations) {
    if (f(left) * f(right) >= 0) {
        printf("Bisection method cannot guarantee a root in the given interval.\n");
        return NAN; // Return Not-a-Number (indicates failure)
    }

    double mid;
    int iteration = 0;

    while (iteration < maxIterations) {
        mid = (left + right) / 2.0;

        if (fabs(f(mid)) < tolerance || fabs(right - left) < tolerance) {
            printf("Root found after %d iterations.\n", iteration + 1);
            return mid;
        }

        if (f(left) * f(mid) < 0)
            right = mid;
        else
            left = mid;

        iteration++;
    }

    printf("Max iterations reached. Root not found.\n");
    return NAN; // Return Not-a-Number (indicates failure)
}

int main() {
    double left, right;
    printf("Enter the interval boundaries (left and right): ");
    scanf("%lf %lf", &left, &right);

    double tolerance = 1e-6;
    int maxIterations = 1000;

    double root = bisection(left, right, tolerance, maxIterations);
    if (!isnan(root)) {
        printf("The root is: %lf\n", root);
    }

    return 0;
}

