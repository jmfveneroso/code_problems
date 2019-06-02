#include <iostream>
#include <vector>
#include <stack>

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

// X is the number for which we want to find the multiplicative inverse and
// Y is the modulo.
int find_multiplicative_inverse(int x, int y) {
  int x_ = x, y_ = y;
  stack<int> s;
  while (true) {
    int gcd = y_ % x_;
    if (gcd == 0) break;
    s.push(-y_ / x_);
    y_ = x_;
    x_ = gcd;
  }

  int adder = 0, multiplier = 1;
  while (!s.empty()) {
    int tmp = multiplier;
    multiplier = multiplier * s.top() + adder;
    adder = tmp;
    s.pop();
  }

  return (y + multiplier) % y;
}

int naive_inverse(int a, int m) { 
  a = a % m; 
  for (int x = 1; x < m; x++) 
    if ((a * x) % m == 1) 
      return x; 
  return -1;
}

// Code taken from here 
// https://www.geeksforgeeks.org/multiplicative-inverse-under-modulo-m/.
// https://www.google.com/search?q=find+multiplicative+inverse+algorithm&oq=find+multiplicative+inverse+al&aqs=chrome.1.69i57j0l5.6424j0j7&sourceid=chrome&ie=UTF-8#kpvalbx=1
int gcd_extended(int a, int b, int& x, int& y) { 
  // Base Case 
  if (a == 0) { 
    x = 0, y = 1; 
    return b; 
  } 
  
  int x1, y1;
  int gcd = gcd_extended(b % a, a, x1, y1); 
  
  // Update x and y using results of recursive call.
  x = y1 - (b/a) * x1; 
  y = x1; 
  return gcd; 
}

// Function to find modulo inverse of a 
int mod_inverse(int a, int m) { 
  int x, y; 
  int g = gcd_extended(a, m, x, y); 
  if (g != 1) 
    return 0;
  else { 
    // m is added to handle negative x 
    return (x % m + m) % m; 
  } 
} 

int main () {
  cout << gcd(26, 5) << " should be 1." << endl;
  cout << gcd(26, 14) << " should be 2." << endl;
  cout << gcd(28, 8) << " should be 4." << endl;

  cout << find_multiplicative_inverse(11, 26) << " should be 19." << endl;
  cout << find_multiplicative_inverse(13, 5) << " should be 2." << endl;
  cout << mod_inverse(13, 5) << " should be 2." << endl;
  cout << naive_inverse(13, 5) << " should be 2." << endl;
  cout << find_multiplicative_inverse(997, 10) << " should be 3." << endl;
  cout << naive_inverse(997, 10) << " should be 3." << endl;
  cout << mod_inverse(997, 10) << " should be 3." << endl;


  // cout << find_multiplicative_inverse(26, 11) << " should be 19." << endl;
  return 0;
}
