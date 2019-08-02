#include <iostream>
#include <memory>
#include <vector>
#include <queue>

using namespace std;

class Node {
 public:
  int value;
  shared_ptr<Node> lft, rgt, parent;
  bool black;

  Node() {}

  Node(int value) 
    : value(value), lft(nullptr), rgt(nullptr), parent(nullptr), black(false) {
  }
};

int GetDepth(shared_ptr<Node> node) {
  if (!node) return 0;

  queue< pair<shared_ptr<Node>, int> > q;
  q.push({ node, 1 });

  int depth = 0;
  while (!q.empty()) {
    pair<shared_ptr<Node>, int> cur = q.front();
    q.pop();

    depth = max(depth, cur.second); 
    if (cur.first->lft)
      q.push({ cur.first->lft, cur.second + 1 });
    if (cur.first->rgt)
      q.push({ cur.first->rgt, cur.second + 1 });
  }
  return depth;
}

void PrintTreeAux(
  shared_ptr<Node> node, int pos, int depth, int max_depth, vector< vector< shared_ptr<Node> > >& draw_matrix
) {
  draw_matrix[depth-1][pos] = node;

  int step = (1 << (max_depth-depth-1));
  if (node->lft)
    PrintTreeAux(node->lft, pos - step, depth+1, max_depth, draw_matrix);
  if (node->rgt)
    PrintTreeAux(node->rgt, pos + step, depth+1, max_depth, draw_matrix);
}

void PrintTree(shared_ptr<Node> node) {
  if (!node) return;

  int max_depth = GetDepth(node);
  int width = (1 << max_depth);

  vector< vector< shared_ptr<Node> > > draw_matrix(max_depth, vector< shared_ptr<Node> >(width, nullptr));
  PrintTreeAux(node, width / 2, 1, max_depth, draw_matrix);

  for (int i = 0; i < max_depth; i++) {
    for (int j = 0; j < width; j++) {
      if (draw_matrix[i][j]) {
        shared_ptr<Node> parent = draw_matrix[i][j]->parent;
        cout << " " << draw_matrix[i][j]->value;
      } else {
        int step = 1 << (max_depth-i-1);
        if (j >= step && j <= width - step)
          cout << " -";
        else
          cout << "  ";
      }
    }

    cout << endl;
    if (i < max_depth - 1) {
      for (int j = 0; j < width; j++) {
        int step = 1 << (max_depth-i-2);
        if (j >= step && j <= width - step) {
          if (draw_matrix[i+1][j]) {
            cout << " +";
          } else {
            cout << " -";
          }
        } else {
          cout << "  ";
        }
      }
      cout << endl;
    }
  }
}

class BinaryTree {
 shared_ptr<Node> root_; 

  void Recolor(shared_ptr<Node> new_node) {
    // Is root.
    if (!new_node->parent) {
      new_node->black = true;
      return;
    }

    // Parent is black.
    shared_ptr<Node> parent = new_node->parent;
    if (parent->black)
      return;

    // Since the parent is red, the grandparent must exist,
    // because the root is always black. Also, the grandparent must 
    // be black.
    shared_ptr<Node> grand_parent = parent->parent;
    shared_ptr<Node> uncle = grand_parent->lft;
    if (uncle == parent) uncle = grand_parent->rgt;

    // Uncle is black.
    if (!uncle || uncle->black) {
      // Left right case. Transform in left left case.
      if (grand_parent->lft == parent && new_node == parent->rgt) {
        cout << "Node a: " << new_node->value << endl;
        new_node->parent = grand_parent; 
        parent->parent = new_node; 
        parent->rgt = new_node->lft;
        if (new_node->lft) new_node->lft->parent = parent;

        new_node->lft = parent; 
        grand_parent->lft = new_node;

        shared_ptr<Node> tmp = new_node;
        new_node = parent;
        parent = tmp;
      }

      // Right left case.
      else if (grand_parent->rgt == parent && new_node == parent->lft) {
        cout << "Node b: " << new_node->value << endl;
        new_node->parent = grand_parent; 
        parent->parent = new_node; 
        parent->lft = new_node->rgt;
        if (new_node->rgt) new_node->rgt->parent = parent;

        new_node->rgt = parent; 
        grand_parent->rgt = new_node;

        shared_ptr<Node> tmp = new_node;
        new_node = parent;
        parent = tmp;
      }

      // Left left case.
      if (grand_parent->lft == parent && new_node == parent->lft) {
        cout << "Node c: " << new_node->value << endl;
        shared_ptr<Node> tmp = grand_parent->parent;
        grand_parent->parent = parent; 
        parent->parent = tmp; 
        grand_parent->lft = parent->rgt; 
        if (parent->rgt) parent->rgt->parent = grand_parent;
        parent->rgt = grand_parent;
        grand_parent->black = false; 
        parent->black = true;

        if (!tmp)
          root_ = parent;
        else if (tmp->lft == grand_parent)
          tmp->lft = parent;
        else if (tmp->rgt == grand_parent)
          tmp->rgt = parent;
      }

      // Right right case.
      else if (grand_parent->rgt == parent && new_node == parent->rgt) {
        shared_ptr<Node> tmp = grand_parent->parent;
        grand_parent->parent = parent; 
        parent->parent = tmp; 
        grand_parent->rgt = parent->lft; 
        if (parent->lft) parent->lft->parent = grand_parent;
        parent->lft = grand_parent;

        grand_parent->black = false; 
        parent->black = true;

        if (!tmp)
          root_ = parent;
        else if (tmp->lft == grand_parent)
          tmp->lft = parent;
        else if (tmp->rgt == grand_parent)
          tmp->rgt = parent;
      }

      return;
    } 
    
    // Uncle is red.
    parent->black = true;
    uncle->black = true;
    grand_parent->black = false;
    Recolor(grand_parent);
  }

