// =====================================================
// Book: Elements of programming interviews
// Problem 11.1: First occurrence of k in sorted array
// =====================================================

#include <iostream>
#include <vector>

using namespace std;

// O(log(n)) time complexity.
int search(vector<int>& arr, int k) {
  int candidate = -1;
  int l = 0, r = arr.size() - 1;
  while (l <= r) {
    int mid = l + ((r - l) >> 1);
    if (arr[mid] == k) {
      candidate = mid;
      r = mid - 1;
    } else if (arr[mid] > k) {
      r = mid - 1;
    } else {
      l = mid + 1;
    }
  }
  return candidate;
}

int main() {
  vector<int> arr { -14, -10, 2, 108, 108, 243, 285, 285, 285, 401 };
  cout << search(arr, 108) << " should be 3." << endl;
  cout << search(arr, 285) << " should be 6." << endl;
  cout << search(arr, 303) << " should be -1." << endl;
  return 0;
}
