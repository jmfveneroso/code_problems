// =====================================================
// Book: Elements of programming interviews
// Problem 13.12: Points covering intervals
// =====================================================

#include <iostream>
#include <set>
#include <vector>

using namespace std;

struct Interval {
  int l, r;
  Interval(int l, int r) : l(l), r(r) {}
};

class LeftComp {
 public:
  bool operator()(const Interval& lhs, const Interval& rhs) {
    return (lhs.l != rhs.l) ? lhs.l < rhs.l : lhs.r < rhs.r;
  }
};

class RightComp {
 public:
  bool operator()(const Interval& lhs, const Interval& rhs) {
    return (lhs.r != rhs.r) ? lhs.r < rhs.r : lhs.l < rhs.l;
  }
};

vector<int> find_points_covering_interval(vector<Interval> intervals) {
  set<Interval, LeftComp> lefts;
  set<Interval, RightComp> rights;

  for (auto& i : intervals) {
    lefts.insert(i), rights.insert(i);
  }

  vector<int> points;
  while (lefts.size() && rights.size()) {
    int min_right = rights.cbegin()->r;

    points.push_back(min_right);
    auto it = lefts.begin();
    while (it != lefts.end() && it->l <= min_right) {
      rights.erase(*it);
      lefts.erase(it++);
    }
  }
  return points;
}

ostream& operator<<(ostream& os, vector<int>& r) {
  for (auto& x : r) cout << x << " ";
  return os;
}

int main() {
  vector<Interval> intervals {
    Interval(0, 5),
    Interval(1, 6),
    Interval(2, 7),
    Interval(3, 4),
    Interval(6, 8),
    Interval(8, 9)
  };

  vector<int> r = find_points_covering_interval(intervals);
  cout << r << " should be 4 8." << endl;
  return 0;
}
