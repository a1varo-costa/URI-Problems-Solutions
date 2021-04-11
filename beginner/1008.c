#include <stdio.h>

int main()
{
	int id, worked_h;
	float dollars_per_h;

	scanf("%d %d %f", &id, &worked_h, &dollars_per_h);
	printf("NUMBER = %d\nSALARY = U$ %.2f\n", id, worked_h * dollars_per_h);

	return 0;
}