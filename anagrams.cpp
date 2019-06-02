// =====================================================
// Book: Elements of programming interviews
// Problem 12.7: Anagrams
// =====================================================

#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

const int MULTIPLIER = 997;
const int HASH_TABLE_SIZE = 1000;

int hash_fn(const string& s) {
  int res = 0;
  for (auto& c : s) res = (res + MULTIPLIER + c) % HASH_TABLE_SIZE;
  return res;
}

void compute_anagrams(vector<string> dictionary) {
  map<int, vector<int> > word_sets;

  for (size_t i = 0; i < dictionary.size(); i++) {
    int hash = hash_fn(dictionary[i]);
    if (word_sets.find(hash) == word_sets.end())
      word_sets[hash] = vector<int>();
    word_sets[hash].push_back(i);
  }

  int counter = 1;
  for (auto& set : word_sets) {
    cout << "Set (" << counter++ << "):" << endl;
    for (auto& w_id : set.second) {
      cout << dictionary[w_id] << endl;
    }
  }
}

void compute_anagrams2(vector<string> dictionary) {
  map<string, vector<int> > word_sets;

  for (size_t i = 0; i < dictionary.size(); i++) {
    // Use sorted word as a hash.
    string hash = string(dictionary[i]);
    sort(hash.begin(), hash.end());   

    if (word_sets.find(hash) == word_sets.end())
      word_sets[hash] = vector<int>();
    word_sets[hash].push_back(i);
  }

  int counter = 1;
  for (auto& set : word_sets) {
    cout << "Set (" << counter++ << "):" << endl;
    for (auto& w_id : set.second) {
      cout << dictionary[w_id] << endl;
    }
  }
}

int main() {
  vector<string> dictionary {
    "mace", "aligned", "acme", 
    "auctioned", "dealing", 
    "strait", "traits",
    "leading", "artist", 
    "education"
  };
  compute_anagrams(dictionary);
  cout << "=============" << endl;
  compute_anagrams2(dictionary);
  return 0;
}
