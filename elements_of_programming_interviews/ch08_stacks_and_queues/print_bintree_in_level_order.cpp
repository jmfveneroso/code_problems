// =====================================================
// Book: Elements of programming interviews
// Problem 8.9: Printing binary tree in level order
// =====================================================

#include <iostream>
#include <memory>
#include <queue>

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

void print_bin_tree_in_level_order(shared_ptr< BinTree<int> > r) {
  if (r == nullptr) return;

  queue< int > level;
  queue< shared_ptr< BinTree<int> > > q;
  q.push(r);
  level.push(0);
  while (!q.empty()) {
    if (q.front()->lft != nullptr) {
      q.push(q.front()->lft);
      level.push(level.front() + 1);
    }

    if (q.front()->rgt != nullptr) {
      q.push(q.front()->rgt);
      level.push(level.front() + 1);
    }

    cout << q.front()->value << " at level " << level.front() << endl;
    q.pop();
    level.pop();
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

  print_bin_tree_in_level_order(a);
  return 0;
}
