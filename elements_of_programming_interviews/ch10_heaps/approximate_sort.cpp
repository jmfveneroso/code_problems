// =====================================================
// Book: Elements of programming interviews
// Problem 10.6: Approximate sort
// =====================================================

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

// Sorts array where the elements are located at most
// k steps away from their correct location. The heap
// has O(1) look complexity and O(log(n)) insert and
// remove complexity. The algorithm makes exactly n 
// pushes and n pops, yielding O(n log(n)) time complexity.
void approximate_sort(vector<int>& arr, size_t k) {
  priority_queue< int, vector<int>, greater<int> > q;

  for (size_t i = 0; i < k; i++)
    q.push(arr[i]);

  for (size_t i = k; i < arr.size(); i++) {
    q.push(arr[i]);
    arr[i-k] = q.top();
    q.pop();
  }

  int i = arr.size() - k;
  while (!q.empty()) {
    arr[i++] = q.top();
    q.pop();
  }
}

ostream& operator<<(ostream& os, vector<int> x) {
  for (size_t i = 0; i < x.size(); i++) {
    cout << x[i];
    if (i < x.size() - 1) cout << ", ";
  }
  return os;
}

int main() {
  vector<int> arr = {1, 2, 3, 5, 4, 8, 6, 7, 10, 9};
  cout << arr << endl;
  approximate_sort(arr, 2);
  cout << arr << endl;
  return 0;
}
