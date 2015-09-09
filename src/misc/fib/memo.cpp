#include <cstdio>
#include <map>

std::map<int, int> memo;

int fib(int n) {
  if (memo.count(n) == 1) return memo[n];
  return memo[n] = n <= 2 ? 1 : fib(n - 1) + fib(n - 2);
}

int main() {
  int n;
  scanf("%d", &n);
  printf("%d\n", fib(n));
  return 0;
}
