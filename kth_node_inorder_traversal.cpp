// =====================================================
// Book: Elements of programming interviews
// Problem 9.6: K-th node in in-order traversal
// =====================================================

#include <iostream>
#include <memory>
#include <queue>

using namespace std;

template<typename T>
class BinTree {
 public:
  BinTree(
    T value, 
    shared_ptr< BinTree<T> > lft, 
    shared_ptr< BinTree<T> > rgt,
    int size
  ) : value(value), lft(lft), rgt(rgt), size(size) {
  }

  T value;
  shared_ptr< BinTree<T> > lft;
  shared_ptr< BinTree<T> > rgt;
  int size;
};

shared_ptr< BinTree<int> > kth_node(shared_ptr< BinTree<int> > node, int k) {
  int pre_index = 0;
  while (true) {
    int current_index = pre_index;
    if (node->lft)
      current_index = pre_index + node->lft->size;

    if (current_index == k) {
       return node;
    } else if (current_index > k) {
      node = node->lft;
    } else { 
      pre_index = current_index + 1;
      node = node->rgt;
    }
  }
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

  shared_ptr< BinTree<int> > d = make_shared< BinTree<int> >(23, nullptr, nullptr, 1);
  shared_ptr< BinTree<int> > e = make_shared< BinTree<int> >(31, nullptr, nullptr, 1);
  shared_ptr< BinTree<int> > b = make_shared< BinTree<int> >(29, d, e, 3);

  shared_ptr< BinTree<int> > g = make_shared< BinTree<int> >(41, nullptr, nullptr, 1);
  shared_ptr< BinTree<int> > f = make_shared< BinTree<int> >(47, nullptr, nullptr, 1);
  shared_ptr< BinTree<int> > c = make_shared< BinTree<int> >(43, g, f, 3);

  shared_ptr< BinTree<int> > a = make_shared< BinTree<int> >(37, b, c, 7);

  shared_ptr< BinTree<int> > k = kth_node(a, 2);
  cout << (k == e) << " should be true." << endl;

  k = kth_node(a, 5);
  cout << (k == c) << " should be true." << endl;
  return 0;
}
