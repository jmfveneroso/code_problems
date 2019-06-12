#include <iostream>
#include <vector>

using namespace std; 

// Implementation of Euclid's algorithm for finding the greatest common
// divisor.
int gcd(int x, int y) {
  if (y > x) {
    int tmp = y;
    x = y;
    y = tmp;
  }

  while (true) {
    int gcd = x % y;
    if (gcd == 0) return y;
    x = y;
    y = gcd;
  }
}

int main () {
  cout << gcd(26, 5) << " should be 1." << endl;
  cout << gcd(26, 14) << " should be 2." << endl;
  cout << gcd(28, 8) << " should be 4." << endl;
  return 0;
}
