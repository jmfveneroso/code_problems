#include <vector>
#include <iostream>

// https://leetcode.com/problems/best-time-to-buy-and-sell-stock/

using namespace std;

// Divide and conquer solution. Too complicated. O(n).
vector<int> aux(vector<int>& prices, int start, int end) {
  if (start == end)
    return { prices[start], prices[start], 0 };

  int mid = (start + end) / 2;
  vector<int> lft = aux(prices, start, mid);
  vector<int> rgt = aux(prices, mid+1, end);

  int min = (lft[0] < rgt[0]) ? lft[0] : rgt[0];
  int max = (lft[1] > rgt[1]) ? lft[1] : rgt[1];
  int max_profit = (lft[2] > rgt[2]) ? lft[2] : rgt[2];
  if (rgt[1] - lft[0] > max_profit)
      max_profit = rgt[1] - lft[0];

  return { min, max, max_profit };
}

int dq_max_profit(vector<int>& prices) {
  if (prices.size() <= 1) return 0;
  return aux(prices, 0, prices.size()-1)[2];
}

// Dynamic programming. Also too complicated. O(n).
int dp_max_profit(vector<int>& prices) {
  if (prices.size() <= 1) return 0;

  vector<int> min;
  min.reserve(prices.size());
  vector<int> max;
  max.reserve(prices.size());

  int c_min = 1215752191;
  for (int i = 0; i < prices.size(); i++) {
    c_min = (prices[i] < c_min) ? prices[i] : c_min;
    min[i] = c_min;
  }

  int c_max = 0;
  for (int i = prices.size() - 1; i >= 0; i--) {
    c_max = (prices[i] > c_max) ? prices[i] : c_max;
    max[i] = c_max;
  }

  int max_profit = 0;
  for (int i = 0; i < prices.size()-1; i++) {
    if (max[i+1] - min[i] > max_profit) max_profit = max[i+1] - min[i];
  }
  return max_profit;
}

// Actual solution. Only two variables needed.
int max_profit(vector<int>& prices) {
  int min = 1215752191;
  int max_profit = 0;
  for (int i = 0; i < prices.size(); i++) {
    min = (prices[i] < min) ? prices[i] : min;
    max_profit = (prices[i] - min > max_profit) ? prices[i] - min : max_profit;
  }
  return max_profit;
}

int main () {
  vector<int> x { 5,5,4,9,3,8,5,5,1,6,8,3,4 };
  cout << "Max profit for [5,5,4,9,3,8,5,5,1,6,8,3,4] should be 7." << endl;

  cout << "DQ: " << dq_max_profit(x) << endl;
  cout << "DP: " << dp_max_profit(x) << endl;
  cout << "Best: " << max_profit(x) << endl;
}
