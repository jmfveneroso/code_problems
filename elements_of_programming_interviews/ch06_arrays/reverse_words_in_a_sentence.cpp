// =====================================================
// Book: Elements of programming interviews
// Problem 6.19: Reverse words in a sentence.
// =====================================================

#include <iostream>
#include <string>

using namespace std;

void reverse_words(string& s) {
  // Reverse words.
  int first_char = 0;
  for (unsigned int i = 0; i < s.size(); i++) {
    if (s[i] == ' ') {
      int word_len = i - first_char;
      for (int j = first_char, k = i-1; j < first_char + word_len/2; j++, k--)
        s[j] ^= s[k] ^= s[j] ^= s[k];
      first_char = i + 1;
    }
  }

  int word_len = s.size() - first_char;
  for (int j = first_char, k = s.size()-1; j < first_char + word_len/2; j++, k--)
    s[j] ^= s[k] ^= s[j] ^= s[k];

  // Reverse characters.
  for (unsigned int i = 0, j = s.size()-1; i < s.size()/2; i++, j--)
    s[i] ^= s[j] ^= s[i] ^= s[j];
}

int main() {
  string s = "Bob likes Alice";
  reverse_words(s);
  cout << s << " should be \"Alice likes Bob\"" << endl;
  return 0;
}
