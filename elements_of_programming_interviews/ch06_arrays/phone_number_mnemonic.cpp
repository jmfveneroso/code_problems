// =====================================================
// Book: Elements of programming interviews
// Problem 6.22: Phone Number Mnemonic
// =====================================================

#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Lists all acronym permutations. Time complexity: O(2^n).
void phone_mnemonic(const vector<int>& nums, string prefix = "", unsigned int lft = 0) {
  static char mapping[8][4] = {
    {'A', 'B', 'C', '\0'},
    {'D', 'E', 'F', '\0'},
    {'G', 'H', 'I', '\0'},
    {'J', 'K', 'L', '\0'},
    {'M', 'N', 'O', '\0'},
    {'P', 'Q', 'R', 'S' },
    {'T', 'U', 'V', '\0'},
    {'W', 'X', 'Y', 'Z' }
  };

  if (lft >= nums.size()) cout << prefix << endl;
  
  for (int i = 0; i < 4; i++) {
    char c = mapping[nums[lft] - 2][i];
    if (c == '\0') continue;

    phone_mnemonic(nums, prefix + c, lft + 1);
  }
}

int main() {
  vector<int> x { 2, 7, 8, 4 };
  phone_mnemonic(x);
  return 0;
}
