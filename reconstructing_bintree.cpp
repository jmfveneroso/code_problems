// ============================================================
// Book: Elements of programming interviews
// Problem 9.7: Reconstructing Binary Tree from Traversal Data
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

// Reconstructs a binary tree from the in-order representation
// and pre-order representation of nodes. O(n) time complexity.
shared_ptr< BinTree<int> > reconstruct_bin_tree(
  vector<int>& preorder,
  vector<int>& inorder, 
  int preorder_i,
  int inorder_i,
  int inorder_j
) {
  if (inorder_i >= inorder_j) return nullptr;

  int i = inorder_i;
  for (; i < inorder_j; i++) {
    if (inorder[i] == preorder[preorder_i])
      break;
  }

  shared_ptr< BinTree<int> > lft = nullptr;
  shared_ptr< BinTree<int> > rgt = nullptr;

  if (i > inorder_i)
    lft = reconstruct_bin_tree(
      preorder,
      inorder, 
      preorder_i + 1,
      inorder_i,
      i
    );

  if (i + 1 < inorder_j)
    rgt = reconstruct_bin_tree(
      preorder,
      inorder, 
      preorder_i + (i - inorder_i) + 1,
      i + 1,
      inorder_j
    );

  shared_ptr< BinTree<int> > current = make_shared< BinTree<int> >(
    preorder[preorder_i], lft, rgt
  );

  return current;
}

void print_inorder(
  shared_ptr< BinTree<int> > node
) {
  if (node == nullptr) return;

  print_inorder(node->lft);
  cout << node->value << ", ";
  print_inorder(node->rgt);
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
  vector<int> preorder { 8, 2, 6, 5, 1, 3, 4, 7, 9 };
  vector<int> inorder  { 6, 2, 1, 5, 8, 3, 4, 9, 7 };

  shared_ptr< BinTree<int> > root = reconstruct_bin_tree(preorder, inorder, 0, 0, 9);

  print_preorder(root); cout << "should be 8, 2, 6, 5, 1, 3, 4, 7, 9" << endl;
  print_inorder(root); cout << "should be 6, 2, 1, 5, 8, 3, 4, 9, 7" << endl;

  return 0;
}
