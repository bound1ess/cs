#include <cstdio>
#include <algorithm>

using namespace std;

inline void insertion_sort(int arr[], int l, int r);

int main() {
  int n; scanf("%d", &n);
  int* arr = new int[n];

  for (int i = 0; i < n; ++i) {
    scanf("%d", arr + i);
  }

  insertion_sort(arr, 0, n - 1);

  for (int i = 0; i < n - 1; ++i) {
    printf("%d ", arr[i]);
  }

  printf("%d\n", arr[n - 1]);
  delete[] arr;
  return 0;
}

inline void insertion_sort(int arr[], int l, int r) {
  for (int i = l + 1; i <= r; ++i) {
    int j = i;

    while (j > l && arr[j - 1] > arr[j]) {
      swap(arr[j], arr[j - 1]);
      --j;
    }
  }
}
