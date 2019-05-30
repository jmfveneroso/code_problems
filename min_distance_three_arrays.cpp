// ========================================================
// Book: Elements of programming interviews
// Problem 14.16 : Minimum distance in three sorted arrays
// ========================================================

#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;

// Example function.
int min_distance(
  vector<int>& a, vector<int>& b, vector<int>& c,
  size_t& best_i, size_t& best_j, size_t& best_k
) {
  int min_distance = 99999;
  size_t i = 0, j = 0, k = 0;

  while (true) {
    size_t* min;
    int distance;
    if (a[i] <= b[j] && a[i] <= c[k]) {
      min = &i;
      distance = (b[j] > c[k]) ? abs(a[i] - b[j]) : abs(a[i] - c[k]);
      if (i+1 == a.size()) return min_distance;
    } else if (b[j] <= c[k]) { 
      min = &j;
      distance = (a[i] > c[k]) ? abs(b[j] - a[i]) : abs(b[j] - c[k]);
      if (j+1 == b.size()) return min_distance;
    } else {
      min = &k;
      distance = (a[i] > b[j]) ? abs(c[k] - a[i]) : abs(c[k] - b[j]);
      if (k+1 == c.size()) return min_distance;
    }

    *min += 1;
    if (distance < min_distance) {
      min_distance = distance;
      best_i = i;
      best_j = j;
      best_k = k;
    }
  }

  return 0;
}

ostream& operator<<(ostream& os, vector<int> x) {
  for (auto x_ : x) cout << x_ << " ";
  return os;
}

int main() {
  vector<int> a { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
  vector<int> b { -5, -3, -1, 0, 1, 3, 5, 7, 9  };
  vector<int> c { 4, 6, 8, 10, 12, 14, 16 };

  size_t i, j, k;
  cout << min_distance(a, b, c, i, j, k) << " should be 1." << endl;
  cout << "(" << i << ", " << j << ", " << k << ") should be (3, 5, 0)." << endl;
  return 0;
}
