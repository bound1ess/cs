#include <iostream>
#include <vector>

using namespace std;

vector<int> find_primes(int lower, int upper) {
  vector<bool> sieve(upper + 1, true);
  vector<int> primes;
  for (int i = lower; i * i <= upper; ++i) {
    if (sieve[i]) {
      for (int j = i * i; j <= upper; j += i) {
        sieve[j] = false;
      }
    }
  }
  for (int i = lower; i <= upper; ++i) {
    if (sieve[i]) {
      primes.push_back(i);
    }
  }
  return primes;
}

int main() {
  int limit;
  cin >> limit;
  vector<int> primes = find_primes(2, limit);
  for (int prime: primes) {
    cout << prime << endl;
  }
  return 0;
}
