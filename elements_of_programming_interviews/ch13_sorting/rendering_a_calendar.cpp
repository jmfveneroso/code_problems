// =====================================================
// Book: Elements of programming interviews
// Problem 13.10: Rendering a calendar
// =====================================================

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool compare_times(const pair<bool, int>& lhs, const pair<bool, int>& rhs) {
  return (lhs.second != rhs.second) ? lhs.second < rhs.second : (lhs.first && !rhs.first);
}

int rendering_calendar(vector< pair<int, int> >& time_pairs) {
  vector< pair<bool, int> > times;
  for (auto& p : time_pairs) {
    times.push_back({ 1, p.first });
    times.push_back({ 0, p.second });
  } 

  sort(times.begin(), times.end(), compare_times);

  int max_concurrent = 0;
  int count = 0;
  for (auto& t : times) {
    if (t.first)
      max_concurrent = max(++count, max_concurrent);
    else
      --count;
  }
  return max_concurrent;
}

int main() {
  vector< pair<int, int> > pairs {
    { 1, 5   }, { 2, 7   }, { 4, 5   },
    { 6, 10  }, { 8, 9   }, { 9, 17  },
    { 11, 13 }, { 12, 15 }, { 14, 15 }
  };

  cout << rendering_calendar(pairs) << " should be 3.";
  return 0;
}
