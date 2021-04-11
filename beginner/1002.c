#include <stdio.h>
#define PI 3.14159

int main()
{
	double a;
	scanf("%lf", &a);
	printf("A=%.4lf\n", PI * a * a);
	return 0;
}