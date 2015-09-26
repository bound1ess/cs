#include <cstdio>
#include <cassert>

void check(int n, int bit) {
  if ((1 << bit) > n) return;
  check(n, bit + 1);
  printf("%d", n & (1 << bit) ? 1 : 0);
}

int main() {
  int n;
  scanf("%d", &n);
  assert(n > 0);
  check(n, 0);
  printf("\n");
  return 0;
}
