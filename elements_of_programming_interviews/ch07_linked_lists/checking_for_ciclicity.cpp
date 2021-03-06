// =====================================================
// Book: Elements of programming interviews
// Problem 7.2: Checking for cyclicity
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

shared_ptr< node_t<int> > detect_cycles(shared_ptr< node_t<int> > x) {
  shared_ptr< node_t<int> > y = x;
  shared_ptr< node_t<int> > z = x;
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

int main() {
  shared_ptr< node_t<int> > c = make_shared< node_t<int> >(7, nullptr);
  shared_ptr< node_t<int> > b = make_shared< node_t<int> >(5, c);
  shared_ptr< node_t<int> > a = make_shared< node_t<int> >(2, b);

  shared_ptr< node_t<int> > g = make_shared< node_t<int> >(16, nullptr);
  shared_ptr< node_t<int> > f = make_shared< node_t<int> >(14, g);
  shared_ptr< node_t<int> > e = make_shared< node_t<int> >(11, f);
  shared_ptr< node_t<int> > d = make_shared< node_t<int> >(3, e);
  g->next = e;

  cout << (detect_cycles(a) == nullptr) << " should be true." << endl;
  cout << (detect_cycles(d) == e) << " should be true." << endl;
  return 0;
}
