#include <stdio.h>

#define tri_area(b, h)    ((b) * (h) / 2.0)
#define cir_area(r)       ((r) * (r) * 3.14159)
#define tra_area(a, b, h) (((a) + (b)) * h / 2.0)
#define sqr_area(a)       ((a) * (a))
#define rec_area(a, b)    ((a) * (b))

int main()
{
	double a, b, c;

	scanf("%lf %lf %lf", &a, &b, &c);

	printf("TRIANGULO: %.3lf\n", tri_area(a, c));
	printf("CIRCULO: %.3lf\n", cir_area(c));
	printf("TRAPEZIO: %.3lf\n", tra_area(a, b, c));
	printf("QUADRADO: %.3lf\n", sqr_area(b));
	printf("RETANGULO: %.3lf\n", rec_area(a, b));

	return 0;
}