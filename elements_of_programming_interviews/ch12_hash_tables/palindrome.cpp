// =====================================================
// Book: Elements of programming interviews
// Problem 12.8: Palindrome
// =====================================================

#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

// O(n) time complexity and O(n) space complexity.
bool palindrome(string s) {
  unordered_map<char, size_t> char_counts;

  for (auto& c : s) {
    if (char_counts.find(c) == char_counts.end()) 
      char_counts[c] = 0;
    char_counts[c] += 1;
  }

  bool found_odd = false;
  for (auto& key : char_counts) {
    if (key.second % 2 == 1) {
      if (found_odd) return false;
      found_odd = true;
    }
  }

  return true;
}

// O(n log(n)) time complexity and O(1) space complexity.
bool palindrome2(string s) {
  sort(s.begin(), s.end());

  bool found_odd = false;
  char cur = '\0';
  int count = 0;
  for (auto& c : s) {
    if (c != cur) {
      if (count % 2 == 1) {
        if (found_odd) return false;
        found_odd = true;
      }
      cur = c;
      count = 0;
    }
    count++;
    cur = c;
  }
  if (count % 2 == 1 && found_odd) return false;
  return true;
}

int main() {
  cout << palindrome("edified") << " should be true." << endl;
  cout << palindrome("dog") << " should be false." << endl;
  cout << palindrome("rraaa") << " should be true." << endl;
  cout << palindrome("chernobyl") << " should be false." << endl;
  cout << palindrome2("edified") << " should be true." << endl;
  cout << palindrome2("dog") << " should be false." << endl;
  cout << palindrome2("rraaa") << " should be true." << endl;
  cout << palindrome2("chernobyl") << " should be false." << endl;
  return 0;
}
