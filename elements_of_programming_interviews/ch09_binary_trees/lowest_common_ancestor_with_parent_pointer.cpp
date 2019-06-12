// ============================================================
// Book: Elements of programming interviews
// Problem 9.12: Lowest common ancestor with parent pointer
// ============================================================

#include <iostream>
#include <vector>
#include <memory>
#include <queue>
#include <stack>

using namespace std;

template<typename T>
class BinTree {
 public:
  T value;
  shared_ptr<BinTree> lft;
  shared_ptr<BinTree> rgt;
  shared_ptr<BinTree> parent;

  BinTree(
    T value,
    shared_ptr<BinTree> lft,
    shared_ptr<BinTree> rgt
  ) : value(value), lft(lft), rgt(rgt), parent(nullptr) {}
};

// O(h) time complexity, where h is the tree height.
shared_ptr< BinTree<int> > lowest_common_ancestor(
  shared_ptr< BinTree<int> > a,
  shared_ptr< BinTree<int> > b
) {
  int height_a = 0;
  int height_b = 0;

  shared_ptr< BinTree<int> > tmp_a = a;
  shared_ptr< BinTree<int> > tmp_b = b;
  while (tmp_a != nullptr) {
    height_a++;
    tmp_a = tmp_a->parent;
  }

  while (tmp_b != nullptr) {
    height_b++;
    tmp_b = tmp_b->parent;
  }

  if (height_a > height_b) {
    for (int i = 0; i < height_a - height_b; i++) a = a->parent;
  } else {
    for (int i = 0; i < height_b - height_a; i++) b = b->parent;
  }

  while (a != b)
    a = a->parent, b = b->parent;
  return a;
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
  d->parent = b;
  e->parent = b;

  shared_ptr< BinTree<int> > g = make_shared< BinTree<int> >(41, nullptr, nullptr);
  shared_ptr< BinTree<int> > f = make_shared< BinTree<int> >(47, nullptr, nullptr);
  shared_ptr< BinTree<int> > c = make_shared< BinTree<int> >(43, g, f);
  g->parent = c;
  f->parent = c;

  shared_ptr< BinTree<int> > a = make_shared< BinTree<int> >(37, b, c);
  b->parent = a;
  c->parent = a;

  shared_ptr< BinTree<int> > res = lowest_common_ancestor(d, e);
  cout << (res == b) << " should be true." << endl;

  res = lowest_common_ancestor(d, f);
  cout << (res == a) << " should be true." << endl;

  res = lowest_common_ancestor(b, d);
  cout << (res == b) << " should be true." << endl;
  return 0;
}
