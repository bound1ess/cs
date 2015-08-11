#include <cstdio>

inline bool find(int arr[], int val, int l, int r) {
  for (int i = l; i <= r; ++i) {
    if (arr[i] == val) {
      return true;
    }
  }

  return false;
}

int main() {
  int n; scanf("%d", &n);
  int* arr = new int[n];

  for (int i = 0; i < n; ++i) {
    scanf("%d", arr + i);
  }

  int x; scanf("%d", &x);

  if (find(arr, x, 0, n - 1)) {
    printf("Got it!\n");
  } else {
    printf("No such element.\n");
  }

  delete[] arr;
  return 0;
}
