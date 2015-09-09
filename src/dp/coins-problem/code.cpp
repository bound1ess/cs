#include <cstdio>
#include <cassert>
#include <algorithm>

using namespace std;

const int INF = (1LL << 31) - 1;

int main() {
  int n, sum; // number of coins, sum
  scanf("%d%d", &n, &sum);
  assert(n > 0 && sum > 0);
  int *coins = new int[n], *dp = new int[sum + 1];
  dp[0] = 0;

  for (int i = 1; i <= sum; ++i) {
    dp[i] = INF;
  }

  for (int i = 0; i < n; ++i) {
    scanf("%d", coins + i);
    assert(coins[i] > 0);
  }

  for (int i = 1; i <= sum; ++i) {
    for (int j = 0; j < n; ++j) {
      if (coins[j] <= i && dp[i - coins[j]] != INF) {
        dp[i] = min(dp[i], 1 + dp[i - coins[j]]);
      }
    }
  }

  if (dp[sum] != INF) {
    printf("Answer to your problem is %d\n", dp[sum]);
  } else {
    printf("You can't get to %d with these coins.\n", sum);
  }

  int x;

  while (scanf("%d", &x) && x >= 0 && x <= sum) {
    if (dp[x] != INF) {
      printf("%d? Here you go, %d\n", x, dp[x]);
    } else {
      printf("It's impossible!\n");
    }
  }

  delete[] coins;
  delete[] dp;
  return 0;
}
