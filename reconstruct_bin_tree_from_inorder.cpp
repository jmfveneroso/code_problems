// ============================================================
// Book: Elements of programming interviews
// Problem 9.8: Reconstructing Binary Tree from Traversal Data
// ============================================================

#include <iostream>
#include <vector>
#include <memory>

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

// Reconstructs a binary tree from the in-order representation with
// zero markers marking null pointers. Time complexity is O(n), each node
// is visited once.
shared_ptr< BinTree<int> > reconstruct_bin_tree(vector<int>& preorder, int& i) {
  int value = preorder[i++];
  if (value == 0) return nullptr;

  shared_ptr< BinTree<int> > cur = make_shared< BinTree<int> >(value, nullptr, nullptr);
  cur->lft = reconstruct_bin_tree(preorder, i);
  cur->rgt = reconstruct_bin_tree(preorder, i);
  return cur;
}

void print_preorder(
  shared_ptr< BinTree<int> > node
) {
  if (node == nullptr) return;

  cout << node->value << ", ";
  print_preorder(node->lft);
  print_preorder(node->rgt);
}

int main() {
  vector<int> preorder { 8, 2, 6, 0, 0, 5, 1, 0, 0, 0, 3, 0, 4, 0, 7, 9, 0, 0, 0 };

  int i = 0;
  shared_ptr< BinTree<int> > root = reconstruct_bin_tree(preorder, i);
  print_preorder(root); cout << "should be 8, 2, 6, 5, 1, 3, 4, 7, 9" << endl;
  return 0;
}
