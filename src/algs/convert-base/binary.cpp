#include <cstdio>
#include <cassert>

const int N = 8;
bool bits[N];

inline int pow(int exp, int base = 2) {
  int result = 1;

  for (int i = 0; i < exp; ++i) {
    result *= base;
  }

  return result;
}

int main() {
  int n;
  scanf("%d", &n);
  assert(n >= 0 && n < 256);

  while (n > 0) {
    for (int i = 0; i < N; ++i) {
      if ( ! bits[i] && pow(N - i - 1) <= n) {
        bits[i] = true;
        n -= pow(N - i - 1);
      }
    }
  }

  for (int i = 0; i < N; ++i) {
    printf("%d", (int) bits[i]);
  }

  printf("\n");
  return 0;
}
