// =====================================================
// Book: Elements of programming interviews
// Problem 15.15: Score combinations
// =====================================================

#include <iostream>
#include <vector>

using namespace std;

// Top down dynamic programming approach to solve the score combination 
// problem.
int count_combinations(int s, vector<int> W) {
  if (s <= 0) return 0; 

  vector<int> table = vector<int>(s+1, 0);
  table[0] = 1;

  for (auto& w : W) {
    for (int i = w; i <= s; i++)
      table[i] += table[i - w];
  }

  int result = table[s];
  return result;
}

int main() {
  vector<int> W { 2, 3, 7 };
  cout << count_combinations(12, W) << " should be 4." << endl;
  cout << count_combinations(5, W) << " should be 1." << endl;
  return 0;
}
