#include <cstdio>

class Node {
  public:
    int id;
    Node* next;
    Node(int id): id(id), next(NULL) {}
};

class List {
  private:
    Node* root;
  public:
    List(): root(NULL) {}

    void add(Node* node) {
      if (root == NULL) {
        root = node;
      } else {
        Node* last = root;
        while (last->next != NULL) {
          last = last->next;
        }
        last->next = node;
      }
    }

    bool has(int id) const {
      Node* current = root;
      while (current != NULL) {
        if (current->id == id) {
          return true;
        }
        current = current->next;
      }
      return false;
    }
};

const int N = 10;
List graph[N];

int main() {
  // add edges
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < N; ++j) {
      if (i + j == 11) {
        graph[i].add(new Node(j));
      }
    }
  }

  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < N; ++j) {
      if (graph[i].has(j)) {
        printf("%d => %d\n", i, j);
      }
    }
  }

  return 0;
}
