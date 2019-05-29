// =====================================================
// Book: Elements of programming interviews
// Problem 8.4: Search Postings List
// =====================================================

#include <iostream>
#include <cstring>
#include <vector>
#include <memory>
#include <stack>

using namespace std;

template<typename T>
class PostingsList {
 public:
  PostingsList(
    T value,
    shared_ptr< PostingsList<T> > next,
    shared_ptr< PostingsList<T> > jump
  ) : order(-1), value(value), next(next), jump(jump) {}

  int order;
  T value;
  shared_ptr< PostingsList<T> > next;
  shared_ptr< PostingsList<T> > jump;
};

// Recursive solution.
void search_postings_list(shared_ptr< PostingsList<int> > x, int& order) {
  if (x != nullptr && x->order == -1) {
    x->order = order++;
    search_postings_list(x->jump, order);
    search_postings_list(x->next, order);
  }
}

// Iterative solution.
void search_postings_list2(shared_ptr< PostingsList<int> > x) {
  int order = 0;
  stack< shared_ptr< PostingsList<int> > > s;
  s.push(x);

  while (s.size()) {
    shared_ptr< PostingsList<int> > cur = s.top();
    s.pop();

    if (cur == nullptr || cur->order != -1) continue;

    cur->order = order++;
    s.push(cur->next);
    s.push(cur->jump);
  }
}

ostream& operator<<(ostream& os, shared_ptr< PostingsList<int> > x) {
  while (x != nullptr) {
    cout << "(" << x->order << ", " << x->value << ")";
    x = x->next;
    if (x != nullptr)
      cout << ", ";
  }
  return os;
}

int main() {
  shared_ptr< PostingsList<int> > d = make_shared< PostingsList<int> >(2, nullptr, d);
  shared_ptr< PostingsList<int> > c = make_shared< PostingsList<int> >(3, d, nullptr);
  shared_ptr< PostingsList<int> > b = make_shared< PostingsList<int> >(1, c, d);
  shared_ptr< PostingsList<int> > a = make_shared< PostingsList<int> >(0, b, b);
  c->jump = a;

  cout << a << endl;
  int order = 0;
  search_postings_list(a, order);
  cout << a << " should be 0, 1, 3, 2." << endl;

  shared_ptr< PostingsList<int> > tmp = a;
  while (tmp != nullptr) {
    tmp->order = -1;
    tmp = tmp->next;
  }

  cout << "===================" << endl;
  cout << a << endl;
  search_postings_list2(a);
  cout << a << " should be 0, 1, 3, 2." << endl;

  return 0;
}
