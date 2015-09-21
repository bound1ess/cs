#include <cstdio>
#include <cassert>

void generate(int n, int *set, int at, bool *stack) {
  if (at == n) {
    bool empty = true;
    for (int i = 0; i < n; ++i) {
      if (stack[i]) {
        empty = false;
        break;
      }
    }
    if (empty) {
      puts("this subset is empty");
      return;
    }
    for (int i = 0; i < n; ++i) {
      if (stack[i]) {
        printf("%d ", set[i]);
      }
    }
    puts("");
  } else {
    stack[at] = true;
    generate(n, set, at + 1, stack);
    stack[at] = false;
    generate(n, set, at + 1, stack);
  }
}

int main() {
  int n;
  scanf("%d", &n);
  assert(n > 0);
  int *set = new int[n];
  bool *stack = new bool[n];
  for (int i = 0; i < n; ++i) {
    scanf("%d", set + i);
    stack[i] = false;
  }
  printf("subsets: %d\n", 1 << n);
  generate(n, set, 0, stack);
  delete[] set;
  delete[] stack;
  return 0;
}
