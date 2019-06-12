// =====================================================
// Book: Elements of programming interviews
// Problem 11.9: Computing square roots
// =====================================================

#include <iostream>

using namespace std;

// This square root function starts with a number that is
// guaranteed to be higher than the sought square root and
// updates each time moving in the direction of the actual
// square root by a step that is guaranteed to be smaller
// than the actual difference.
float sqrt(float x) {
  float res = x;

  while ((res*res - x) > 0.0001)
    res -= res/2 - x/(2*res);
  return res;
}

// Performs a binary search over a fixed range. This function
// does not work if the square root is outside that range.
// The square root is never higher than x itself.
float sqrt_binsearch(float x) {
  float lower_bound = 0;
  float upper_bound = x;

  float res;
  while (true) {
    res = (upper_bound + lower_bound) / 2.0;

    float diff = res*res - x;
    if (diff > 0.0001) 
      upper_bound = res;
    else if (diff < -0.0001)
      lower_bound = res;
    else
      return res;
  }
}

int main() {
  cout << sqrt(4) << " should be 2." << endl;
  cout << sqrt_binsearch(4) << " should be 2." << endl;
  cout << sqrt(15) << " should be 3.87." << endl;
  cout << sqrt_binsearch(15) << " should be 3.87." << endl;
  cout << sqrt(13) << " should be 3.60." << endl;
  cout << sqrt_binsearch(13) << " should be 3.60." << endl;
  return 0;
}
