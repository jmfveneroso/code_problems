// =====================================================
// Book: Elements of programming interviews
// Problem 13.6: Team photo day
// =====================================================

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool team_photo(vector<int>& a, vector<int>& b) {
  sort(a.begin(), a.end(), greater<int>());
  sort(b.begin(), b.end(), greater<int>());

  for (size_t i = 0; i < a.size(); i++)
    if (a[i] <= b[i]) return false;
  return true;
}

int main() {
  vector<int> a { 2, 5, 6, 7, 9, 3 };
  vector<int> b { 1, 4, 5, 6, 8, 2 };
  vector<int> c { 2, 4, 5, 6, 8, 2 };

  cout << team_photo(a, b) << " should be true." << endl;
  cout << team_photo(a, c) << " should be false." << endl;
  return 0;
}
