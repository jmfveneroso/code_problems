// =====================================================
// Book: Elements of programming interviews
// Problem 8.13: Queue with max
// =====================================================

#include <iostream>
#include <queue>
#include <deque>

using namespace std;

template<typename T>
class QueueWithMax {
  queue<T> data;
  deque<T> candidates;

 public:
  void enqueue(const T& value) {
    while (!candidates.empty() && candidates.back() < value) {
      candidates.pop_back();
    }

    candidates.push_back(value);
    data.push(value);
  }

  T dequeue() {
    if (candidates.front() == data.front())
      candidates.pop_front();

    T value = data.front();
    data.pop();
    return value;
  }

  T max() {
    return candidates.front();
  }
};

int main() {
  QueueWithMax<int> q;

  q.enqueue(7);
  q.enqueue(2);
  q.enqueue(5);
  q.enqueue(3);
  q.enqueue(4);
  q.enqueue(2);
  q.enqueue(1);

  cout << q.max() << " should be 7." << endl;

  q.dequeue();

  cout << q.max() << " should be 5." << endl;

  q.enqueue(8);

  cout << q.max() << " should be 8." << endl;

  q.dequeue();
  q.dequeue();
  q.dequeue();

  cout << q.max() << " should be 8." << endl;
}
