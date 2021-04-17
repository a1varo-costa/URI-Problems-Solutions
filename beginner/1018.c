#include <stdio.h>
#include <string.h>
#include <limits.h>

#define N_COINS 7
#define MAX_VAL 1000002

const int COINS[] = {1, 2, 5, 10, 20, 50, 100};

int dp[MAX_VAL];
struct {
	int coin_id, val;
} prev[MAX_VAL];

int coin_cnt[N_COINS];

int main()
{
	int value;

	scanf("%d", &value);

	dp[0] = 0;
	// minimum for every coin in range [1, value], inclusive
	for (int n = 1; n <= value; n++) {
		int last_coin = -1;
		dp[n] = INT_MAX;
		// go through all coins smaller than 'n'
		for (int i = 0; i < N_COINS; i++) {
			if (COINS[i] <= n && dp[n - COINS[i]] + 1 < dp[n]) {
				prev[n].coin_id = i;
				prev[n].val = n - COINS[i];
				dp[n] = dp[n - COINS[i]] + 1;
			}
		}
	}

	for (int n = value; n > 0; ) {
		int diff = n - prev[n].val;
		coin_cnt[prev[n].coin_id]++;
		n = prev[n].val;
	}

	// output
	printf("%d\n", value);
	for (int i = N_COINS-1; i >= 0; i--) {
		printf("%d nota(s) de R$ %d,00\n", coin_cnt[i], COINS[i]);
	}
	return 0;
}