// =====================================================
// Book: Elements of programming interviews
// Problem 11.3: Search array for A[i] == i 
// =====================================================

#include <iostream>
#include <vector>

using namespace std;

int search(vector<int> arr) {
  int lft = 0, rgt = arr.size() - 1;
  while (lft <= rgt) {
    int mid = lft + ((rgt - lft) >> 1);
    if (arr[mid] == mid) 
      return mid;
    else if (arr[mid] > mid)
      rgt = mid - 1;
    else
      lft = mid + 1;
  }
  return -1;
}

int main() {
  vector<int> arr { -2, -1, 0, 2, 3, 4, 5, 6, 8, 10, 11, 12 };
  int x = search(arr);
  cout << x << " should be 8." << endl;

  vector<int> arr2 { -2, -1, 0, 2, 3 };
  x = search(arr2);
  cout << x << " should be -1." << endl;
  return 0;
}
