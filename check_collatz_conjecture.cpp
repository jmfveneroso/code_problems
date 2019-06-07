// =====================================================
// Book: Elements of programming interviews
// Problem 17.12: Checking the Collatz conjecture
// =====================================================

#include <iostream>
#include <unordered_set>

using namespace std;

// The Collatz conjecture has still not been proven wrong.
// So this function should probably never return false for
// any n. The number of steps is unbounded since there may
// be an n for which there is no convergence.
bool check_collatz(unsigned long n) {
  unordered_set<unsigned long> converging_nums;
  for (unsigned int i = 2; i < n; i++) {
    unsigned long tmp = i;

    unordered_set<unsigned long> sequence;
    while (tmp != 1 && tmp >= i) {
      if (converging_nums.find(tmp) != converging_nums.end()) break;
      if (!sequence.insert(tmp).second) return false;

      if (tmp & 1) { // Odd.
        unsigned long next = 3 * tmp + 1;
        if (next <= tmp)
          throw overflow_error("Test overflow.");
        tmp = 3*tmp+1;
      } else { // Even.
        tmp = tmp >> 1;
      }
    }
    converging_nums.insert(i);
  } 

  return true;
}

int main() {
  cout << check_collatz(12) << " should be true." << endl;
  cout << check_collatz(27) << " should be true." << endl;
  cout << check_collatz(1422) << " should be true." << endl;
  cout << check_collatz(900000) << " should be true." << endl;
  cout << check_collatz(414241) << " should be true." << endl;
  return 0;
}
