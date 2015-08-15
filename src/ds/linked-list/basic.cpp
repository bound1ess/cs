#include <iostream>
#include <queue>
#include <string>

using namespace std;

class Node {
  public:
    string value;
    Node* prev;
    Node* next;
    Node(const string &value);
};

class LinkedList {
  private:
    Node* root;
  public:
    void add(Node* node);
    void dump() const;
    bool find(const string &value) const;
    LinkedList();
    ~LinkedList();
};

Node* create_node(const string &value) {
  return new Node(value);
}

int main() {
  LinkedList list;
  cout << "Appending new elements to the list (type 'stop' to finish)." << endl;
  while (true) { // bad idea
    string input;
    cin >> input;
    if (input == "stop") {
      break;
    }
    list.add(create_node(input));
  }
  list.dump();
  cout << "Performing linear search (exact match). Type 'exit' to finish." << endl;
  while (true) {
    string query;
    cin >> query;
    if (query == "exit") {
      break;
    }
    if (list.find(query)) {
      cout << "Found." << endl;
    } else {
      cout << "Not found." << endl;
    }
  }
  return 0;
}

Node::Node(const string &value): value(value), prev(NULL), next(NULL) {}

LinkedList::LinkedList(): root(NULL) {}

LinkedList::~LinkedList() {
  Node* curr = root;
  queue<Node*> ptrs;
  while (curr != NULL) {
    ptrs.push(curr);
    curr = curr->next;
  }
  while ( ! ptrs.empty()) {
    Node* ptr = ptrs.front();
    ptrs.pop();
    delete ptr;
  }
}

void LinkedList::add(Node* node) {
  if (root == NULL) {
    root = node;
  } else {
    Node* last = root;
    while (last->next != NULL) {
      last = last->next;
    }
    last->next = node;
    node->prev = last;
  }
}

void LinkedList::dump() const {
  Node* curr = root;
  cout << "====== Displaying the list ======" << endl;
  while (curr != NULL) {
    cout << curr->value;
    if (curr->prev != NULL) {
      cout << " (prev node value: " << curr->prev->value << ")";
    }
    cout << endl;
    curr = curr->next;
  }
}

bool LinkedList::find(const string &value) const {
  Node* curr = root;
  while (curr != NULL) {
    if (curr->value == value) {
      return true;
    }
    curr = curr->next;
  }
  return false;
}
