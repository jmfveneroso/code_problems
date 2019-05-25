#include <iostream>
#include <unordered_map>
#include <vector>

// https://leetcode.com/problems/two-sum/

using namespace std;

vector<int> two_sum(vector<int>& arr, int number) {
  unordered_map<int, int> map;

  for (int i = 0; i < arr.size(); i++) {
    int complement = number - arr[i];
    if (map.find(complement) != map.end()) {
      return {map[complement], i};
    } else {
      map[arr[i]] = i;
    }
  }

  return vector<int>({-1, -1});
}

int main() {
  vector<int> numbers {2, 7, 11, 15};
  vector<int> pair = two_sum(numbers, 9);
  cout << pair[0] << ", " << pair[1] << endl;
  return 0;
}
