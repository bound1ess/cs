#include <cstdio>
#include <cassert>
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

inline bool fermat(int n, int trials = 20) {
  assert(n > 1);
  uniform_int_distribution<int> dist(1, n - 1);

  for (int i = 0; i < trials; ++i) {
    int j = dist(engine);
    assert(j >= 1 && j <= n - 1);

    if (mod_pow(j, n - 1, n) != 1) {
      return false;
    }
  }

  return true;
}

int main() {
  int n;
  scanf("%d", &n);

  printf(fermat(n) ? "Probably prime.\n" : "Not prime.\n");
  return 0;
}
