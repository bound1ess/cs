#include <cstdio>
#include <algorithm>

using namespace std;

inline void restore_heap(int heap[], int n);
inline void heap_sort(int arr[], int l, int r);

int main() {
  int n;
  scanf("%d", &n);

  int* arr = new int[n];

  for (int i = 0; i < n; ++i) {
    scanf("%d", arr + i);
  }

  heap_sort(arr, 0, n - 1);

  for (int i = 0; i < n - 1; ++i) {
    printf("%d ", arr[i]);
  }

  printf("%d\n", arr[n - 1]);
  delete[] arr;
  return 0;
}

inline void heap_sort(int arr[], int l, int r) {
  int n = r - l + 1;
  int* heap = new int[n];

  for (int i = l, j = 0; i <= r; ++i, ++j) {
    heap[j] = arr[i];
  }

  for (int i = l, j = n - 1; i <= r; ++i, --j) {
    restore_heap(heap, j + 1);
    arr[l + j] = heap[0];
    swap(heap[0], heap[j]);
  }

  delete[] heap;
}

inline void restore_heap(int heap[], int n) {
  for (int i = n / 2; i >= 0; --i) {
    int l = i * 2 + 1, r = i * 2 + 2;

    if (l < n && heap[i] < heap[l]) {
      swap(heap[i], heap[l]);
    }

    if (r < n && heap[i] < heap[r]) {
      swap(heap[i], heap[r]);
    }
  }
}
