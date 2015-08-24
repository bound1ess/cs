#include <cstdio>

inline int binpow(int base, int exp) {
  int ans = 1;

  while (exp) {
    if (exp & 1) { // check if odd
      ans *= base;
    }

    base *= base;
    exp >>= 1; // divide by 2
  }

  return ans;
}

int main() {
  int base, exp;
  scanf("%d%d", &base, &exp);

  printf("%d\n", binpow(base, exp));
  return 0;
}
