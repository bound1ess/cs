#include <iostream>
#include <string>

using namespace std;

class Stack {
  private:
    int* data;
    int max_size, pointer;

  public:
    class UnderflowException {};
    class OverflowException {};

    Stack(int max_size): max_size(max_size), pointer(0) {
      data = new int[max_size];
    }

    ~Stack() {
      delete [] data;
    }

    bool empty() const {
      return pointer == 0;
    }

    int pop() {
      if (empty()) {
        throw UnderflowException();
      }

      --pointer;
      return data[pointer];
    }

    int top() {
      if (empty()) {
        throw UnderflowException();
      }

      return data[pointer - 1];
    }

    void push(int value) {
      if (pointer == max_size) {
        throw OverflowException();
      }

      data[pointer] = value;
      ++pointer;
    }
};

int main() {
  Stack stack(20);
  string query;

  while (true) {
    cin >> query;

    if (query == "exit") {
      break;
    }

    if (query == "top") {
      try {
        cout << "Top value: " << stack.top() << endl;
      } catch (Stack::UnderflowException exception) {
        cout << "Stack is empty :(" << endl;
      }

      continue;
    }

    if (query == "empty") {
      if (stack.empty()) {
        cout << "Stack is empty." << endl;
      } else {
        cout << "Stack is NOT empty." << endl;
      }

      continue;
    }

    if (query == "pop") {
      try {
        stack.pop();
        cout << "Element was removed." << endl;
      } catch (Stack::UnderflowException exception) {
        cout << "Stack is empty :(" << endl;
      }

      continue;
    }

    if (query == "push") {
      int value;
      cin >> value;

      try {
        stack.push(value);
        cout << "Done!" << endl;
      } catch (Stack::OverflowException exception) {
        cout << "Can't push :(" << endl;
      }

      continue;
    }

    cout << "Unrecognized command." << endl;
  }

  return 0;
}
