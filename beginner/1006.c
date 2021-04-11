#include <stdio.h>

#define WEIGHT_A 2
#define WEIGHT_B 3
#define WEIGHT_C 5
#define avrg(a, b, c) ((WEIGHT_A * (a) + WEIGHT_B * (b) + WEIGHT_C * (c)) / (WEIGHT_A + WEIGHT_B + WEIGHT_C))

int main()
{
	double grade_a, grade_b, grade_c;
	double average;

	scanf("%lf %lf %lf", &grade_a, &grade_b, &grade_c);
	printf("MEDIA = %.1lf\n", avrg(grade_a, grade_b, grade_c));

	return 0;
}