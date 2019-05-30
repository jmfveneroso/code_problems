// =====================================================
// Book: Elements of programming interviews
// Problem 10.8: Online median
// =====================================================

#include <iostream>
#include <sstream>
#include <string>
#include <queue>

using namespace std;

void online_median(istringstream& iss) {
  priority_queue<int> lft_heap;
  priority_queue<int, vector<int>, greater<int> > rgt_heap;

  int x;
  while (iss >> x) {
    if (lft_heap.empty()) {
      lft_heap.push(x);
    } else if (x <= lft_heap.top()) {
      lft_heap.push(x);
    } else {
      rgt_heap.push(x);
    }

    while (lft_heap.size() > rgt_heap.size() + 1) {
      rgt_heap.push(lft_heap.top());
      lft_heap.pop();
    }

    while (rgt_heap.size() > lft_heap.size()) {
      lft_heap.push(rgt_heap.top());
      rgt_heap.pop();
    }
    cout << lft_heap.top() << " ";
  }
}

int main () {
  string s = "3 5 2 7 10 11 22 12 3 4 5 6";

  istringstream iss(s);
  online_median(iss);
  cout << "should be 3 3 3 3 5 5 7 7 7 5 5 5." << endl;
  return 0;
}
