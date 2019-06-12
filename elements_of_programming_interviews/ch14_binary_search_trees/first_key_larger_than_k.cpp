// =====================================================
// Book: Elements of programming interviews
// Problem 14.5: First key larger than k
// =====================================================

#include <iostream>
#include <memory>
#include <limits>

using namespace std;

template<typename T>
class BinTree {
 public:
  T value;
  shared_ptr<BinTree> lft;
  shared_ptr<BinTree> rgt;

  BinTree(
    T value,
    shared_ptr<BinTree> lft,
    shared_ptr<BinTree> rgt
  ) : value(value), lft(lft), rgt(rgt) {}
};

shared_ptr< BinTree<int> > find_key_larger_than_k(shared_ptr< BinTree<int> > x, int k) {
  shared_ptr< BinTree<int> > first_key = nullptr;

  bool found_key;
  while (x) {
    if (x->value == k) {
      found_key = true;
      x = x->rgt;
    } else if (x->value > k) {
      first_key = x;
      x = x->lft;
    } else {
      x = x->rgt;
    }
  }

  return (found_key) ? first_key : nullptr;
}

int main() {
  /*         
              Example tree:
                   37  
                /      \
              29        43 
            /    \    /    \
           23    31  41    47
  */

  shared_ptr< BinTree<int> > d = make_shared< BinTree<int> >(23, nullptr, nullptr);
  shared_ptr< BinTree<int> > e = make_shared< BinTree<int> >(31, nullptr, nullptr);
  shared_ptr< BinTree<int> > b = make_shared< BinTree<int> >(29, d, e);

  shared_ptr< BinTree<int> > g = make_shared< BinTree<int> >(41, nullptr, nullptr);
  shared_ptr< BinTree<int> > f = make_shared< BinTree<int> >(47, nullptr, nullptr);
  shared_ptr< BinTree<int> > c = make_shared< BinTree<int> >(43, g, f);

  shared_ptr< BinTree<int> > a = make_shared< BinTree<int> >(37, b, c);

  cout << (find_key_larger_than_k(a, 29) == e) << " should be true." << endl;
  cout << (find_key_larger_than_k(a, 42) == nullptr) << " should be true." << endl;
  return 0;
}
