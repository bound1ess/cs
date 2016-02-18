#include <cstdio>
#include <cassert>

int main() {
  // create an empty array of size n + 1
  int n;
  scanf("%d", &n);
  assert(0 < n);
  int *a = new int[n + 1];
  assert(nullptr != a);
  for (int i = 0; i < n; ++i) {
    a[i] = 0;
  }

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
    // this is the key concept
    ++a[l], --a[r + 1];
  }

  // restore missing values
  for (int i = 1; i < n; ++i) {
    a[i] += a[i - 1];
  }

  // print out the array
  for (int i = 0; i < n; ++i) {
    if (0 < i) {
      putchar(' ');
    }
    printf("%d", a[i]);
  }
  putchar('\n');

  // free the allocated memory
  delete [] a;
  return 0;
}
