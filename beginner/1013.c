#include <stdio.h>
#include <stdlib.h>

#define greaterAB(a, b) (((a) + (b) + abs(a - b))/2)
#define greaterABC(a, b, c) (greaterAB(greaterAB(a, b), c))

int main()
{
	int a, b, c;

	scanf("%d %d %d", &a, &b, &c);
	printf("%d eh o maior\n", greaterABC(a, b, c));

	return 0;
}