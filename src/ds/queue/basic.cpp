#include <cstdio>
#include <cassert>
#include <vector>

using namespace std;

template<class T>
class Node {
  public:
    T value;
    Node<T> *next;
    Node(T value): value(value), next(nullptr) {}
};

template<class T>
class BasicQueue {
  private:
    Node<T> *root;
  public:
    BasicQueue();
    ~BasicQueue();
    void push(T value);
    T front();
    void pop();
};

int main() {
  int n, x;
  scanf("%d", &n);
  assert(n > 0);
  BasicQueue<int> queue;
  for (int i = 0; i < n; ++i) {
    scanf("%d", &x);
    queue.push(x);
  }
  for (int i = 0; i < n; ++i) {
    printf("Next element is %d\n", queue.front());
    queue.pop();
  }
  return 0;
}

template<class T>
BasicQueue<T>::BasicQueue() {
  this->root = nullptr;
}

template<class T>
BasicQueue<T>::~BasicQueue() {
  Node<T> *current = this->root;
  while (current != nullptr) {
    Node<T> *copy = current->next;
    delete current;
    current = copy;
  }
}

template<class T>
void BasicQueue<T>::push(T value) {
  if (this->root == nullptr) {
    this->root = new Node<T>(value);
  } else {
    Node<T> *tail = this->root;
    while (tail->next != nullptr) {
      tail = tail->next;
    }
    tail->next = new Node<T>(value);
  }
}

template<class T>
T BasicQueue<T>::front() {
  assert(this->root != nullptr);
  return this->root->value;
}

template<class T>
void BasicQueue<T>::pop() {
  assert(this->root != nullptr);
  Node<T> *last_root = this->root;
  this->root = this->root->next;
  delete last_root;
}
