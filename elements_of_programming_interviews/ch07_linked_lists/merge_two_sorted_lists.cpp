// =====================================================
// Book: Elements of programming interviews
// Problem 7.1: Merge two sorted lists.
// =====================================================

#include <iostream>
#include <memory>

using namespace std;

template <typename T>
class node_t {
 public:
  node_t<T>(T value, shared_ptr< node_t<T> > next) : value(value), next(next) {}

  T value;
  shared_ptr< node_t<T> > next;
};


shared_ptr< node_t<int> > merge(shared_ptr< node_t<int> > a, shared_ptr< node_t<int> > b) {
  shared_ptr< node_t<int> > r;
  r = (a->value < b->value) ? a : b;

  while (a != nullptr && b != nullptr) {
    if (a->value < b->value) {
      if (a->next == nullptr) {
        a->next = b;
        a = nullptr;
      } else if (b->value < a->next->value) {
        shared_ptr< node_t<int> > tmp = a->next;
        a->next = b;
        a = tmp;
      } else {
        a = a->next;
      }
    } else {
      if (b->next == nullptr) {
        b->next = a;
        b = nullptr;
      } else if (b->next != nullptr && a->value < b->next->value) {
        shared_ptr< node_t<int> > tmp = b->next;
        b->next = a;
        b = tmp;
      } else {
        b = b->next;
      }
    }
  }
  return r;
}

ostream& operator<<(ostream& out, shared_ptr< node_t<int> > a) {
  while (a != nullptr) {
    cout << a->value;
    a = a->next;
    if (a != nullptr) cout << ", ";
  }
  return out;
}

int main() {
  shared_ptr< node_t<int> > c = make_shared< node_t<int> >(7, nullptr);
  shared_ptr< node_t<int> > b = make_shared< node_t<int> >(5, c);
  shared_ptr< node_t<int> > a = make_shared< node_t<int> >(2, b);

  shared_ptr< node_t<int> > e = make_shared< node_t<int> >(11, nullptr);
  shared_ptr< node_t<int> > d = make_shared< node_t<int> >(3, e);

  a = merge(a, d);
  cout << "Result: " << a << endl;
  cout << "Expected: 2, 3, 5, 7, 11" << endl;
  return 0;
}
