// =====================================================
// Book: Elements of programming interviews
// Problem 8.3: Printing the keys in BST
// =====================================================

#include <iostream>
#include <memory>
#include <stack>

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

void print_keys_in_bst(shared_ptr< BinTree<int> > r) {
  if (r == nullptr) return;

  stack< shared_ptr< BinTree<int> > > s;
  s.push(r);
  while (!s.empty()) {
    if (s.top()->lft != nullptr) {
      shared_ptr< BinTree<int> > cur = s.top();
      s.push(cur->lft);
      cur->lft = nullptr;
    } else if (s.top()->rgt != nullptr) { 
      shared_ptr< BinTree<int> > cur = s.top();
      cout << cur->value << endl;
      s.pop();
      s.push(cur->rgt);
    } else {
      cout << s.top()->value << endl;
      s.pop();
    }
  }
}

void print_keys_in_bst2(shared_ptr< BinTree<int> > r) {
  shared_ptr< BinTree<int> > cur = r;
  stack< shared_ptr< BinTree<int> > > s;

  while (!s.empty() || cur != nullptr) {
    while (cur != nullptr) {
      s.push(cur);
      cur = cur->lft;
    }
  
    cout << s.top()->value << endl;

    if (s.top()->rgt != nullptr)
      cur = s.top()->rgt;
    s.pop();
  }
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

  shared_ptr< BinTree<int> > d = make_shared< BinTree<int> >(23, nullptr, nullptr);
  shared_ptr< BinTree<int> > e = make_shared< BinTree<int> >(31, nullptr, nullptr);
  shared_ptr< BinTree<int> > b = make_shared< BinTree<int> >(29, d, e);

  shared_ptr< BinTree<int> > g = make_shared< BinTree<int> >(41, nullptr, nullptr);
  shared_ptr< BinTree<int> > f = make_shared< BinTree<int> >(47, nullptr, nullptr);
  shared_ptr< BinTree<int> > c = make_shared< BinTree<int> >(43, g, f);

  shared_ptr< BinTree<int> > a = make_shared< BinTree<int> >(37, b, c);

  print_keys_in_bst2(a);
  cout << "=====================" << endl;
  print_keys_in_bst(a);
  return 0;
}
