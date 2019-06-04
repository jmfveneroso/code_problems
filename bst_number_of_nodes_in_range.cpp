// =====================================================
// Book: Elements of programming interviews
// Problem 14.22: Number of  elements in range in BST
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
  int num_children;

  BinTree(
    T value,
    shared_ptr<BinTree> lft,
    shared_ptr<BinTree> rgt
  ) : value(value), lft(lft), rgt(rgt), num_children(0) {}
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

int calculate_children(shared_ptr< BinTree<int> > node) {
  if (node == nullptr) return 0;

  int lft_children = calculate_children(node->lft);
  int rgt_children = calculate_children(node->rgt);

  node->num_children = lft_children + rgt_children;
  return node->num_children + 1;
}

int nodes_in_range( 
  shared_ptr< BinTree<int> > node, 
  int min, int max, 
  int range_min, int range_max
) {
  if (!node) return 0;

  if (min >= range_min && max <= range_max) 
    return node->num_children + 1;

  int count = 0;
  if (node->value >= range_min && node->value <= range_max)
    count++;
  
  int lft_count = 0, rgt_count = 0;
  if (node->value >= range_min)
    lft_count = nodes_in_range(  
      node->lft,
      min, node->value, 
      range_min, range_max
    );

  if (node->value <= range_max)
    rgt_count = nodes_in_range(  
      node->rgt,
      node->value, max,
      range_min, range_max
    );

  return lft_count + rgt_count + count;
}

int main() {
  vector<int> arr { 
    2, 3, 5, 7, 11, 13, 17, 19, 23, 
    29, 31, 37, 41, 43, 47, 53
  };
  shared_ptr< BinTree<int> > root = build_tree(arr, 0, arr.size()-1);
  calculate_children(root);
  cout << root->num_children << " should be 15." << endl;

  cout << nodes_in_range(root, -1000, 1000, 13, 43) << " should be 9." << endl;
  cout << nodes_in_range(root, -1000, 1000, 3, 8) << " should be 3." << endl;
  cout << nodes_in_range(root, -1000, 1000, 36, 44) << " should be 3." << endl;
  return 0;
}
