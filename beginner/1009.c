#include <stdio.h>
#define MAX_NAME_LEN 256

int main()
{
	char name[MAX_NAME_LEN];
	double salary, sales;

	scanf("%s %lf %lf", name, &salary, &sales);
	printf("TOTAL = R$ %.2lf\n", salary + sales * 0.15);

	return 0;
}