// =====================================================
// Book: Elements of programming interviews
// Problem 9.9: Linked list from the leaves of bin tree
// =====================================================

#include <iostream>
#include <memory>

using namespace std;

template<typename T>
class BinTree {
 public:
  BinTree(
    T value, 
    shared_ptr< BinTree<T> > lft, 
    shared_ptr< BinTree<T> > rgt
  ) : value(value), lft(lft), rgt(rgt) {
  }

  T value;
  shared_ptr< BinTree<T> > lft;
  shared_ptr< BinTree<T> > rgt;
};

void print_leaves(shared_ptr< BinTree<int> > root) {
  if (!root) return;
  if (!root->lft && !root->rgt) cout << root->value << ", ";

  print_leaves(root->lft);
  print_leaves(root->rgt);
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

  print_leaves(a);
  cout << "should be 23, 31, 41, 47." << endl;
  return 0;
}
