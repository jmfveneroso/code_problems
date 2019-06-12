// =====================================================
// Book: Elements of programming interviews
// Problem 13.5: Intersect sorted arrays
// =====================================================

#include <iostream>
#include <vector>

using namespace std;

// Finds the intersection of two sorted arrays in O(n) time
// and O(n) space complexity.
vector<int> intersect(vector<int>& x, vector<int>& y) {
  vector<int> result;

  size_t i = 0, j = 0;
  while (i < x.size() && j < y.size()) {
    if (x[i] == y[j]) {
      if (!result.size() || x[i] != result.back())
        result.push_back(x[i]);
      i++, j++;
    } else if (x[i] < y[j]) {
      i++;
    } else {
      j++;
    }
  }
  return result;
}

// We assume x is smaller and perform binary search in
// the y array. This goes in O(n log(m)) time where n
// is the size of the small array and m is the size of 
// the big array.
vector<int> intersect2(vector<int>& x, vector<int>& y) {
  vector<int> result;

  for (size_t i = 0; i < x.size(); i++) {
    int l = 0, r = y.size() - 1;
    while (l <= r) {
      int m = l + (r - l) / 2;
      if (x[i] == y[m]) {
        if (!result.size() || x[i] != result.back())
          result.push_back(x[i]);
        break;
      } else if (x[i] < y[m]) {
        r = m-1;
      } else {
        l = m+1;
      }
    }
  }
  return result;
}

ostream& operator<<(ostream& os, vector<int> v) {
  for (auto& x : v) cout << x << " ";
  return os;
}

int main() {
  vector<int> x { 1, 2, 3, 3, 4, 6, 8 };
  vector<int> y { 2, 3, 3, 5, 6, 7, 8, 9 };
  vector<int> result = intersect(x, y);
  cout << result << "should be 2 3 6 8." << endl;

  x = { 1, 5, 8 };
  y = { 2, 2, 2, 2, 2, 3, 3, 4, 5, 5, 5, 6, 7, 7, 7, 8, 9 };
  result = intersect2(x, y);
  cout << result << "should be 5 8." << endl;
  return 0;
}
