// Study in priority queues.

#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

// This template definition was extracted from the STL headers in
// /usr/include/c++/5/bits/stl_queue.h
template<
  typename _Tp, 
  typename _Sequence = vector<_Tp>,
  typename _Compare  = less<typename _Sequence::value_type> 
>
ostream& operator<<(ostream& os, priority_queue<_Tp, _Sequence, _Compare> q) {
  while (!q.empty()) {
    cout << q.top() << " ";
    q.pop();
  }
  return os;
}

class Compare {
 public:
  bool operator()(const int& a, const int& b) {
    return a > b;
  }
};

int main () {
  // Standard int priority queue. Max heap.
  priority_queue<int> q1;
  q1.push(1);
  q1.push(5);
  q1.push(2);
  q1.push(3);
  cout << q1 << endl;

  // Int priority queue with explicit storage. Max heap.
  priority_queue<int, vector<int> > q2;
  q2.push(1);
  q2.push(5);
  q2.push(2);
  q2.push(3);
  cout << q2 << endl;

  // Int priority queue with greater function. Min heap.
  priority_queue<int, vector<int>, greater<int> > q3;
  q3.push(1);
  q3.push(5);
  q3.push(2);
  q3.push(3);
  cout << q3 << endl;

  // Int priority queue with custom class comparison. Min heap.
  priority_queue<int, vector<int>, Compare > q4;
  q4.push(1);
  q4.push(5);
  q4.push(2);
  q4.push(3);
  cout << q4 << endl;

  auto compare_fn = [](int a, int b) {
    return a < b;
  };

  // Int priority queue with custom function comparison. Max heap.
  priority_queue<int, vector<int>, decltype(compare_fn) > q5(compare_fn);
  q5.push(1);
  q5.push(5);
  q5.push(2);
  q5.push(3);
  cout << q5 << endl;

  return 0;
}
