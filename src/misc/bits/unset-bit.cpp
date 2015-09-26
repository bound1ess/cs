#include <cstdio>

int main() {
  int a, b;
  scanf("%d%d", &a, &b);
  for (int i = 0; (1 << i) <= a; ++i) {
    if ((1 << i) & a) {
      b &= ~(1 << i);
    }
  }
  printf("%d\n", b);
  return 0;
}
