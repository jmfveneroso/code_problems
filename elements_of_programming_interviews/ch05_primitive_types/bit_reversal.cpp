// =====================================================
// Book: Elements of programming interviews
// Problem 5.3: Bit reversal.
// =====================================================

#include <iostream>
#include <vector>

using namespace std;

// Reverts bits by swapping the right and left bits starting from
// the edges. O(n) time complexity.
unsigned long bit_reversal1(unsigned long x) {
  unsigned long result = 0;
  for (int i = 0; i < 32; i++) {
    unsigned long lft = (x >> (63-i)) & 1;
    unsigned long rgt = (x >> i) & 1;
    result |= lft << i; 
    result |= rgt << (63-i);
  }
  return result;
}

// Removes the rightmost bit from the number and inserts it into a 
// new number shifting the content from the right to left. 
// O(n) time complexity.
unsigned long bit_reversal2(unsigned long x) {
  unsigned long result = 0;
  for (int i = 0; i < 64; i++)
    result = (result << 1) | ((x >> i) & 1);
  return result;
}

int main() {
  unsigned long x = (unsigned long) 1 << 63;
  vector<unsigned long> numbers { x };
  vector<unsigned long> expected { 1 };

  for (int i = 0; i < numbers.size(); i++) {
    cout << "Reversed: " << bit_reversal1(numbers[i]) << endl;
    cout << "Reversed: " << bit_reversal2(numbers[i]) << endl;
    cout << "Expected: " << expected[i] << endl << endl;
  }
  return 0;
}
