// =====================================================
// Book: Elements of programming interviews
// Problem 10.2: Sort K-increasing decreasing array
// =====================================================

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct CustomCompare {
  bool operator()(const pair<int, int>& a, const pair<int, int>& b) {
    return a.first > b.first;
  }
};

// Sorts a k increasing-decreasing array. First the algorithm finds 
// all spans of only increasing or decreasing elements. Then it 
// does a k-way sort of these spans. Decreasing spans are traversed 
// from right to left and increasing spans are traversed from left
// to right. The time complexity is O(log(n)) and the space complexity
// is O(k).
void sort_k_increasing_decreasing_array(vector<int> arr) {
  vector<int> start {0}, end, direction {1};

  int cur_dir = 1;
  for (size_t i = 1; i < arr.size(); i++) {
    if (cur_dir * arr[i] < cur_dir * arr[i-1]) {
      end.push_back(i-1);
      start.push_back(i); 
      cur_dir *= -1;
      direction.push_back(cur_dir);
    }
  }
  end.push_back(arr.size() - 1);

  priority_queue< pair<int, int>, vector< pair<int, int> >, CustomCompare > q;

  int k = start.size();
  for (int i = 0; i < k; i++) {
    if (direction[i] == 1) {
      q.push({ arr[start[i]], i });
      start[i]++;
    } else {
      q.push({ arr[end[i]], i });
      end[i]--;
    }
  }

  while (true) {
    bool exit = true;
    for (int i = 0; i < k; i++) 
      exit &= !(start[i] <= end[i]);
    if (exit) break;

    cout << q.top().first << " ";
    int i = q.top().second;
    q.pop();

    if (start[i] > end[i]) continue;
    if (direction[i] == 1) {
      q.push({ arr[start[i]], i });
      start[i]++;
    } else {
      q.push({ arr[end[i]], i });
      end[i]--;
    }
  }

  while (!q.empty()) {
    cout << q.top().first << " ";
    q.pop();
  }
}

ostream& operator<<(ostream& os, vector<int>& arr) {
  for (int i = 0; i < arr.size(); i++)
    cout << arr[i] << " ";
  return os;
}

int main () {
  vector<int> arr { 57, 131, 493, 294, 221, 339, 418, 452, 442, 190 };

  cout << arr << endl;
  sort_k_increasing_decreasing_array(arr);
  cout << endl;
  return 0;
}
