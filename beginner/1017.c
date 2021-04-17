#include <stdio.h>
#define KM_PER_LITER 12.0

int main()
{
	int hours, speed, dist;

	scanf("%d %d", &hours, &speed);

	dist = hours * speed;
	printf("%.3lf\n", dist / KM_PER_LITER);
	return 0;
}