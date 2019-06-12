// =====================================================
// Book: Elements of programming interviews
// Problem 10.5: Kth largest element online
// =====================================================

#include <iostream>
#include <sstream>
#include <string>
#include <queue>

using namespace std;

void kth_largest(istringstream& iss, size_t k) {
  priority_queue<int, vector<int>, greater<int> > min_heap;

  int x;
  while (iss >> x) {
    if (min_heap.size() < k) {
      min_heap.push(x);
      if (min_heap.size() == k) 
        cout << min_heap.top() << " ";
    } else {
      if (min_heap.top() < x) {
        min_heap.pop();
        min_heap.push(x);
      }
      cout << min_heap.top() << " ";
    }
  }
}

int main () {
  string s = "1 3 5 10 7 2 5 6 2 11";

  istringstream iss(s);
  kth_largest(iss, 3);
  cout << "should be 1 3 5 5 5 6 6 7." << endl;
  return 0;
}
