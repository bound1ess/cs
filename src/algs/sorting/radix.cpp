#include <cstdio>

inline int find_max_value(int arr[], int n) {
  int max = arr[0];
  for (int i = 1; i < n; ++i) {
    if (arr[i] > max) {
      max = arr[i];
    }
  }
  return max;
}

inline void counting_sort(int arr[], int n, int exp) {
  int* out = new int[n];
  int count[10];

  for (int i = 0; i < 10; ++i) {
    count[i] = 0;
  }

  for (int i = 0; i < n; ++i) {
    ++count[(arr[i] / exp) % 10];
  }

  for (int i = 1; i < 10; ++i) {
    count[i] += count[i - 1];
  }

  for (int i = n - 1; i >= 0; --i) {
    int bucket = (arr[i] / exp) % 10;
    out[count[bucket] - 1] = arr[i];
    --count[bucket];
  }

  for (int i = 0; i < n; ++i) {
    arr[i] = out[i];
  }

  delete[] out;
}

inline void radix_sort(int arr[], int n) {
  int max = find_max_value(arr, n);
  for (int exp = 1; max / exp > 0; exp *= 10) {
    counting_sort(arr, n, exp);
  }
}

int main() {
  int n; scanf("%d", &n);
  int* arr = new int[n];

  for (int i = 0; i < n; ++i) {
    scanf("%d", arr + i);
  }

  radix_sort(arr, n);

  for (int i = 0; i < n - 1; ++i) {
    printf("%d ", arr[i]);
  }

  printf("%d\n", arr[n - 1]);
  delete[] arr;
  return 0;
}
