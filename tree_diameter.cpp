// =====================================================
// Book: Elements of programming interviews
// Problem 15.4: Tree diameter
// =====================================================

#include <iostream>
#include <vector>
#include <memory>
#include <queue>
#include <algorithm>

using namespace std;

template<typename T>
class Tree {
 public:
  T value;
  vector< shared_ptr< Tree<T> > > children;

  Tree() {}
  Tree(T value, vector< shared_ptr< Tree<T> > > children) 
    : value(value), children(children) {
  }
};

pair<int, int> tree_diameter(shared_ptr< Tree<int> > node) {
  priority_queue<int> q;

  int max_found = 0;
  for (auto& c : node->children) {
    pair<int, int> p = tree_diameter(c);
    int dis = p.first;
    if (p.second > max_found) max_found = p.second;

    if (q.size() < 2)
      q.push(dis);
    else if (dis > q.top()) {
      q.pop();
      q.push(dis);
    }
  }

  if (q.empty()) return { node->value, max_found };

  int first = q.top(); 
  q.pop();

  if (q.empty()) return { node->value + first, max_found };
  int second = q.top();

  if (first + second > max_found)
    max_found = first + second;

  return { node->value + first, max_found };
}

int main() {
  shared_ptr< Tree<int> > root = make_shared< Tree<int> >(
    0, vector< shared_ptr< Tree<int> > >({
    make_shared< Tree<int> >(
      1, vector< shared_ptr< Tree<int> > >({
      make_shared< Tree<int> >(
        7, vector< shared_ptr< Tree<int> > >({
        make_shared< Tree<int> >(
          4 , vector< shared_ptr< Tree<int> > >({
          make_shared< Tree<int> >(6, vector< shared_ptr< Tree<int> > >())
        })),
        make_shared< Tree<int> >(
          3, vector< shared_ptr< Tree<int> > >()
        )
      })),
      make_shared< Tree<int> >(
        14, vector< shared_ptr< Tree<int> > >()
      ),
      make_shared< Tree<int> >(
        3, vector< shared_ptr< Tree<int> > >({
        make_shared< Tree<int> >(
          2 , vector< shared_ptr< Tree<int> > >()),
        make_shared< Tree<int> >(
          1, vector< shared_ptr< Tree<int> > >({
          make_shared< Tree<int> >(6, vector< shared_ptr< Tree<int> > >())
        }))
      })),
    })),
  }));

  cout << tree_diameter(root).second << " should be 31." << endl;
  return 0;
}
