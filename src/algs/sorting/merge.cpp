#include <cstdio>

void merge_sort(int arr[], int l, int r);

int main() {
  int n; scanf("%d", &n);
  int* arr = new int[n];

  for (int i = 0; i < n; ++i) {
    scanf("%d", arr + i);
  }

  merge_sort(arr, 0, n - 1);

  for (int i = 0; i < n; ++i) {
    printf("%d", arr[i]);
    printf(i + 1 < n ? " " : "\n");
  }

  delete[] arr;
  return 0;
}

void merge_sort(int arr[], int l, int r) {
  if (l >= r) {
    return;
  }

  int m = (l + r) / 2;
  int i = l, j = m + 1, k = 0;

  merge_sort(arr, i, m);
  merge_sort(arr, j, r);

  int* aux = new int[r - l + 1];

  while (i <= m && j <= r) {
    if (arr[i] < arr[j]) {
      aux[k] = arr[i];
      ++i;
    } else {
      aux[k] = arr[j];
      ++j;
    }
    ++k;
  }

  while (i <= m) {
    aux[k] = arr[i];
    ++k, ++i;
  }

  while (j <= r) {
    aux[k] = arr[j];
    ++k, ++j;
  }

  while (k > 0) {
    arr[l + k - 1] = aux[k - 1];
    --k;
  }

  delete[] aux;
}
