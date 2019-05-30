// =====================================================
// Book: Elements of programming interviews
// Problem 10.3: Stack and Queue with a heap
// =====================================================

#include <iostream>
#include <sstream>
#include <string>
#include <queue>

using namespace std;

struct CustomCompare {
  bool operator()(const pair<int, int>& a, const pair<int, int>& b) {
    return a.first < b.first;
  }
};

class Stack {
  priority_queue<pair<int, int>, vector< pair<int, int> >, CustomCompare > heap;
  int counter = 0;

 public:

  void Push(int x) {
    heap.push({ counter++, x });
  }

  int Pop() {
    int x = heap.top().second;
    heap.pop();
    return x;
  }
};

class Queue {
  priority_queue<pair<int, int>, vector< pair<int, int> >, CustomCompare > heap;
  int counter = 0;

 public:

  void Push(int x) {
    heap.push({ counter--, x });
  }

  int Pop() {
    int x = heap.top().second;
    heap.pop();
    return x;
  }
};

int main () {
  Stack s;
  s.Push(3);
  s.Push(52);
  s.Push(67);

  cout << s.Pop() << " should be 67." << endl;
  cout << s.Pop() << " should be 52." << endl;

  s.Push(12);
  s.Push(25);

  cout << s.Pop() << " should be 25." << endl;
  cout << s.Pop() << " should be 12." << endl;
  cout << s.Pop() << " should be 3." << endl;

  Queue q;

  q.Push(3);
  q.Push(52);
  q.Push(67);

  cout << q.Pop() << " should be 3." << endl;
  cout << q.Pop() << " should be 52." << endl;

  q.Push(12);
  q.Push(25);

  cout << q.Pop() << " should be 67." << endl;
  cout << q.Pop() << " should be 12." << endl;
  cout << q.Pop() << " should be 25." << endl;

  return 0;
}
