#include <cstdio>
#include <algorithm>

using namespace std;

inline void bubble_sort(int arr[], int l, int r);

int main() {
  int n; scanf("%d", &n);
  int* arr = new int[n];

  for (int i = 0; i < n; ++i) {
    scanf("%d", arr + i);
  }

  bubble_sort(arr, 0, n - 1);

  for (int i = 0; i < n; ++i) {
    printf("%d", arr[i]);
    printf(i + 1 < n ? " " : "\n");
  }

  delete[] arr;
  return 0;
}

inline void bubble_sort(int arr[], int l, int r) {
  bool keep = true;

  while (keep) {
    keep = false;

    for (int i = l; i < r; ++i) {
      if (arr[i] > arr[i + 1]) {
        swap(arr[i], arr[i + 1]);
        keep = true;
      }
    }

    --r;
  }
}
