#include <cstdio>
#include <cassert>

int main() {
  // prepare an empty array of length n
  int n;
  scanf("%d", &n);
  assert(0 < n);
  int *a = new int[n];
  assert(nullptr != a);
  for (int i = 0; i < n; ++i) {
    a[i] = 0;
  }

  // update the array
  int m;
  scanf("%d", &m);
  assert(0 < m);
  for (int i = 0; i < m; ++i) {
    int l, r;
    scanf("%d%d", &l, &r);
    --l, --r;
    assert(0 <= l && l < n);
    assert(0 <= r && r < n);
    assert(l <= r);
    for (int j = l; j <= r; ++j) {
      ++a[j];
    }
  }

  // print final state
  for (int i = 0; i < n; ++i) {
    if (0 < i) {
      putchar(' ');
    }
    printf("%d", a[i]);
  }
  putchar('\n');

  // handle user queries
  int k;
  scanf("%d", &k);
  assert(0 < k);
  for (int i = 0; i < k; ++i) {
    int pos;
    scanf("%d", &pos);
    --pos;
    assert(0 <= pos && pos < n);
    printf("%d\n", a[pos]);
  }

  // don't forget to free the allocated memory
  delete [] a;
  return 0;
}
