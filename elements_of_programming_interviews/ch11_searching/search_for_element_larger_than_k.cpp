// =====================================================
// Book: Elements of programming interviews
// Problem 11.2: Search for element larger than K
// =====================================================

#include <iostream>
#include <vector>

using namespace std;

int search(vector<int> arr, int k) {
  int candidate = -1;
  int start = 0, end = arr.size() - 1; 
  while (start <= end) {
    int mid_point = start + (end - start) / 2;
    if (arr[mid_point] <= k) {
      start = mid_point + 1;
    } else {
      candidate = mid_point;
      end = mid_point - 1;
    }
  }
  return candidate;
}

int main() {
  vector<int> arr { -14, -10, 2, 108, 108, 243, 285, 285, 285, 401 };
  int i = search(arr, 103);
  cout << i << " should be 3." << endl;
  i = search(arr, 283);
  cout << i << " should be 6." << endl;
  i = search(arr, 400);
  cout << i << " should be 9." << endl;
  i = search(arr, -14);
  cout << i << " should be 1." << endl;
  i = search(arr, 401);
  cout << i << " should be -1." << endl;
  return 0;
}
