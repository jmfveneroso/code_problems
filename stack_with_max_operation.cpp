// =====================================================
// Book: Elements of programming interviews
// Problem 8.1: Stack with max operation
// =====================================================

#include <iostream>
#include <memory>

using namespace std;

template<typename T>
class Node {
 public:
  Node(T value, shared_ptr< Node<T> > next) : 
    value(value), next(next) {}

  T value;
  shared_ptr< Node<T> > next;
};


// This stack keeps the maximum value at each stack position
// in addition to the value at that position. To keep track
// of the maximum value at any point, we need simply look at the 
// first position of the linked list with maximum values. Takes
// O(n) additional space.
template<typename T>
class Stack {
  shared_ptr< Node<T> > first_node_;
  shared_ptr< Node<T> > max_node_;

 public:
  Stack() : first_node_(nullptr), max_node_(nullptr) {}

  void push(T value) {
    first_node_ = make_shared< Node<T> >(value, first_node_);
    if (max_node_ == nullptr)
      max_node_ = make_shared< Node<T> >(value, max_node_);
    else {
      T max_value = (max_node_->value > value) ? max_node_->value : value;
      max_node_ = make_shared< Node<T> >(max_value, max_node_);
    }
  }

  T pop() {
    T value = first_node_->value;
    first_node_ = first_node_->next;

    max_node_ = max_node_->next;
    return value; 
  }

  T max() {
    return max_node_->value;
  }
};

ostream& operator<<(ostream& os, shared_ptr< Node<int> > x) {
  while (x != nullptr) {
    cout << x->value;
    x = x->next;
    if (x != nullptr) cout << ", ";
  }
  return os;
}

int main () {
  Stack<int> s;

  s.push(3);
  s.push(5);
  s.push(10);
  s.push(2);

  cout << s.max() << " should be 10." << endl;
  s.pop();
  s.pop();
  cout << s.max() << " should be 5." << endl;
  s.pop();
  cout << s.max() << " should be 3." << endl;
  return 0;
}
