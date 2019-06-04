// ==========================================================
// Book: Elements of programming interviews
// Problem 14.7: Build minimum height tree from sorted array
// ==========================================================

#include <iostream>
#include <memory>
#include <vector>

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

shared_ptr< BinTree<int> > build_tree(
  vector<int>& arr, int i, int j
) {
  if (i > j) return nullptr;
  int mid = i + (j - i) / 2;
  return make_shared< BinTree<int> >(
    arr[mid], 
    build_tree(arr, i, mid-1),
    build_tree(arr, mid+1, j)
  );
}

int get_tree_depth(shared_ptr< BinTree<int> > node, int depth = 0) {
  if (node == nullptr) return depth;

  depth++;
  return max(
    get_tree_depth(node->lft, depth),
    get_tree_depth(node->rgt, depth)
  );
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
                   108  
                /      \
              108       285
            /     \   /     \
          -10    108 243    285
         /    \               \
        -14   2               401
  */

  vector<int> arr { -14, -10, 2, 108, 108, 108, 243, 285, 285, 401 };
  shared_ptr< BinTree<int> > root = build_tree(arr, 0, arr.size()-1);
  cout << get_tree_depth(root) << " should be 4." << endl;
  return 0;
}
