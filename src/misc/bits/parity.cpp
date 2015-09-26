#include <cstdio>

int main() {
  int n;
  scanf("%d", &n);
  puts(n & 1 ? "Odd" : "Even");
  return 0;
}
