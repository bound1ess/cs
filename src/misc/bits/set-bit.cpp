#include <cstdio>
#include <cassert>

inline int copy(int n) {
  int m = 0;
  for (int i = 1; i <= n; i <<= 1) {
    if (n & i) {
      m |= i;
    }
  }
  return m;
}

int main() {
  int n;
  scanf("%d", &n);
  assert(n >= 0);
  printf("%d\n", copy(n));
  return 0;
}
