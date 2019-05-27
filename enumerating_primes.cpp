// =====================================================
// Book: Elements of programming interviews
// Problem 5.11: Enumerating primes.
// =====================================================

#include <iostream>
#include <vector>

using namespace std;

// Tests for each odd number between 3 and x, if the number is
// divisible by any prime found before it. A non-prime number
// must be divisible by a prime number smaller than it. Time
// complexity O(n^2).
void enumerate_primes1(int x) {
  vector<int> primes { 2 };
 
  for (int i = 3; i <= x; i += 2) {
    bool prime = true;
    for (auto p : primes) {
      if (i % p == 0) {
        prime = false;
        break;
      }
    }
    if (prime) cout << i << endl;
    primes.push_back(i);
  }
}

// Tests for each odd number between 3 and x, if the number is
// divisible by any odd number before it up to that number squared.
// If a number x is not divisible by any prime before y and y^2 > x,
// then it must be a prime. Because, otherwise there would exist a 
// numbers w, and z bigger than y such that w*z = x. But this
// is impossible. Time complexity O(n^2).
void enumerate_primes2(int x) {
  for (int i = 3; i <= x; i += 2) {
    bool prime = (i % 2 != 0);
    for (int j = 3; j*j <= i; j+=2) {
      if (i % j == 0) {
        prime = false;
        break;
      }
    }
    if (prime) cout << i << endl;
  }
}

int main() {
  vector<int> numbers { 8, 17, 50 };

  for (int i = 0; i < numbers.size(); i++) {
    enumerate_primes1(numbers[i]);
    cout << "===========" << endl;
    enumerate_primes2(numbers[i]);
    cout << "===========" << endl;
  }
  return 0;
}