 public:
  BinaryTree() {}

  shared_ptr<Node> root() { return root_; }

  void Insert(int value) {
    if (!root_) {
      root_ = make_shared<Node>(value);
      root_->black = true;
      return;
    }

    shared_ptr<Node> current = root_;
    while (current) {
      if (current->value == value)
        return;

      if (value < current->value) {
        if (!current->lft) {
          current->lft = make_shared<Node>(value);
          current->lft->parent = current;

          if (current->black)
            return;
          else
            Recolor(current->lft);
        }
        current = current->lft;
      } else {
        if (!current->rgt) {
          current->rgt = make_shared<Node>(value);
          current->rgt->parent = current;
          if (current->black)
            return;
          else
            Recolor(current->rgt);
        }
        current = current->rgt;
      }
    }
  }

  void FixDoubleBlack(shared_ptr<Node> node) {
    if (node == root_)
      return;

    shared_ptr<Node> parent = node->parent;
    shared_ptr<Node> sibling = parent->lft;
    if (sibling == node) sibling = parent->rgt;

    // Sibling is red.
    if (!sibling->black) {
      // Sibling is left child.
      if (sibling == parent->lft) {
        shared_ptr<Node> tmp = parent->parent;
        parent->lft = sibling->rgt;
        if (sibling->rgt) sibling->rgt->parent = parent;
        sibling->rgt = parent;
        sibling->parent = tmp;
        parent->parent = sibling;

        if (!tmp)
          root_ = sibling;
        else if (tmp->lft == parent)
          tmp->lft = sibling;
        else
          tmp->rgt = sibling;
      } 

      // Sibling is right child.
      else {
        shared_ptr<Node> tmp = parent->parent;
        parent->rgt = sibling->lft;
        if (sibling->lft) sibling->lft->parent = parent;
        sibling->lft = parent;
        sibling->parent = tmp;
        parent->parent = sibling;

        if (!tmp)
          root_ = sibling;
        else if (tmp->lft == parent)
          tmp->lft = sibling;
        else
          tmp->rgt = sibling;
      }

      parent->black = false;
      sibling->black = true;

      //FixDoubleBlack(node);
      return;
    }

    // Sibling is black.
    if (sibling->black) {
      shared_ptr<Node> s_1 = sibling->lft;
      shared_ptr<Node> s_2 = sibling->rgt;

      // Both children are black.
      if ((!s_1 || s_1->black) && (!s_2 || s_2->black)) {
        sibling->black = false;
    
        if (parent->black)
          FixDoubleBlack(parent);
        return;
      }

      // Right left case. Transform in right right case.
      if (sibling == parent->rgt && s_1 && !s_1->black) {
        shared_ptr<Node> tmp = s_1->rgt;
        parent->rgt = s_1; 
        s_1->rgt = sibling;
        sibling->lft = tmp;
        if (tmp) tmp->parent = sibling;
        s_1->parent = parent;
        sibling->parent = s_1;
        
        sibling = s_1; 
        s_1 = sibling->lft;
        s_2 = sibling->rgt;
      } 

      // Left right case. Transform in left left case.
      else if (sibling == parent->lft && s_2 && !s_2->black) {
        shared_ptr<Node> tmp = s_2->lft;
        parent->lft = s_2; 
        s_2->lft = sibling;
        sibling->rgt = tmp;
        if (tmp) tmp->parent = sibling;
        s_2->parent = parent;
        sibling->parent = s_2;
        
        sibling = s_2; 
        s_1 = sibling->lft;
        s_2 = sibling->rgt;
      }

      // Left left case.
      if (sibling == parent->lft && s_1 && !s_1->black) {
        shared_ptr<Node> tmp = parent->parent;
        parent->lft = sibling->rgt;
        if (sibling->rgt) sibling->rgt->parent = parent;
        sibling->rgt = parent;
        sibling->parent = tmp;
        parent->parent = sibling;
        s_1->black = true;

        if (!tmp)
          root_ = sibling;
        else if (tmp->lft == parent)
          tmp->lft = sibling;
        else 
          tmp->rgt= sibling;
      }
      // Right right case.
      else if (sibling == parent->rgt && s_2 && !s_2->black) {
        shared_ptr<Node> tmp = parent->parent;
        parent->rgt = sibling->lft;
        if (sibling->lft) sibling->lft->parent = parent;
        sibling->lft = parent;
        sibling->parent = tmp;
        parent->parent = sibling;
        s_2->black = true;

        if (!tmp)
          root_ = sibling;
        else if (tmp->lft == parent)
          tmp->lft = sibling;
        else 
          tmp->rgt= sibling;
      }
      return;    
    }
  }

