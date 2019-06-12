// ==========================================================
// Book: Elements of programming interviews
// Problem 7.8: Remove the kth last element from linked list
// ==========================================================

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

shared_ptr< Node<int> > remove_kth_last_element(shared_ptr< Node<int> > a, int k) {
  a = reverse(a);

  if (k == 0) return reverse(a->next);

  shared_ptr < Node<int> > prev = nullptr;
  shared_ptr < Node<int> > tmp = a;
  for (int i = 0; i < k; i++) {
    prev = tmp;
    tmp = tmp->next;
  }
  prev->next = tmp->next;
  return reverse(a);
}

int main () {
  shared_ptr< Node<int> > e = make_shared< Node<int> >(4, nullptr);
  shared_ptr< Node<int> > d = make_shared< Node<int> >(3, e);
  shared_ptr< Node<int> > c = make_shared< Node<int> >(2, d);
  shared_ptr< Node<int> > b = make_shared< Node<int> >(1, c);
  shared_ptr< Node<int> > a = make_shared< Node<int> >(0, b);

  cout << a << endl;
  a = remove_kth_last_element(a, 1);
  cout << a << " should be 0, 1, 2, 4" << endl;
  a = remove_kth_last_element(a, 0);
  cout << a << " should be 0, 1, 2" << endl;
  return 0;
}
