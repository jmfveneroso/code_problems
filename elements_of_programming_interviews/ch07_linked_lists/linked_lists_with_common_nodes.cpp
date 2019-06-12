// =====================================================
// Book: Elements of programming interviews
// Problem 7.4: Linked lists with common nodes
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

shared_ptr< Node<int> > find_common_node(
  shared_ptr< Node<int> > a, shared_ptr< Node<int> > b
) {
  unsigned int a_len = 0;
  unsigned int b_len = 0;

  shared_ptr< Node<int> > a_ = a;
  shared_ptr< Node<int> > b_ = b;
  while (a_ != nullptr) { 
    a_ = a_->next;
    a_len++;
  }

  while (b_ != nullptr) { 
    b_ = b_->next;
    b_len++;
  }

  unsigned int diff = 0;
  if (a_len > b_len) {
    a_ = a; b_ = b;
    diff = a_len - b_len;
  } else {
    a_ = b; b_ = a;
    diff = b_len - a_len;
  }
 
  for (unsigned int i = 0; i < diff; i++) a_ = a_->next;
 
  while (a_ != nullptr) {
    if (a_ == b_) return a_;
    a_ = a_->next; 
    b_ = b_->next; 
  }

  return nullptr;
}

int main () {
  shared_ptr< Node<int> > e = make_shared< Node<int> >(7, nullptr);
  shared_ptr< Node<int> > d = make_shared< Node<int> >(6, e);
  shared_ptr< Node<int> > c = make_shared< Node<int> >(5, d);
  shared_ptr< Node<int> > b = make_shared< Node<int> >(2, c);
  shared_ptr< Node<int> > a = make_shared< Node<int> >(1, b);

  shared_ptr< Node<int> > b2 = make_shared< Node<int> >(4, c);
  shared_ptr< Node<int> > a2 = make_shared< Node<int> >(3, b2);

  shared_ptr< Node<int> > b3 = make_shared< Node<int> >(9, nullptr);
  shared_ptr< Node<int> > a3 = make_shared< Node<int> >(8, b3);

  cout << a << endl;
  cout << a2 << endl;

  cout << (find_common_node(a, a2) == c) << " should be true" << endl;
  cout << (find_common_node(a, a3) == nullptr) << " should be true" << endl;
  return 0;
}
