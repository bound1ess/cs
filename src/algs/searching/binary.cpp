#include <cstdio>
#include <algorithm>

using namespace std;

inline bool find(int arr[], int val, int l, int r);

int main() {
  int n; scanf("%d", &n);
  int* arr = new int[n];

  for (int i = 0; i < n; ++i) {
    scanf("%d", arr + i);
  }

  sort(arr, arr + n);

  int x; scanf("%d", &x);

  if (find(arr, x, 0, n - 1)) {
    printf("Got it!\n");
  } else {
    printf("No such element.\n");
  }

  delete[] arr;
  return 0;
}

inline bool find(int arr[], int val, int l, int r) {
  while (l <= r) {
    int mid = (l + r) / 2;

    if (arr[mid] == val) {
      return true;
    } else if (arr[mid] < val) {
      l = mid + 1;
    } else {
      r = mid - 1;
    }
  }

  return false;
}
