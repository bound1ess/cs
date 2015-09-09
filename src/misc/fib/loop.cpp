#include <cstdio>

inline int fib(int n) {
  if (n <= 2) {
    return 1;
  }

  int a = 1, b = 1, c;

  for (int i = 3; i <= n; ++i) {
    c = a + b;
    a = b, b = c;
  }

  return b;
}

int main() {
  int n;
  scanf("%d", &n);
  printf("%d\n", fib(n));
  return 0;
}
