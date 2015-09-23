#include <cstdio>
#include <cassert>

int main() {
  freopen("in.txt", "r", stdin);
  int n, ans = 1;
  scanf("%d", &n);
  assert(n > 0);
  int *arr = new int[n], *dp = new int[n];
  for (int i = 0; i < n; ++i) {
    scanf("%d", arr + i);
    dp[i] = 1;
  }
  for (int i = 1; i < n; ++i) {
    if (arr[i - 1] <= arr[i]) {
      dp[i] += dp[i - 1];
    }
    if (dp[i] > ans) {
      ans = dp[i];
    }
  }
  printf("The answer is %d\n", ans);
  for (int i = 0; i < n; ++i) {
    if (dp[i] == ans) {
      int j = i;
      while (dp[j] != 1) {
        --j;
      }
      while (j <= i) {
        printf("%d", arr[j]);
        printf(j + 1 <= i ? " " : "\n");
        ++j;
      }
      break;
    }
  }
  delete[] arr;
  delete[] dp;
  return 0;
}
