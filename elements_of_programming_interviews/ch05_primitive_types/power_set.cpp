// =====================================================
// Book: Elements of programming interviews
// Problem 5.5: Power Set
// =====================================================

#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

// Stores 2^n intermediary results and prints all sets with
// an additional number each time. O(2^n) time and space.
void power_set1(std::vector<int>& x) {
  vector<string> power_sets;
  cout << "EMPTY" << endl;

  for (int i = 0; i < x.size(); i++) {
    vector<string> new_sets;

    stringstream ss;
    int n = power_sets.size();
    for (int j = 0; j < n; j++) {
      ss.str("");
      ss << power_sets[j] << ", " << x[i];
      cout << ss.str() << endl;
      power_sets.push_back(ss.str());
    } 

    ss.str("");
    ss << x[i];
    cout << ss.str() << endl;
    power_sets.push_back(ss.str());
    
    power_sets.insert(power_sets.end(), new_sets.begin(), new_sets.end());
  }
}

// There are 2^n power sets. Uses binary encoding to omit
// elements in zero positions and print elements in one positions.
// Ex: the 101 encoded power set of (A, B, C) is (A, C). O(2^n) time, O(1) space.
void power_set2(std::vector<int>& x) {
  int num_sets = 1 << x.size();
  for (int i = 1; i <= num_sets; i++) {
    bool first = true;
    for (int j = 0; j < x.size(); j++) {
      if ((i >> j) & 1) {
        if (!first) cout << ", ";
        cout << x[j];
        first = false;
      }
    }
    if (first) cout << "EMPTY";
    cout << endl;
  }
}

int main() {
  vector<int> numbers { 1, 2, 3, 4 };
  power_set1(numbers);
  cout << "=============" << endl;
  power_set2(numbers);
  return 0;
}
