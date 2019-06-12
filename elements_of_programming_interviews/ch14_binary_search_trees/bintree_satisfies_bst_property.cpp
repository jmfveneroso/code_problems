// =====================================================
// Book: Elements of programming interviews
// Problem 14.1: Bintree satisfies BST property
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

// Performs a DFS checking at each time if the subtree conforms 
// to the BST property. O(n) time complexity.
bool bintree_satisfies_bst(
  shared_ptr< BinTree<int> > x, 
  int lower=numeric_limits<int>::min(), 
  int upper=numeric_limits<int>::max()
) {
  if (x == nullptr) return true;

  if (x->value < lower || x->value > upper) return false;

  if (!bintree_satisfies_bst(x->lft, lower, x->value)) return false;
  if (!bintree_satisfies_bst(x->rgt, x->value, upper)) return false;
  return true;
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

  cout << bintree_satisfies_bst(a) << " should be true." << endl;

  g->lft = make_shared< BinTree<int> >(42, nullptr, nullptr);

  cout << bintree_satisfies_bst(a) << " should be false." << endl;
  return 0;
}
