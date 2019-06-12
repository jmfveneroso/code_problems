// =====================================================
// Book: Elements of programming interviews
// Problem 5.2: Bit Swap
// =====================================================

#include <iostream>
#include <vector>

using namespace std;

unsigned long bit_swap1(unsigned long x, int i, int j) {
  if (i < 0 || i > 63 || j < 0 || j > 63) return 0;
  if (i == j) return x;

  unsigned long mask1 = 0x1 << i;
  unsigned long mask2 = 0x1 << j;
 
  bool bit1 = x & mask1;
  bool bit2 = x & mask2;

  x = (x & ~mask1) & ~mask2;
  if (bit1) x = x | mask2;
  if (bit2) x = x | mask1;

  return x;
}

unsigned long bit_swap2(unsigned long x, int i, int j) {
  if (i < 0 || i > 63 || j < 0 || j > 63) return 0;
  unsigned long ith_bit = (x >> i) & 1;
  unsigned long jth_bit = (x >> j) & 1;
  if (ith_bit != jth_bit) x ^= (1 << i) | (1 << j);
  return x;
}

int main() {
  vector<int> index_i { 0, 0, 2, 0 };
  vector<int> index_j { 4, 1, 3, 1 };
  vector<unsigned long> numbers { 0xff, 0x01, 0x09, 0x0e };
  vector<unsigned long> expected { 0xff, 0x2, 0x5, 0x0d };
  for (int i = 0; i < numbers.size(); i++) {
    cout << "Original: " << numbers[i] << endl;
    cout << "Swapped 1: " << bit_swap1(numbers[i], index_i[i], index_j[i]) << endl;
    cout << "Swapped 2: " << bit_swap2(numbers[i], index_i[i], index_j[i]) << endl;
    cout << "Expected: " << expected[i] << endl << endl;
  }
  return 0;
}
