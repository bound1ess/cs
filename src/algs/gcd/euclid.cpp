#include <cstdio>

int gcd(int a, int b) {
  return b == 0 ? a : gcd(b, a % b);
}

// bonus!
inline int lcm(int a, int b) {
  return (a * b) / gcd(a, b);
}

int main() {
  int a, b;
  scanf("%d%d", &a, &b);

  printf("GCD: %d, LCM: %d\n", gcd(a, b), lcm(a, b));
  return 0;
}
