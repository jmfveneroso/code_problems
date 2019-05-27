// =====================================================
// Book: Elements of programming interviews
// Problem 6.3: Max Difference
// =====================================================

#include <iostream>
#include <vector>

using namespace std;

// Calculates the maximum difference in an array. O(n).
int max_difference(std::vector<int> x) {
  int min = 999999;
  int max_difference = 0;
  for (unsigned int i = 0; i < x.size(); i++) {
    if (x[i] - min > max_difference) max_difference = x[i] - min;
    if (x[i] < min) min = x[i];
  }
  return max_difference;
}

int main() {
  vector<int> x { 1, 5, -5, 2, 8, 12, -7, 6 };
  cout << max_difference(x) << " should be 17." << endl;
  return 0;
}
