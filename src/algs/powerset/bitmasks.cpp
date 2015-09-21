#include <cstdio>
#include <cassert>

int main() {
  int n;
  scanf("%d", &n);
  assert(n > 0);
  int *set = new int[n];
  for (int i = 0; i < n; ++i) {
    scanf("%d", set + i);
  }
  printf("subsets: %d\n", 1 << n);
  for (int i = 0; i < (1 << n); ++i) {
    int mask = 0;
    for (int j = 0; j < n; ++j) {
      mask |= i & (1 << j);
    }
    if (mask) {
      for (int j = 0; j < n; ++j) {
        if (mask & (1 << j)) {
          printf("%d ", set[j]);
        }
      }
      printf("\n");
    } else {
      printf("this set is empty\n");
    }
  }
  delete[] set;
  return 0;
}
