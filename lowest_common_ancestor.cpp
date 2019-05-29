// ============================================================
// Book: Elements of programming interviews
// Problem 9.12: Lowest common ancestor
// ============================================================

#include <iostream>
#include <vector>
#include <memory>
#include <queue>
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

// Reconstructs a binary tree from the in-order representation
// and pre-order representation of nodes. O(n) time complexity.
shared_ptr< BinTree<int> > lowest_common_ancestor(
  shared_ptr< BinTree<int> > root,
  shared_ptr< BinTree<int> > a,
  shared_ptr< BinTree<int> > b
) {
  stack< shared_ptr< BinTree<int> > > s;
  queue< shared_ptr< BinTree<int> > > q;
  q.push(root);

  while (!q.empty()) {
    shared_ptr< BinTree<int> > cur = q.front();
    q.pop();

    if (cur->lft) q.push(cur->lft);
    if (cur->rgt) q.push(cur->rgt);
   
    cout << cur->value << endl;
    s.push(cur);
  }

  shared_ptr< BinTree<int> > a_tmp = a;
  shared_ptr< BinTree<int> > b_tmp = b;

  while (!s.empty()) {
    shared_ptr< BinTree<int> > cur = s.top();
    s.pop();

    if (cur->lft == a_tmp || cur->rgt == a_tmp) a_tmp = cur;
    if (cur->lft == b_tmp || cur->rgt == b_tmp) b_tmp = cur;
   
    if (a_tmp == b_tmp) return a_tmp; 
  }
  return nullptr;
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

  shared_ptr< BinTree<int> > res = lowest_common_ancestor(a, d, e);
  cout << (res == b) << " should be true." << endl;

  res = lowest_common_ancestor(a, d, f);
  cout << (res == a) << " should be true." << endl;

  res = lowest_common_ancestor(a, b, d);
  cout << (res == b) << " should be true." << endl;
  return 0;
}
