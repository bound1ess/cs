#include <cstdio>
#include <random>

using namespace std;

const int RANGE = 10, SIZE = 30;
int arr[SIZE], buckets[RANGE];

inline void counting_sort();

int main() {
  random_device device;
  mt19937 engine(device());
  uniform_int_distribution<int> dist(0, RANGE - 1);

  for (int i = 0; i < SIZE; ++i) {
    arr[i] = dist(engine);
  }

  counting_sort();

  for (int i = 0; i < SIZE - 1; ++i) {
    printf("%d ", arr[i]);
  }

  printf("%d\n", arr[SIZE - 1]);
  return 0;
}

inline void counting_sort() {
  for (int i = 0; i < SIZE; ++i) {
    ++buckets[arr[i]];
  }

  for (int i = 0, j = 0; i < RANGE; ++i) {
    for (int k = 0; k < buckets[i]; ++k) {
      arr[j] = i;
      ++j;
    }
  }
}
