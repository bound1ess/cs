#include <cstdio>
#include <random>

using namespace std;

random_device device;
mt19937 engine(device());

inline int mod_pow(int base, int exp, int mod) {
  int ans = 1;

  while (exp) {
    if (exp & 1) {
      ans = (ans * base) % mod;
    }

    base = (base * base) % mod;
    exp >>= 1;
  }

  return ans % mod;
}

inline bool miller_rabin(int n, int attempts = 20) {
  if (n == 2) {
    return true;
  }

  if (n < 2 || n % 2 == 0) {
    return false;
  }

  int d = n - 1, s = 0;

  while (d % 2 == 0) {
    d >>= 1, ++s;
  }

  uniform_int_distribution<int> dist(2, n - 1);

  for (int i = 0; i < attempts; ++i) {
    outer:
    int mod = mod_pow(dist(engine), d, n);

    if (mod == 1 || mod == n - 1) {
      continue;
    }

    for (int j = 0; j < s - 1; ++j) {
      mod = (mod * mod) % n;

      if (mod == 1) {
        return false;
      }

      if (mod == n - 1) {
        ++i;
        goto outer;
      }
    }

    return false;
  }

  return true;
}

int main() {
  int n;
  scanf("%d", &n);

  printf(miller_rabin(n) ? "Probably prime.\n" : "Not prime.\n");
  return 0;
}
