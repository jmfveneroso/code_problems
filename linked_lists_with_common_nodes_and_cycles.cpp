// ======================================================
// Book: Elements of programming interviews
// Problem 7.5: Linked lists with common nodes and cycles
// ======================================================

#include <iostream>
#include <memory>
#include <vector>

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

shared_ptr< Node<int> > check_cycle(shared_ptr< Node<int> > x) {
  shared_ptr< Node<int> > y = x;
  shared_ptr< Node<int> > z = x;
  while (x != nullptr) {
    x = x->next;
    if (y != nullptr) y = y->next;
    if (y != nullptr) y = y->next;
    if (x != nullptr && x == y) {
      while (z != x) {
        x = x->next;
        z = z->next;
      }
      return z; 
    }
  }
  return nullptr;
}

// This function assumes that both lists end in a cycle.
// If only one list contains a cycle then there is no
// common node. If both lists end in a null pointer, the
// procedure was already described in problem 7.4. O(n) time complexity.
// O(1) space complexity.
vector< shared_ptr< Node<int> > > find_common_node_with_cycle(
  shared_ptr< Node<int> > a, shared_ptr< Node<int> > b
) {
  shared_ptr< Node<int> > c_a = check_cycle(a);
  shared_ptr< Node<int> > c_b = check_cycle(b);

  if (c_a != c_b)
    return { c_a, c_b };

  unsigned int a_len = 0;
  unsigned int b_len = 0;

  shared_ptr< Node<int> > a_ = a;
  shared_ptr< Node<int> > b_ = b;
  while (a_ != c_a) { 
    a_ = a_->next; a_len++;
  }

  while (b_ != c_b) { 
    b_ = b_->next; b_len++;
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
    if (a_ == b_) return { a_, a_ };
    a_ = a_->next; 
    b_ = b_->next; 
  }

  return { nullptr, nullptr };
}

int main () {
  shared_ptr< Node<int> > e = make_shared< Node<int> >(7, nullptr);
  shared_ptr< Node<int> > d = make_shared< Node<int> >(6, e);
  shared_ptr< Node<int> > c = make_shared< Node<int> >(5, d);
  shared_ptr< Node<int> > b = make_shared< Node<int> >(2, c);
  shared_ptr< Node<int> > a = make_shared< Node<int> >(1, b);
  e->next = c;

  shared_ptr< Node<int> > b2 = make_shared< Node<int> >(4, d);
  shared_ptr< Node<int> > a2 = make_shared< Node<int> >(3, b2);

  shared_ptr< Node<int> > b3 = make_shared< Node<int> >(9, b);
  shared_ptr< Node<int> > a3 = make_shared< Node<int> >(8, b3);

  cout << (find_common_node_with_cycle(a, a2)[0] == c) << " should be true" << endl;
  cout << (find_common_node_with_cycle(a, a2)[1] == d) << " should be true" << endl;
  cout << (find_common_node_with_cycle(a, a3)[0] == b) << " should be true" << endl;
  cout << (find_common_node_with_cycle(a, a3)[1] == b) << " should be true" << endl;
  return 0;
}
