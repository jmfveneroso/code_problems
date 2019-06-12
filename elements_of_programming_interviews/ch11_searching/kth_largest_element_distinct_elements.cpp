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

  if (p_l != r)
    arr[p_l] ^= arr[r] ^= arr[p_l] ^= arr[r]; // Swap.

  if (p_l == k - 1) {
    return arr[p_l];
  } else if (p_l > k) {
    return kth_largest_element(arr, k, l, p_l-1);
  } else {
    return kth_largest_element(arr, k, p_l+1, r);
  }
}

int main() {
  vector<int> arr { 3, 5, 6, 1, 4, 8, 7, 2 };
  cout << kth_largest_element(arr, 3, 0, arr.size() - 1) << " should be 3." << endl;

  vector<int> arr2 { 3, 5, 6, 1, 4, 8, 7, 2 };
  cout << kth_largest_element(arr2, 6, 0, arr.size() - 1) << " should be 6." << endl;
  return 0;
}
