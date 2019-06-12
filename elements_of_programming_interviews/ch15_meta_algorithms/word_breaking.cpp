// =====================================================
// Book: Elements of programming interviews
// Problem 15.12: Word breaking
// =====================================================

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

ostream& operator<<(ostream& os, vector<string>& v) {
  for (auto& s : v) cout << s << endl;
  return os;
}

// Breaks a sentence into words according to a dictionary. This
// is the recursive naive approach. Time complexity: O(n^2).
vector<string> recursive_word_breaking(string& s, unordered_set<string>& dictionary, int i) {
  vector<string> words;
  for (size_t j = i+1; j <= s.size(); j++) {
    string word = s.substr(i, j-i);
    if (dictionary.find(word) == dictionary.end()) continue;
    if (j == s.size())
      words.push_back(word);
    else {
      vector<string> rgt_words = recursive_word_breaking(s, dictionary, j);
      for (auto& r_word : rgt_words) 
        words.push_back(word + string(" ") + r_word);
    }
  }
  return words;
}

void print_bottom_up_results(
  string& s, vector< vector<int> >& prev_words, int i, string suffix
) {
  for (size_t j = 0; j < prev_words[i].size(); j++) {
    int prev_index = prev_words[i][j];
    string word = s.substr(prev_index, (i-prev_index)+1);
    if (prev_index == 0)
      cout << word << " " << suffix << endl;
    else
      print_bottom_up_results(s, prev_words, prev_index-1, word + " " + suffix);
  }
}

// Bottom up dynamic programming approach. Also O(n^2) complexity but avoids 
// more calculations.
void bottom_up_word_breaking(string& s, unordered_set<string>& dictionary) {
  vector< vector<int> > prev_words(s.size(), vector<int>());

  for (size_t i = 1; i <= s.size(); i++) {
    for (int j = i-1; j > 0; j--) {
      if (prev_words[j-1].size()) {
        string word = s.substr(j, i-j);
        if (dictionary.find(word) != dictionary.end()) {
          prev_words[i-1].push_back(j);
        }
      }
    }

    string word = s.substr(0, i);
    if (dictionary.find(word) != dictionary.end()) {
      prev_words[i-1].push_back(0);
    }
  } 

  print_bottom_up_results(s, prev_words, s.size()-1, "");
}

int main() {
  string s = "bedbathandbeyond";
  unordered_set<string> dictionary {
    "bed", "bat", "bath", "hand", "and", "beyond"
  };

  cout << "All of the methods below should output:" << endl;
  cout << "bed bat hand beyond" << endl;
  cout << "bed bath and beyond" << endl << endl;

  cout << "Recursive:" << endl;
  vector<string> words = recursive_word_breaking(s, dictionary, 0);
  cout << words << endl;

  cout << "Bottom up:" << endl;
  bottom_up_word_breaking(s, dictionary);
  return 0;
}
