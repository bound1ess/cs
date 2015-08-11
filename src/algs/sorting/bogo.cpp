#include <cstdio>
#include <algorithm>
#include <random>

using namespace std;

random_device device;
mt19937 engine(device());

inline int random_int(int floor, int ceiling) {
  uniform_int_distribution<int> distrib(floor, ceiling);
  return distrib(engine);
}

inline bool is_sorted(int arr[], int l, int r) {
  for (int i = l; i < r; ++i) {
    if (arr[i] > arr[i + 1]) {
      return false;
    }
  }

  return true;
}

inline void shuffle(int arr[], int l, int r) {
  for (int i = r; i > l; --i) {
    int j = random_int(l, i);
    swap(arr[i], arr[j]);
  }
}

inline void bogo_sort(int arr[], int l, int r) {
  int trials = random_int(10, 100);
  bool sorted = false;

  for (int i = 0; i < trials; ++i) {
    if (is_sorted(arr, l, r)) {
      sorted = true;
      break;
    }

    shuffle(arr, l, r);
  }

  if (sorted) {
    printf("You got lucky.\n");
  } else {
    printf("After %d attempts, I gave up. Best effort:\n", trials);
  }
}

int main() {
  int n; scanf("%d", &n);
  int* arr = new int[n];

  for (int i = 0; i < n; ++i) {
    scanf("%d", arr + i);
  }

  bogo_sort(arr, 0, n - 1);

  for (int i = 0; i < n - 1; ++i) {
    printf("%d ", arr[i]);
  }

  printf("%d\n", arr[n - 1]);
  delete[] arr;
  return 0;
}
