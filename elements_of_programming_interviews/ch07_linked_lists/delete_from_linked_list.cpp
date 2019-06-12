// =====================================================
// Book: Elements of programming interviews
// Problem 7.7: Delete from linked list
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

// Deletes a linked list node in O(1) time by taking
// the value of the next node. Does not work if the
// deleted node is the last one in the list.
void delete_node(shared_ptr< Node<int> > a) {
  if (a == nullptr) return;
  a->value = a->next->value;
  a->next = a->next->next;
}

int main () {
  shared_ptr< Node<int> > e = make_shared< Node<int> >(4, nullptr);
  shared_ptr< Node<int> > d = make_shared< Node<int> >(3, e);
  shared_ptr< Node<int> > c = make_shared< Node<int> >(2, d);
  shared_ptr< Node<int> > b = make_shared< Node<int> >(1, c);
  shared_ptr< Node<int> > a = make_shared< Node<int> >(0, b);

  cout << a << endl;
  delete_node(c);
  cout << a << " should be 0, 1, 3, 4" << endl;
  return 0;
}
