// =====================================================
// Book: Elements of programming interviews
// Problem 6.1: Dutch National Flag
// =====================================================

#include <iostream>
#include <vector>

using namespace std;

void print_array(const vector<int>& x) {
  for (const auto& xi : x) {
    cout << xi << ", ";
  }
  cout << endl;
}

// Sorts array such that all values < i are in the
// beginning of the array, all values == i are in 
// the middle and all values > i are in the end.
// Time complexity O(n). Space complexity O(1).
void dutch_national_flag(vector<int>& x, int i) {
  int j = 0;
  int k = x.size() - 1;
  while(true) {
    while (x[k] >= i) k--;
    while (x[j] < i) j++;

    if (j >= k) break;
    x[k] ^= x[j] ^= x[k] ^= x[j]; // Swap.
  }

  j = k + 1;
  k = x.size() - 1;
  while(true) {
    while (x[k] > i) k--;
    while (x[j] == i) j++;

    if (j >= k) break;
    x[k] ^= x[j] ^= x[k] ^= x[j]; // Swap.
  }
}

int main() {
  vector<int> x { 1, 2, 3, 2, 1, 2, 3 };

  print_array(x);
  dutch_national_flag(x, 2);
  print_array(x);
  cout << "Done." << endl;
  return 0;
}
