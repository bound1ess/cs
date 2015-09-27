#include <cstdio>
#include <cassert>

int main() {
  int n;
  scanf("%d", &n);
  assert(n > 0);
  printf("%d\n", n | (n - 1));
  return 0;
}
