// ===============================================================
// Book: Elements of programming interviews
// Problem 9.13: Lowest common ancestor with less time complexity
// ===============================================================

#include <iostream>
#include <vector>
#include <memory>
#include <unordered_set>
#include <stdexcept>

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

// Starts from nodes A and B and stores every checked
// node in a hash table. Each time a new node is added 
// to the hash table, we check if it has already been
// added. If this is the case then it must be the lowest
// common ancestor. O(h-d) time complexity, where h is the
// height of the tree and d is the height of the deepest
// node. Also, O(h-d) space complexity.
shared_ptr< BinTree<int> > lowest_common_ancestor(
  shared_ptr< BinTree<int> > a,
  shared_ptr< BinTree<int> > b
) {
  unordered_set< shared_ptr< BinTree<int> > > s;
  while (a != nullptr || b != nullptr) {
    if (s.find(a) != s.end()) return a;
    s.insert(a); 
    if (s.find(b) != s.end()) return b;
    s.insert(b); 
  
    if (a != nullptr) a = a->parent;
    if (b != nullptr) b = b->parent;
  }
  throw runtime_error("Reached root node without finding LCA.");
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
