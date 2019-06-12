// =====================================================
// Book: Elements of programming interviews
// Problem 14.4: get first k from BST
// =====================================================

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

shared_ptr< BinTree<int> > get_first_k(
  shared_ptr< BinTree<int> > node, int k
) {
  shared_ptr< BinTree<int> > result = nullptr;

  while (node) {
    if (node->value == k) {
      result = node;
      node = node->lft;
    } else if (node->value < k) {
      node = node->rgt;
    } else {
      node = node->lft;
    }
  }
  return result;
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

  shared_ptr< BinTree<int> > root = make_shared< BinTree<int> >(108, 
    make_shared< BinTree<int> >(108,
      make_shared< BinTree<int> >(-10,
        make_shared< BinTree<int> >(-14, nullptr, nullptr),
        make_shared< BinTree<int> >(-2, nullptr, nullptr)
      ),
      make_shared< BinTree<int> >(108, nullptr, nullptr)
    ),
    make_shared< BinTree<int> >(285,
      make_shared< BinTree<int> >(243, nullptr, nullptr),
      make_shared< BinTree<int> >(285, 
        make_shared< BinTree<int> >(401, nullptr, nullptr),
        nullptr
      )
    )
  );

  preorder_traversal(root);
  cout << "should be 108 108 -10 -14 2 108 285 243 285 401." << endl;

  shared_ptr< BinTree<int> > node = get_first_k(root, 108);
  cout << (node == root->lft) << " should be true." << endl;
  node = get_first_k(root, 285);
  cout << (node == root->rgt) << " should be true." << endl;
  node = get_first_k(root, 143);
  cout << (node == nullptr) << " should be true." << endl;
  return 0;
}
