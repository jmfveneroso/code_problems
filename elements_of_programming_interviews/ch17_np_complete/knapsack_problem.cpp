// =====================================================
// Book: Elements of programming interviews
// Problem 17.2: Knapsack problem
// =====================================================

#include <iostream>
#include <vector>

using namespace std;

class Clock {
 public:
  int value;
  int weight;
};

int knapsack(vector<Clock>& clocks, const int& max_weight) {
  vector< vector<int > > cache(clocks.size());
  for (size_t i = 0; i < clocks.size(); i++)
    cache[i] = vector<int>(max_weight+1, 0);

  for (int j = 1; j <= max_weight; j++)
    cache[0][j] = (j >= clocks[0].weight) ? clocks[0].value : 0;

  for (size_t i = 1; i < clocks.size(); i++) {
    for (int j = 1; j <= max_weight; j++) {
      // Keep the same items.
      int max_profit = cache[i][j-1];

      // Forgo the current item.
      max_profit = max(max_profit, cache[i-1][j]);

      // Take the current item.
      int allowed_weight = j - clocks[i].weight;
      if (allowed_weight >= 0) {
        int value = cache[i-1][allowed_weight] + clocks[i].value;
        max_profit = max(max_profit, value);
      }
      cache[i][j] = max_profit;
    }
  }
  return cache[clocks.size()-1][max_weight];
}

int main() {
  vector<Clock> clocks {
    {65, 20}, {35, 8}, {245, 60}, {195, 55}, {65, 40},
    {150, 70}, {275, 85}, {155, 25}, {120, 30}, {320, 65},
    {75, 75}, {40, 10}, {200, 95}, {100, 50}, {220, 40},
    {90, 10}
  };

  cout << knapsack(clocks, 130) << " should be 695." << endl;
  return 0;
}
