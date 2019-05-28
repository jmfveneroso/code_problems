// =====================================================
// Book: Elements of programming interviews
// Problem 8.10: Circular queue
// =====================================================

#include <iostream>
#include <memory>
#include <vector>
#include <stdexcept>

using namespace std;

template<typename T>
class Queue {
  size_t head, tail, count;
  vector<T> values;
 
 public:
  Queue(const size_t& cap = 1)
    : head(0), tail(0), count(0), values(cap) {
  }

  void enqueue(const T& value) {
    if (count == values.size()) {
      size_t old_size = values.size();
      values.resize(values.size() << 1);

      for (size_t i = 0; i < count; i++) {
        values[old_size+i] = values[head];
        head = (head + 1) % old_size;
      }
      head = old_size;
      tail = 0;
    }

    values[tail] = value;
    tail = (tail + 1) % values.size(), count++;
  }

  T dequeue() {
    if (count == 0)
      throw length_error("Empty queue.");

    count--;
    T val = values[head];
    head = (head + 1) % values.size();
    return val;
  }
};

int main() {
  Queue<int> q;
  q.enqueue(1);
  q.enqueue(2);
  q.enqueue(3);
  q.enqueue(4);
  q.enqueue(5);
  q.enqueue(6);
  cout << q.dequeue() << endl;
  cout << q.dequeue() << endl;
  cout << q.dequeue() << endl;
  cout << q.dequeue() << endl;
  cout << q.dequeue() << endl;
  cout << q.dequeue() << endl;
  return 0;
}
