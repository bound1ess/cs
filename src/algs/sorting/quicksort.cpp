#include <cstdio>
#include <algorithm>

using namespace std;

void quicksort(int arr[], int l, int r);

int main() {
  int n;
  scanf("%d", &n);

  int* arr = new int[n];

  for (int i = 0; i < n; ++i) {
    scanf("%d", arr + i);
  }

  quicksort(arr, 0, n - 1);

  for (int i = 0; i < n - 1; ++i) {
    printf("%d ", arr[i]);
  }

  printf("%d\n", arr[n - 1]);
  delete[] arr;
  return 0;
}

void quicksort(int arr[], int l, int r) {
  int i = l, j = r, pivot = arr[(l + r) / 2];

  while (i <= j) {
    while (arr[i] < pivot) {
      ++i;
    }

    while (arr[j] > pivot) {
      --j;
    }

    if (i <= j) {
      swap(arr[i], arr[j]);
      ++i, --j;
    }
  }

  if (i < r) {
    quicksort(arr, i, r);
  }

  if (l < j) {
    quicksort(arr, l, j);
  }
}
