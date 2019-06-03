// =====================================================
// Book: Elements of programming interviews
// Problem 13.2: Swap lines of a text
// =====================================================

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// Sorts line of a text by indirectly comparing strings with 
// pointers. O(n log (n) ) time complexity.
vector<string> sort_lines(vector<string>& x) {
  vector<string*> x_;
  for (auto& s : x) x_.push_back(&s);

  sort(x_.begin(), x_.end(), [] (const string* a, const string* b) -> bool {
    size_t i = 0, j = 0;
    while (i < a->size() && j < b->size()) {
      if ((*a)[0] == (*b)[0]) i++, j++;
      else return (*a)[0] < (*b)[0];
    }
    return a->size() < b->size();
  });

  vector<string> result;
  for (auto& s : x_) {
    result.push_back(*s);
  }
  return result;
}

int main() {
  vector<string> x {
    "lorem ipsum dolor sit amet, consectetur adipiscing elit",
    "nullam pretium, lectus iaculis blandit tristique, ante enim porta eros",
    "non dapibus mauris mi sit amet neque",
    "morbi turpis augue",
    "luctus ornare cursus ut, dapibus ac sem. Etiam viverra, ante",
    "ut cursus porttitor, justo est luctus magna, quis",
    "dapibus tellus orci in ante. Ut",
    "morbi turpis"
  };

  x = sort_lines(x);
  for (auto& s : x) cout << s << endl;

  return 0;
}