  void RemoveRecolor(shared_ptr<Node> node) {
    shared_ptr<Node> parent = node->parent;
    shared_ptr<Node> child = nullptr;

    if (node->lft)
      child = node->lft;
    else
      child = node->rgt;

    // Node is red.
    if (!node->black) {
      if (parent->lft == node)
        parent->lft = child;
      else
        parent->rgt = child;

      if (child)
        child->parent = parent;
      return;
    }

    // Child is red.
    if (child && !child->black) {
      child->parent = parent;
      child->black = true;
      if (parent->lft == node)
        parent->lft = child;
      else
        parent->rgt = child;
      return;
    }

    // Both child and node are black.
    FixDoubleBlack(node);
    if (parent->lft == node)
      parent->lft = child;
    else
      parent->rgt = child;
  }

  void RemoveNode(shared_ptr<Node> current) {
    if (!current) return;

    if (current->lft && current->rgt) {
      shared_ptr<Node> successor = current->rgt;
      while (successor->lft) successor = successor->lft;

      current->value = successor->value;
      RemoveNode(successor);
      return;
    }

    RemoveRecolor(current);
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

  void PrintNodeIn(shared_ptr<Node> node) {
    if (!node) 
      return; 

    PrintNodeIn(node->lft);
    cout << node->value << "";
    cout << ((node->black) ? "B" : "R") << " ";
    PrintNodeIn(node->rgt);
  }

  void PrintIn() {
    PrintNodeIn(root_);
  }
};

ostream& operator<<(ostream& os, BinaryTree& bt) {
  bt.PrintIn();
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
  bt.Insert(8);
  bt.Insert(9);
  bt.Insert(8);
  cout << bt << "should be 1 2 3 4 5 6 7 8 9" << endl;

  PrintTree(bt.root());
  cout << endl;

  cout << endl << "Remove 7:" << endl;
  bt.Remove(7);
  PrintTree(bt.root());
  cout << endl;

  cout << endl << "Remove 4:" << endl;
  bt.Remove(4);
  PrintTree(bt.root());

  cout << endl << "Insert 7:" << endl;
  bt.Insert(7);
  PrintTree(bt.root());

  cout << endl << "Insert 4:" << endl;
  bt.Insert(4);
  PrintTree(bt.root());

  cout << endl << "Insert 10:" << endl;
  bt.Insert(10);
  PrintTree(bt.root());

  cout << endl << "Remove 8:" << endl;
  bt.Remove(8);
  PrintTree(bt.root());

  cout << endl << "Remove 5:" << endl;
  bt.Remove(5);
  PrintTree(bt.root());
  return 0;
}
