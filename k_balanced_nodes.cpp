// =====================================================
// Book: Elements of programming interviews
// Problem 9.2: K-balanced nodes
// =====================================================

#include <iostream>
#include <memory>
#include <cstdlib>

using namespace std;

template<typename T>
class BinTree {
 public:
  BinTree(
    T value, 
    shared_ptr< BinTree<T> > lft, 
    shared_ptr< BinTree<T> > rgt) : 
    value(value), lft(lft), rgt(rgt) {
  }

  T value;
  shared_ptr< BinTree<T> > lft;
  shared_ptr< BinTree<T> > rgt;
};

using IntTree = shared_ptr< BinTree<int> >;

// Traverses a binary tree checking for unbalanced nodes.
// On worst case it has to check all nodes. O(n) time 
// complexity. O(log(n)) space complexity.
IntTree k_balanced_nodes(
  IntTree node, int k, int& child_count
) {
  if (node == nullptr) return nullptr;
 
  int lft_count = 0;
  int rgt_count = 0;
  IntTree lft = k_balanced_nodes(node->lft, k, lft_count);
  IntTree rgt = k_balanced_nodes(node->rgt, k, rgt_count);

  if (lft) return lft;
  if (rgt) return rgt;
  if (abs(lft_count - rgt_count) > k) return node; 

  child_count = 1 + lft_count + rgt_count;
  return nullptr;
}

int main() {
  /*         
              Example tree:
                   37  
                /      \
              29        43 
            /    \
           23    31      
  */

  shared_ptr< BinTree<int> > d = make_shared< BinTree<int> >(23, nullptr, nullptr);
  shared_ptr< BinTree<int> > e = make_shared< BinTree<int> >(31, nullptr, nullptr);
  shared_ptr< BinTree<int> > b = make_shared< BinTree<int> >(29, d, e);

  shared_ptr< BinTree<int> > c = make_shared< BinTree<int> >(43, nullptr, nullptr);

  shared_ptr< BinTree<int> > a = make_shared< BinTree<int> >(37, b, c);

  int count = 0;
  shared_ptr< BinTree<int> > res = k_balanced_nodes(a, 1, count);

  cout << (res == a) << " should be true." << endl;
  return 0;
}
