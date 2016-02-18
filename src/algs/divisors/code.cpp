#include <cstdio>
#include <vector>
#include <cassert>
#include <algorithm>

using namespace std;

int main() {
  // read an integer
  int n;
  scanf("%d", &n);
  assert(0 <= n);

  // find this number's divisors
  vector <int> v;
  for (int i = 1; i * i <= n; ++i) {
    if (n % i == 0) {
      v.push_back(i);
      if (n / i != i) {
        v.push_back(n / i);
      }
    }
  }

  // let's sort (to make things prettier)
  sort(v.begin(), v.end());

  // print out the found divisors
  int len = int(v.size());
  for (int i = 0; i < len; ++i) {
    if (0 < i) {
      putchar(' ');
    }
    printf("%d", v[i]);
  }
  if (0 < len) {
    putchar('\n');
  } else {
    puts("No divisors");
  }
  return 0;
}
