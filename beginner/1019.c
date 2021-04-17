#include <stdio.h>

int main()
{
	int hours, minutes, seconds;

	scanf("%d", &seconds);

	minutes = seconds / 60;
	seconds %= 60;
	hours = minutes / 60;
	minutes %= 60;

	printf("%d:%d:%d\n", hours, minutes, seconds);
	return 0;
}