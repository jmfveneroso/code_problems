// =====================================================
// Book: Elements of programming interviews
// Problem 11.5: Search a cyclically sorted array
// =====================================================

#include <iostream>
#include <vector>

using namespace std;

// Performs binary search comparing the last element in the span to
// the middle point. If the middle point is greater, then the smallest
// point in the array must be in the right span. Otherwise it is in 
// the left span, including the middle point. Time complexity O(log(n)).
int search(vector<int>& arr) {
  int l = 0, r = arr.size() - 1;

  while (l < r) {
    int mid = l + (r - l) / 2; // To avoid overflow instead of (l + r) / 2.
    if (arr[mid] > arr[r]) {
      l = mid + 1;
    } else {
      r = mid;
    }
  }
  return l;
}

int main() {
  vector<int> arr { 378, 478, 550, 631, 103, 203, 220, 234, 279, 368 };
  cout << search(arr) << " should be 4." << endl;

  vector<int> arr2 { 1, 2, 3, 4, 5, 6 };
  cout << search(arr2) << " should be 0." << endl;

  vector<int> arr3 { 2, 3, 4, 5, 6, 1 };
  cout << search(arr3) << " should be 5." << endl;
  return 0;
}
