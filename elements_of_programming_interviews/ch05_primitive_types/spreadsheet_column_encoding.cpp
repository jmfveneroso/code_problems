// =====================================================
// Book: Elements of programming interviews
// Problem 5.8: Spreadsheet Column Encoding
// =====================================================

#include <iostream>
#include <vector>
#include <string>

using namespace std;

// The spreadsheet column index is essentially a number in base 25, where
// each letter from A-Z corresponds to an algarism from 1-25. This function 
// performs a base conversion. O(n) time complexity.
int spreadsheet_encode(string x) {
  int result = 0;
  int base = 1;
  for (int i = x.size() - 1; i >= 0; i--) {
    result += (1 + x[i] - 'A') * base;
    base *= ('Z' - 'A');
  }
  return result;
}

int main() {
  vector<string> numbers { 
    "AAB", "BC", "M"
  };

  vector<int> expected { 
    25*25*1 + 25*1 + 2, 25 * 2 + 3, 13
  };

  for (int i = 0; i < numbers.size(); i++) {
    cout << "Result: " << spreadsheet_encode(numbers[i]) << endl;
    cout << "Expected: " << expected[i] << endl << endl;
  }
  return 0;
}
