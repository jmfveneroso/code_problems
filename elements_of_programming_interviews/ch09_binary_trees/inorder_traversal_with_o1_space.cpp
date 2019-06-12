// =====================================================
// Book: Elements of programming interviews
// Problem 9.5: In-order Traversal with O(1) space
// =====================================================

#include <iostream>
#include <memory>

using namespace std;

template<typename T>
class BinTree {
 public:
  T value;
  shared_ptr< BinTree<T> > lft;
  shared_ptr< BinTree<T> > rgt;

  BinTree(
    T value,
    shared_ptr< BinTree<T> > lft, 
    shared_ptr< BinTree<T> > rgt
  ) : value(value), lft(lft), rgt(rgt) {}
}; 

// The morris algorithm prints the nodes of a binary tree
// in order using O(1) space. The parent nodes are stored
// in the right most child rgt pointer. O(n) time complexity.
void morris_traversal(shared_ptr< BinTree<int> > r) {
  while (r) {
    if (r->lft) {
      shared_ptr< BinTree<int> > tmp = r->lft;
      while (tmp->rgt && tmp->rgt != r)
        tmp = tmp->rgt;
    
      if (tmp->rgt == r) {
        cout << r->value << endl;
        tmp->rgt = nullptr;
        r = r->rgt;
      } else {
        tmp->rgt = r;
        r = r->lft;
      }
    } else {
      cout << r->value << endl;
      r = r->rgt;
    }
  }
}

int main() {
  shared_ptr< BinTree<int> > g = make_shared< BinTree<int> >(7, nullptr, nullptr);
  shared_ptr< BinTree<int> > f = make_shared< BinTree<int> >(5, nullptr, nullptr);
  shared_ptr< BinTree<int> > e = make_shared< BinTree<int> >(3, nullptr, nullptr);
  shared_ptr< BinTree<int> > d = make_shared< BinTree<int> >(1, nullptr, nullptr);
  shared_ptr< BinTree<int> > c = make_shared< BinTree<int> >(6, f, g);
  shared_ptr< BinTree<int> > b = make_shared< BinTree<int> >(2, d, e);
  shared_ptr< BinTree<int> > a = make_shared< BinTree<int> >(4, b, c);

  morris_traversal(a);
  cout << "Should print 1, 2, 3, 4, 5, 6, 7." << endl;
  return 0;
}
