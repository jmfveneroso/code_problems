// =====================================================
// Book: Elements of programming interviews
// Problem 17.10: Computing x^n
// =====================================================

#include <iostream>
#include <limits>
#include <list>

using namespace std;

// Determine the minimum number of multiplications for computing x^n.
// Exponential complexity.
list<int> compute_min_mults(const int& n) {
  list<int> init_list;
  init_list.push_back(1);

  list< list<int> > exp_lists;
  exp_lists.push_back(init_list);

  list<int> min_exp;
  size_t shortest_size = numeric_limits<size_t>::max();

  while (exp_lists.empty() == false) {
    list<int> exp = exp_lists.front();
    exp_lists.pop_front();

    for (const int& i : exp) {
      for (const int& j : exp) {
        if (shortest_size <= exp.size() + 1) break;

        int sum = i + j;
        if (sum == n) {
          min_exp = exp;
          min_exp.push_back(sum);
          shortest_size = exp.size() + 1;
        } else if (sum < n && sum > exp.back()) {
          list<int> ext = exp;
          ext.push_back(sum);
          exp_lists.push_back(ext);
        }
      }
    }
  }

  return min_exp;
}

ostream& operator<<(ostream& os, list<int> l) {
  for (auto& x : l) cout << x << " ";
  return os;
}

int main() {
  cout << compute_min_mults(15) << endl;
  return 0;
}
