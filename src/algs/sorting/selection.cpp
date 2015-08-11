#include <cstdio>
#include <algorithm>

using namespace std;

inline void selection_sort(int arr[], int l, int r);

int main() {
  int n; scanf("%d", &n);
  int* arr = new int[n];

  for (int i = 0; i < n; ++i) {
    scanf("%d", arr + i);
  }

  selection_sort(arr, 0, n - 1);

  for (int i = 0; i < n - 1; ++i) {
    printf("%d ", arr[i]);
  }

  printf("%d\n", arr[n - 1]);
  delete[] arr;
  return 0;
}

inline void selection_sort(int arr[], int l, int r) {
  for (int i = l; i < r; ++i) {
    int smallest_index = i;

    for (int j = i + 1; j <= r; ++j) {
      if (arr[j] < arr[smallest_index]) {
        smallest_index = j;
      }
    }

    if (i != smallest_index) {
      swap(arr[i], arr[smallest_index]);
    }
  }
}
