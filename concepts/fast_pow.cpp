#include <iostream>

using namespace std;

int fast_pow(int base, int exp) {
  int result = 1;
  while (exp > 0) {
    if (exp % 2 == 0) {
      exp /= 2;
      base *= base;
    } else {
      exp -= 1;
      result *= base;
    }
  }
  return result;
}

int main() {
  cout << fast_pow(3, 10) << " should be 59049." << endl;
  cout << fast_pow(5, 11) << " should be 48828125." << endl;
  cout << fast_pow(2, 15) << " should be 32768." << endl;
  cout << fast_pow(7, 7) << " should be 823543." << endl;
  cout << fast_pow(123, 0) << " should be 1." << endl;
  return 0;
}
