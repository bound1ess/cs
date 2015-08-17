#include <cstdio>
#include <cassert>

inline void swap(int &x, int &y) {
  int z = x;
  x = y, y = z;
}

class MaxHeap {
  private:
    int* heap;
    int heap_size;
    bool damaged;

  public:
    MaxHeap(int* arr, int n): heap_size(n), damaged(true) {
      heap = new int[n];

      for (int i = 0; i < n; ++i) {
        heap[i] = arr[i];
      }
    }

    ~MaxHeap() {
      delete [] heap;
    }

    void restore() {
      if ( ! damaged) {
        //printf("heap is OK, skip\n");
        return;
      }

      damaged = false;

      for (int i = heap_size / 2; i >= 0; --i) {
        int left_child = i * 2 + 1, right_child = i * 2 + 2;

        if (left_child < heap_size && heap[i] < heap[left_child]) {
          swap(heap[i], heap[left_child]);
        }

        if (right_child < heap_size && heap[i] < heap[right_child]) {
          swap(heap[i], heap[right_child]);
        }
      }
    }

    int peek() {
      // what if the heap is empty?
      assert(heap_size > 0);

      restore();

      return heap[0];
    }

    void extract() {
      assert(heap_size > 0);

      restore();
      damaged = true;

      swap(heap[0], heap[heap_size - 1]);
      --heap_size;
    }
};

int main() {
  int n; scanf("%d", &n);
  int* arr = new int[n];

  for (int i = 0; i < n; ++i) {
    scanf("%d", arr + i);
  }

  MaxHeap heap(arr, n);

  for (int i = 0; i < n; ++i) {
    printf("%d\n", heap.peek());
    heap.extract();
  }

  delete [] arr;
  return 0;
}
