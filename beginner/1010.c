#include <stdio.h>

int main()
{
	int id_A, cnt_A, id_B, cnt_B;
	double price_A, price_B, total;

	scanf("%d %d %lf", &id_A, &cnt_A, &price_A);
	scanf("%d %d %lf", &id_B, &cnt_B, &price_B);

	total = price_A * cnt_A + price_B * cnt_B;
	printf("VALOR A PAGAR: R$ %.2lf\n", total);

	return 0;
}