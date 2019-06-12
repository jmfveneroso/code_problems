// =====================================================
// Book: Elements of programming interviews
// Problem 14.12: BST from in-order traversal
// =====================================================

#include <iostream>
#include <memory>
#include <vector>
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

shared_ptr< BinTree<int> > bst_from_preorder(
  vector<int>& preorder, size_t& i, int min, int max
) {
  if (i == preorder.size()) return nullptr;

  int current = preorder[i];
  if (current < min || current > max) return nullptr;

  ++i;
  shared_ptr< BinTree<int> > lft = bst_from_preorder(preorder, i, min, current);
  shared_ptr< BinTree<int> > rgt = bst_from_preorder(preorder, i, current, max);

  shared_ptr< BinTree<int> > root = make_shared< BinTree<int> >(
    current, lft, rgt
  );
  return root;
}

void preorder_traversal(shared_ptr< BinTree<int> > node) {
  if (!node) return;
  cout << node->value << " ";
  preorder_traversal(node->lft);
  preorder_traversal(node->rgt);
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
  vector<int> preorder { 37, 29, 23, 31, 43, 41, 47 };

  size_t i = 0;
  shared_ptr< BinTree<int> > root = bst_from_preorder(
    preorder, i, numeric_limits<int>::min(), numeric_limits<int>::max()
  );

  preorder_traversal(root);
  cout << "should be 37 29 23 31 43 41 47." << endl;
  return 0;
}
