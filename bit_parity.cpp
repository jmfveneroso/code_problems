// =====================================================
// Book: Elements of programming interviews
// Problem 5.1: Computing Parity
// =====================================================

#include <iostream>
#include <vector>

using namespace std;

// Naive parity function. Checks the rightmost bit and
// shifts right by one bit, keeping track of the parity
// status. O(n) complexity.
bool parity1(unsigned long x) {
  bool parity = 0;
  short num_bits= sizeof(unsigned long) * 8;
  for (int i = 0; i < num_bits; i++) {
    if (x & 0x1) parity ^= 1;
    x >>= 1;
  }
  return parity;
}

// Log parity. Uses the XOR operator splitting the number
// in half on each iteration. The unmatched 1-bits are gonna
// be left untouched. After log(n) iterations the rightmost
// bit will contain the parity status. O(log(n)) complexity.
bool parity2(unsigned long x) {
  short bit_shift = sizeof(unsigned long) * 8;
  while (bit_shift > 1) {
    bit_shift = bit_shift >> 1;
    x ^= (x >> bit_shift);
  }
  return x & 0x1;
}

// One parity. Only matches 1-bits. On each iteration, the 
// first 1-bit starting from the left is removed and the 
// parity status changes. On the best case, the algorithm takes 
// one iteration. On the worst case it takes n iterations.
// O(n) complexity.
bool parity3(unsigned long x) {
  bool parity = 0;
  while (x) {
    parity ^= 1;
    x &= (x - 1);
  }
  return parity;
}

int main() {
  vector<unsigned long> numbers { 
    0xf0000000, 0xe0000000, 0xe0000000, 0x00000000 
  };

  vector<bool> expected { 
    0, 1, 1, 0
  };

  for (int i = 0; i < numbers.size(); i++) {
    cout << "Parity 1: " << parity1(numbers[i]) << endl;
    cout << "Parity 2: " << parity2(numbers[i]) << endl;
    cout << "Parity 3: " << parity3(numbers[i]) << endl;
    cout << "Expected: " << expected[i] << endl << endl;
  }
  return 0;
}
