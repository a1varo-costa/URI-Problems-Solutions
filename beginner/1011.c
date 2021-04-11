#include <stdio.h>

#define PI 3.14159
#define sphere_vol(r) ((4.0/3.0) * (PI) * ((r)*(r)*(r)))

int main()
{
	double radius;

	scanf("%lf", &radius);
	printf("VOLUME = %.3lf\n", sphere_vol(radius));

	return 0;
}