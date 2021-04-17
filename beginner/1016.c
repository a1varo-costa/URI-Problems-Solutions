#include <stdio.h>

#define MIN_PER_KM 2

int main()
{
	int min;
	scanf("%d", &min);
	printf("%d minutos\n", min * MIN_PER_KM);
	return 0;
}
