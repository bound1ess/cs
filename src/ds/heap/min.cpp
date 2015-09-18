#include <cstdio>
#include <algorithm>
#include <cassert>

using namespace std;

class MinHeap {
  private:
    int *heap, size;
    bool dirty;
    void restore();
  public:
    MinHeap(int *heap, int size);
    ~MinHeap();
    int extract();
};

int main() {
  int n;
  scanf("%d", &n);
  assert(n > 0);
  int *arr = new int[n];
  for (int i = 0; i < n; ++i) {
    scanf("%d", arr + i);
  }
  MinHeap heap(arr, n);
  for (int i = 0; i < n; ++i) {
    printf("%d\n", heap.extract());
  }
  delete[] arr;
  return 0;
}

MinHeap::MinHeap(int *heap, int size) {
  this->size = size;
  this->dirty = true;
  this->heap = new int[size];
  for (int i = 0; i < size; ++i) {
    this->heap[i] = heap[i];
  }
}

MinHeap::~MinHeap() {
  delete[] this->heap;
}

int MinHeap::extract() {
  assert(this->size > 0);
  this->restore();
  this->dirty = true;
  swap(this->heap[0], this->heap[this->size - 1]);
  --this->size;
  return this->heap[this->size];
}

void MinHeap::restore() {
  if (this->dirty) {
    this->dirty = false;
    for (int i = this->size / 2; i >= 0; --i) {
      int left = i * 2 + 1, right = i * 2 + 2;
      if (left < this->size && this->heap[i] > this->heap[left]) {
        swap(this->heap[i], this->heap[left]);
      }
      if (right < this->size && this->heap[i] > this->heap[right]) {
        swap(this->heap[i], this->heap[right]);
      }
    }
  }
}
