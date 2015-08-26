#include <cstdio>

// might want to use long long instead
inline int pow(int base, int exp, int mod) {
  int answer = 1;

  while (exp > 0) {
    if (exp % 2 == 1) {
      answer = (answer * 1ll * base) % mod;
    }

    base = (base * 1ll * base) % mod;
    exp >>= 1; // exp /= 2;
  }

  return answer % mod;
}

int main() {
  int base, exp, mod;
  scanf("%d%d%d", &base, &exp, &mod);

  printf("%d\n", pow(base, exp, mod));
  return 0;
}
