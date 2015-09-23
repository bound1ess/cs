#include <iostream>
#include <string>

using namespace std;

inline int min(int a, int b) {
  return a < b ? a : b;
}

inline int min(int a, int b, int c) {
  return min(a, min(b, c));
}

int main() {
  // init
  string a, b;
  cin >> a >> b;
  int m = a.length(), n = b.length();
  int **dp = new int*[m + 1];
  // fill in values
  for (int i = 0; i <= m; ++i) {
    dp[i] = new int[n + 1];
  }
  for (int i = 0; i <= m; ++i) {
    dp[i][0] = i;
  }
  for (int i = 0; i <= n; ++i) {
    dp[0][i] = i;
  }
  // solve
  for (int j = 1; j <= n; ++j) {
    for (int i = 1; i <= m; ++i) {
      if (a[i - 1] == b[j - 1]) { // skip
        dp[i][j] = dp[i - 1][j - 1];
        continue;
      }
      dp[i][j] = min(
        dp[i - 1][j] + 1, // deletion
        dp[i][j - 1] + 1, // insertion
        dp[i - 1][j - 1] + 1 // replace
      );
    }
  }
  // answer
  printf("%d\n", dp[m][n]);
  // clear
  for (int i = 0; i <= m; ++i) {
    delete[] dp[i];
  }
  delete[] dp;
  return 0;
}
