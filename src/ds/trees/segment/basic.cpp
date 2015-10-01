#include <cstdio>
#include <cassert>
#include <cmath>

inline int midpoint(int low, int high) {
  return (low + high) / 2;
}

inline int left_child(int parent) {
  return (2 * parent) + 1;
}

inline int right_child(int parent) {
  return (2 * parent) + 2;
}

int build(int *arr, int seg_low, int seg_high, int *tree, int elem) {
  if (seg_low == seg_high) {
    tree[elem] = arr[seg_low];
    return tree[elem];
  }
  int mid = midpoint(seg_low, seg_high);
  tree[elem] = build(arr, seg_low, mid, tree, left_child(elem));
  tree[elem] += build(arr, mid + 1, seg_high, tree, right_child(elem));
  return tree[elem];
}

inline int* build(int *arr, int n) {
  int *tree = new int[2 * (int) pow(2, ceil(log2(n))) - 1];
  build(arr, 0, n - 1, tree, 0);
  return tree;
}

int sum(int *tree, int seg_low, int seg_high, int query_low, int query_high, int elem) {
  if (query_low <= seg_low && query_high >= seg_high) {
    return tree[elem];
  }
  if (query_low > seg_high || seg_low > query_high) {
    return 0;
  }
  int mid = midpoint(seg_low, seg_high);
  int answer = sum(tree, seg_low, mid, query_low, query_high, left_child(elem));
  return answer + sum(tree, mid + 1, seg_high, query_low, query_high, right_child(elem));
}

inline int sum(int *tree, int n, int query_low, int query_high) {
  assert(query_low >= 0 && query_high < n && query_low <= query_high);
  return sum(tree, 0, n - 1, query_low, query_high, 0);
}

int main() {
  int n, low, high;
  scanf("%d", &n);
  assert(n > 0);
  int *arr = new int[n];
  for (int i = 0; i < n; ++i) {
    scanf("%d", arr + i);
  }
  int *tree = build(arr, n);
  while (scanf("%d%d", &low, &high) != 0) {
    printf("The answer is %d\n", sum(tree, n, low, high));
  }
  delete[] arr;
  delete[] tree;
  return 0;
}
