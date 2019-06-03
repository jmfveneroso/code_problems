// =====================================================
// Book: Elements of programming interviews
// Problem 13.7: Count characters in a sentence
// =====================================================

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

void count_chars(string& s) {
  sort(s.begin(), s.end(), less<char>());

  char last_char = '\0';
  int count = 0;
  for (auto& c : s) {
    if (last_char != '\0' && c != last_char) {
      cout << last_char << ": " << count << endl;
      count = 0;
    }
    last_char = c, count++;
  }
  cout << last_char << ": " << count << endl;
}

int main() {
  string s = "lorem ipsum dolor sit amet";
  count_chars(s);

  return 0;
}
