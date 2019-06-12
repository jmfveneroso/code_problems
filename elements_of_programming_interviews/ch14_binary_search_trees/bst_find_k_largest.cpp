// =====================================================
// Book: Elements of programming interviews
// Problem 14.11: Find K largest elements in BST
// =====================================================

#include <iostream>
#include <memory>
#include <vector>
#include <stack>

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

void find_k_largest(shared_ptr< BinTree<int> > node, int k, int& count) {
  if (node == nullptr) return;

  find_k_largest(node->rgt, k, count);
  if (count == k) return;
 
  cout << node->value << " "; 
  count++;

  find_k_largest(node->lft, k, count);
}

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

int main() {
  vector<int> arr { 
    2, 3, 5, 7, 11, 13, 17, 19, 23, 
    29, 31, 37, 41, 43, 47, 53
  };
  shared_ptr< BinTree<int> > root = build_tree(arr, 0, arr.size()-1);

  int i = 0;
  find_k_largest(root, 3, i);
  cout << "should be 53 47 43." << endl;
  return 0;
}
