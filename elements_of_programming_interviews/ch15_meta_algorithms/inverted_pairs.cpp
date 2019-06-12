// =====================================================
// Book: Elements of programming interviews
// Problem 15.2: Inverted pairs of indices
// =====================================================

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

ostream& operator<<(ostream& os, vector<int>& x) {
  for (auto& i : x) cout << i << " ";
  return os;
}

// Time complexity: O(n^2).
int naive_count_inversions(vector<int>& arr) {
  int inversions = 0;
  for (size_t i = 0; i < arr.size(); i++) {
    for (size_t j = i+1; j < arr.size(); j++) {
      if (arr[i] > arr[j]) inversions++;
    }
  }
  return inversions;
}

// Counts the inversions in two sorted arrays assuming that all 
// elements in array B come after array A. Time complexity: O(n).
int count_inversions(vector<int>& a, vector<int>& b) {
  int inversions = 0;
  size_t j = 0;
  for (size_t i = 0; i < a.size(); i++) {
    while (j < b.size() && a[i] > b[j]) j++;
    inversions += j;    
  }
  return inversions;
}

// Merges two sorted arrays producing a sorted array. Time 
// complexity: O(n).
vector<int> merge_arrays(vector<int>& a, vector<int>& b) {
  vector<int> c(a.size() + b.size(), 0); 

  size_t i = 0, j = 0, k = 0;
  while (i < a.size() || j < b.size()) {
    if (j == b.size()) 
      c[k++] = a[i++];
    else if (i == a.size()) 
      c[k++] = b[j++];
    else if (a[i] < b[j]) 
      c[k++] = a[i++];
    else 
      c[k++] = b[j++];
  }
  return c;
}

// Calculates the number of inversions while merging. Time complexity:
// O(n log(n)).
vector<int> calculate_inverted(vector<int>& arr, int i, int j, int& count) {
  if (i == j) 
    return vector<int>({ arr[i] });

  int mid = i + (j - i) / 2;
  vector<int> lft = calculate_inverted(arr, i, mid, count);
  vector<int> rgt = calculate_inverted(arr, mid+1, j, count);
 
  count += count_inversions(lft, rgt);
  return merge_arrays(lft, rgt); 
}

int main() {
  vector<int> a { 2, 3, 5, 5, 6, 12, 13 };
  vector<int> b { 1, 4, 5, 7, 8, 9 };
  vector<int> c;
  c.reserve(a.size()+b.size());
  c.insert(c.end(), a.begin(), a.end());
  c.insert(c.end(), b.begin(), b.end());
  cout << naive_count_inversions(c) << " should be " << count_inversions(a, b) << endl;

  vector<int> result = merge_arrays(a, b);
  sort(c.begin(), c.end());
  cout << result << "should be " << c << endl;

  vector<int> d { 24, 32, 11, 17, 4, 44, 56, 77, 15, 2, 29, 31 };

  int count = 0;
  vector<int> e = calculate_inverted(d, 0, d.size()-1, count);
  cout << count << " should be " << naive_count_inversions(d) << endl;
  sort(d.begin(), d.end());
  cout << e << "should be " << d << endl;

  return 0;
}
