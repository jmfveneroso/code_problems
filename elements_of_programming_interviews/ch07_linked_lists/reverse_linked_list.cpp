// =====================================================
// Book: Elements of programming interviews
// Problem 7.9: Reverse linked list
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

ostream& operator<<(ostream& os, shared_ptr< Node<int> > x) {
  while (x != nullptr) {
    cout << x->value;
    x = x->next;
    if (x != nullptr) cout << ", ";
  }
  return os;
}

shared_ptr< Node<int> > reverse(shared_ptr< Node<int> > a) {
  shared_ptr < Node<int> > prev = nullptr;
  while (a != nullptr) {
    shared_ptr < Node<int> > next = a->next;
    a->next = prev;
    prev = a;
    a = next; 
  }
  return prev;
}

int main () {
  shared_ptr< Node<int> > e = make_shared< Node<int> >(4, nullptr);
  shared_ptr< Node<int> > d = make_shared< Node<int> >(3, e);
  shared_ptr< Node<int> > c = make_shared< Node<int> >(2, d);
  shared_ptr< Node<int> > b = make_shared< Node<int> >(1, c);
  shared_ptr< Node<int> > a = make_shared< Node<int> >(0, b);

  cout << a << endl;
  a = reverse(a);
  cout << a << " should be 4, 3, 2, 1, 0" << endl;
  return 0;
}
