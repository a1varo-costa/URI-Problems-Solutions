#include <stdio.h>
#define A_WEIGHT 3.5
#define B_WEIGHT 7.5

int main()
{
	double grade_a, grade_b;
	double average;

	scanf("%lf %lf", &grade_a, &grade_b);
	average = (grade_a * A_WEIGHT + grade_b * B_WEIGHT) / (A_WEIGHT + B_WEIGHT);

	printf("MEDIA = %.5lf\n", average);
	return 0;
}