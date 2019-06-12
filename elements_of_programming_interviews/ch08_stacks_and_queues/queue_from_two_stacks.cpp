#include <iostream>
#include <stack>
#include <stdexcept>

using namespace std;

template<typename T>
class Queue {
  stack<T> A, B;  

 public:
  Queue() {}

  void enqueue(const T& value) {
    A.push(value);
  }

  T dequeue() {
    if (B.empty()) {
      while (!A.empty()) {
        B.push(A.top());
        A.pop();
      }
    }

    if (!B.empty()) {
      T value = B.top(); 
      B.pop();
      return value;
    }
    throw length_error("Queue is empty.");
  }
};

int main () {
  Queue<int> q;
  q.enqueue(1);
  q.enqueue(2);
  q.enqueue(3);
  q.enqueue(4);
  cout << q.dequeue() << endl;
  cout << q.dequeue() << endl;
  cout << q.dequeue() << endl;
  cout << q.dequeue() << endl;
  return 0;
}
