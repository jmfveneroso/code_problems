// =====================================================
// Book: Elements of programming interviews
// Problem 5.7: Base Conversion
// =====================================================

#include <iostream>
#include <vector>
#include <string>

using namespace std;

string convert_base1(string x, int base1, int base2) {
  // Convert to integer.
  int int_x = 0;
  int b = 1;
  for (int i = x.size() - 1; i >= 0; i--) {
    int_x += b * (x[i] - '0');
    b *= base1;
  }

  int base = 1;
  int aux = int_x / base2;
  while (aux > 0) {
    base *= base2;
    aux /= base2;
  }

  string result;
  while (base > 0) {
    char algarism = (int_x / base) + '0';
    result.push_back(algarism);
    int_x %= base;
    base /= base2;
  }

  return result;
}

string convert_base2(string x, int base1, int base2) {
  int int_x = 0;
  int b = 1;
  for (int i = x.size() - 1; i >= 0; i--) {
    int_x += b * (x[i] - '0');
    b *= base1;
  }

  int base = 1;
  string result;
  while (base < int_x) {
    char algarism = ((int_x % (base * base2)) / base) + '0';
    result.push_back(algarism);
    base *= base2;
  }

  reverse(result.begin(), result.end());
  return result;
}

string convert_base3(string x, int base1, int base2) {
  int int_x = 0;
  int b = 1;
  for (int i = x.size() - 1; i >= 0; i--) {
    int_x += b * (x[i] - '0');
    b *= base1;
  }

  string result;
  while (int_x > 0) {
    result.push_back((int_x % base2) + '0');
    int_x /= base2;
  }

  reverse(result.begin(), result.end());
  return result;
}

int main() {
  vector<string> numbers { "53", "27" , "3", "44" }; // Decimal: 53, 23, 3, 28.
  vector<int> base1 { 10, 8, 4, 6 };
  vector<int> base2 { 2, 6, 5, 9 };
  vector<string> expected { "110101", "35" , "3", "31" };

  for (int i = 0; i < numbers.size(); i++) {
    cout << "Result: " << convert_base1(numbers[i], base1[i], base2[i]) << endl;
    cout << "Result: " << convert_base2(numbers[i], base1[i], base2[i]) << endl;
    cout << "Result: " << convert_base3(numbers[i], base1[i], base2[i]) << endl;
    cout << "Expected: " << expected[i] << endl << endl;
  }

  return 0;
}
