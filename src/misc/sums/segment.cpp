#include <cstdio>
#include <cassert>

inline int getSum(int l, int r, const int *arr) {
  return arr[r] - (0 < l ? arr[l - 1] : 0);
}

int main() {
  int n, k;
  scanf("%d%d", &n, &k);
  assert(0 < n && 0 < k && k <= n);
  int *arr = new int[n];
  assert(nullptr != arr);
  for (int i = 0; i < n; ++i) {
    scanf("%d", arr + i);
  }
  for (int i = 1; i < n; ++i) {
    arr[i] += arr[i - 1];
  }
  int minLeft = 0, minRight = k - 1, maxLeft = 0, maxRight = k - 1;
  for (int i = 0; i < n - k + 1; ++i) {
    int l = i, r = i + k - 1;
    int sum = getSum(l, r, arr);
    if (getSum(minLeft, minRight, arr) > sum) {
      minLeft = l, minRight = r;
    }
    if (getSum(maxLeft, maxRight, arr) < sum) {
      maxLeft = l, maxRight = r;
    }
  }
  printf("min [%d, %d], sum = %d\n", minLeft, minRight, getSum(minLeft, minRight, arr));
  printf("max [%d, %d], sum = %d\n", maxLeft, maxRight, getSum(maxLeft, maxRight, arr));
  delete [] arr;
  return 0;
}
