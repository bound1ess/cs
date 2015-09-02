#include <iostream>
#include <string>
#include <stack>

using namespace std;

const char digits[] = {
  '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F',
};

int main() {
  int num, base;
  string answer;
  stack<char> tmp;
  cin >> num >> base;

  while (num > 0) {
    tmp.push(digits[num % base]);
    num /= base;
  }

  while ( ! tmp.empty()) {
    answer += tmp.top();
    tmp.pop();
  }

  cout << answer << endl;
  return 0;
}
