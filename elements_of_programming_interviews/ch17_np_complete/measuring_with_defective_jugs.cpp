// =====================================================
// Book: Elements of programming interviews
// Problem 17.4: Measuring with defective jugs
// =====================================================

#include <iostream>
#include <unordered_set>
#include <functional>
#include <vector>

using namespace std;

class Jug {
 public:
  int id;
  int min, max;
};

class Compare {
 public:
  bool operator()(
    const pair<int, int>& a, const pair<int, int>& b
  ) const {
    return a.first == b.first && a.second == b.second;
  }
};

class HashPair {
 public:
  size_t operator()(
    const pair<int, int>& a
  ) const {
    return hash<int>()(a.first) ^ hash<int>()(a.second);
  }
};

// Brute force check caching results. Exponential complexity.
bool check_feasibility(
  int min, int max,
  vector<Jug>& jugs,
  unordered_set< pair<int, int>, HashPair, Compare >& cache,
  vector<int>& result
) {
  if (min < 0 || max < min) return false;
  if (cache.find({ min, max }) != cache.end()) return false;

  for (auto& j : jugs) {
    if (j.min > min && j.max < max) {
      result.push_back(j.id);
      return true;
    }

    bool feasible = check_feasibility(
      min - j.min, max - j.max, jugs, cache, result
    );

    if (feasible) { 
      result.push_back(j.id);
      return true;
    }
  }
  cache.insert({ min, max });
  return false;
}

ostream& operator<<(ostream& os, vector<int>& arr) {
  for (auto& x : arr)
    cout << x << " ";
  return os;
}

int main() {
  unordered_set< pair<int, int>, HashPair, Compare > cache;
  vector<Jug> jugs { {1, 230, 240}, {2, 290, 310}, {3, 500, 515} };
  vector<int> result;

  cout << check_feasibility(2100, 2300, jugs, cache, result) << " should be true." << endl;
  cout << "Feasible sequence: " << result << endl;

  int min = 0, max = 0;
  for (auto& x : result) {
    min += jugs[x-1].min;
    max += jugs[x-1].max;
  }

  cout << "Min: " << min << endl;
  cout << "Max: " << max << endl;
  return 0;
}
