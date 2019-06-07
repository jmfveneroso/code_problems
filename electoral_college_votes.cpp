// =====================================================
// Book: Elements of programming interviews
// Problem 17.1: Electoral college votes
// =====================================================

#include <iostream>
#include <vector>

using namespace std;

// Basically the knapsack 0-1 problem.
bool is_feasible(vector<int>& states) {
  int total_delegates = 0;
  for (auto& s : states) total_delegates += s;

  if (total_delegates & 1) return false;

  int n = total_delegates / 2;
  vector<int> votes(n + 1, 0);
  votes[0] = 1;
  for (auto& s : states) {
    for (int i = n; i >= s; i--) {
      votes[i] |= votes[i-s];
    }
  }
  return votes[n] > 0;
}

int main() {
  vector<int> states { 5, 6, 4, 5 }; 
  cout << is_feasible(states) << " should be true." << endl;

  vector<int> states2 { 5, 6, 4, 9 }; 
  cout << is_feasible(states2) << " should be false." << endl;
  return 0;
}


