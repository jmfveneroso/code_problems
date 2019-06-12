// =====================================================
// Book: Elements of programming interviews
// Problem 7.6: Even odd merge
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

void even_odd_merge(shared_ptr< Node<int> > a) {
  if (a == nullptr) return;
  if (a->next == nullptr) return;

  shared_ptr< Node<int> > first_odd = a->next;

  bool even = true;
  while (a != nullptr) {
    shared_ptr< Node<int> > tmp = a->next;
   
    if (a->next == nullptr) {
      if (even) 
        a->next = first_odd;
    } else if (a->next->next == nullptr) {
      if (even) 
        a->next = first_odd;
      else
        a->next = nullptr;
    } else {
      a->next = a->next->next;
    }

    a = tmp;
    even = !even;
  }
}

int main () {
  shared_ptr< Node<int> > e = make_shared< Node<int> >(4, nullptr);
  shared_ptr< Node<int> > d = make_shared< Node<int> >(3, e);
  shared_ptr< Node<int> > c = make_shared< Node<int> >(2, d);
  shared_ptr< Node<int> > b = make_shared< Node<int> >(1, c);
  shared_ptr< Node<int> > a = make_shared< Node<int> >(0, b);

  cout << a << endl;
  even_odd_merge(a);
  cout << a << " should be 0, 2, 4, 1, 3" << endl;
  return 0;
}
