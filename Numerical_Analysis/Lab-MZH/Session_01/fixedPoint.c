#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define EPS 10.0e-6
#define F(x) ((x) * (x) * (x) + 4 * (x) * (x)-10)
#define G(x) sqrt((10 - ((x) * (x) * (x))) / 4)

int main(void)
{
	int n = 100, i = 1;
	double x0 = 1.25, x1;

	printf("Iter       x0             F(x0)            x1            F(x1)\n");
	for (i = 1; i < n; i++)
	{
		x1 = G(x0);
		printf(" %3d\t%10.6lf\t%10.6lf\t%10.6lf\t%10.6lf\n", i, x0, F(x0), x1, F(x1));

		x0 = x1;

		if (fabs(F(x1)) < EPS)
		{
			printf("Root = %lf\n", x1);
			exit(0);
		}
	}

	return (0);
}