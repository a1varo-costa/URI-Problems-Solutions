#include <stdio.h>

int main()
{
	int a, b;
    long long prod;

	scanf("%d %d", &a, &b);
	prod = (long long)a * b;
    printf("PROD = %lld\n", prod);

	return 0;
}