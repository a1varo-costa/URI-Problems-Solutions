#include <stdio.h>

int main()
{
	int dist;
	double fuel;

	scanf("%d %lf", &dist, &fuel);
	printf("%.3lf km/l\n", dist/fuel);

	return 0;
}