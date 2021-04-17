#include <stdio.h>
#include <string.h>
#include <limits.h>

#define MAX_REAIS 1000002
#define MAX_CENTS 100
#define N_REAIS 7
#define N_CENTS 5

#define INF INT_MAX

const int REAIS[] = {1, 2, 5, 10, 20, 50, 100};
const int CENTS[] = {1, 5, 10, 25, 50};

int reais_cnt[N_REAIS], cents_cnt[N_CENTS];

typedef struct state {
	int val, prev, id;
} state_t;

state_t dp_reais[MAX_REAIS], dp_cents[MAX_CENTS];


void solve(int value, state_t *dp, const int *coins, int n_coins, int *cnt)
{
	for (int n = 1; n <= value; n++) {
		dp[n].val = INF;
		for (int i = 0; i < n_coins; i++) {
			if (coins[i] <= n && dp[n - coins[i]].val + 1 < dp[n].val) {
				dp[n].id = i;
				dp[n].prev = n - coins[i];
				dp[n].val = dp[n - coins[i]].val + 1;
			}
		}
	}

	for (int n = value; n > 0; ) {
		cnt[dp[n].id]++;
		n = dp[n].prev;
	}
}

void print_ans(int *cnt, const int *coins, int n_coins)
{
	char msg[256];
	int lim = 0;
	if (n_coins == N_REAIS) {
		puts("NOTAS:");
		strcpy(msg, "%d nota(s) de R$ %d.00\n");
		lim = 1; // set lim to 1 so that 'R$ 1.00' is not printed
	}
	else {
		puts("MOEDAS:");
		printf("%d moeda(s) de R$ 1.00\n", reais_cnt[0]);
		strcpy(msg, "%d moeda(s) de R$ 0.%02d\n");
	}

	for (int i = n_coins - 1; i >= lim; i--)
		printf(msg, cnt[i], coins[i]);
}

int main()
{
	int reais, cents;

	scanf("%d.%d", &reais, &cents);

	solve(reais, dp_reais, REAIS, N_REAIS, reais_cnt);
	solve(cents, dp_cents, CENTS, N_CENTS, cents_cnt);

	print_ans(reais_cnt, REAIS, N_REAIS);
	print_ans(cents_cnt, CENTS, N_CENTS);

	return 0;
}