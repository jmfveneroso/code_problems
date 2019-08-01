#include <iostream>
#include <memory>
#include <vector>

using namespace std;

class Node {
 public:
  shared_ptr<Node> lft, rgt, parent;
  int value;

  Node() {}

  Node(int value) 
    : value(value), lft(nullptr), rgt(nullptr), parent(nullptr) {
  }
};

class BinaryTree {
 shared_ptr<Node> root_; 

 public:
  BinaryTree() {}

  void Insert(int value) {
    if (!root_)
      root_ = make_shared<Node>(value);

    shared_ptr<Node> current = root_;
    while (current) {
      if (current->value == value)
        return;

      if (value < current->value) {
        if (!current->lft) {
          current->lft = make_shared<Node>(value);
          current->lft->parent = current;
          return;
        }
        current = current->lft;
      } else {
        if (!current->rgt) {
          current->rgt = make_shared<Node>(value);
          current->rgt->parent = current;
          return;
        }
        current = current->rgt;
      }
    }
  }

  bool Find(int value) {
    shared_ptr<Node> current = root_; 
    while (current) {
      if (current->value == value)
        return true;

      if (value < current->value)
        current = current->lft;
      else
        current = current->rgt;
    }
    return false;
  }

  void RemoveNode(shared_ptr<Node> current) {
    // Is leaf.
    if (!current->lft && !current->rgt) {
      if (current->parent->lft == current)
        current->parent->lft = nullptr;
      else
        current->parent->rgt = nullptr;
      return;
    }

    // Has only one child, the right node.
    if (!current->lft) {
      if (current->parent->lft == current)
        current->parent->lft = current->rgt;
      else
        current->parent->rgt = current->rgt;
      current->rgt->parent = current->parent;
      return;
    } 

    // Has only one child, the left node.
    if (!current->rgt) {
      if (current->parent->lft == current)
        current->parent->lft = current->lft;
      else
        current->parent->rgt = current->lft;
      current->lft->parent = current->parent;
      return;
    }

    shared_ptr<Node> successor = current->rgt;
    while (successor->lft) successor = successor->lft;

    current->value = successor->value;
    RemoveNode(successor);
  } 

  void Remove(int value) {
    shared_ptr<Node> current = root_; 
    while (current) {
      if (current->value == value)
        break;

      if (value < current->value)
        current = current->lft;
      else
        current = current->rgt;
    }

    if (current)
      RemoveNode(current);
  }

  void PrintNodePre(shared_ptr<Node> node) {
    if (!node) 
      return; 

    cout << node->value << " ";
    PrintNodePre(node->lft);
    PrintNodePre(node->rgt);
  }

  void PrintPre() {
    PrintNodePre(root_);
  }

  void PrintNodeIn(shared_ptr<Node> node) {
    if (!node) 
      return; 

    PrintNodeIn(node->lft);
    cout << node->value << " ";
    PrintNodeIn(node->rgt);
  }

  void PrintIn() {
    PrintNodeIn(root_);
  }
};

ostream& operator<<(ostream& os, BinaryTree& bt) {
  bt.PrintIn();
  cout << ": ";
  bt.PrintPre();
  return os;
}

int main() {
  BinaryTree bt;
  bt.Insert(2);
  bt.Insert(5);
  bt.Insert(3);
  bt.Insert(4);
  bt.Insert(1);
  bt.Insert(7);
  bt.Insert(6);

  cout << bt << "should be 1 2 3 4 5 9" << endl;
  return 0;
}
