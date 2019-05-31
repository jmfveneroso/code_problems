// =================================================================
// Book: Elements of programming interviews
// Problem 11.13: Kth largest element in array of distinct elements
// =================================================================

#include <iostream>
#include <vector>

using namespace std;

ostream& operator<<(ostream& os, vector<int> x) {
  for (auto i : x) cout << i << ", ";
  return os;
}

// Finds the kth largest element of an array with distinct elements.
// The time complexity is O(n) = O(n) + O(n/2) which reduces to O(n).
int kth_largest_element(vector<int>& arr, int k, int l, int r) {
  int p_l = l;  
  int p_r = r - 1;  
  while (true) {
    while (arr[p_l] < arr[r]) p_l++;
    while (arr[p_r] > arr[r]) p_r--;
    if (p_l >= p_r) break;
    arr[p_l] ^= arr[p_r] ^= arr[p_l] ^= arr[p_r]; // Swap.
  }
  cout << p_l << endl;
  cout << arr << endl;

  if (p_l == k) {
    return arr[r];
  } else if (p_l > k) {
    cout << "a: " << l << ", " << p_l-1 << endl;
    return kth_largest_element(arr, k, l, p_l-1);
  } else {
    cout << "a: " << p_l+1 << ", " << r-1 << endl;
    return kth_largest_element(arr, k, p_l+1, r-1);
  }
}

int main() {
  vector<int> arr { 3, 5, 6, 1, 4, 8, 7, 2 };
  cout << kth_largest_element(arr, 3, 0, arr.size() - 1) << " should be 3." << endl;
  return 0;
}
