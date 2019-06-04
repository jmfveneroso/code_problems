// =====================================================
// Book: Elements of programming interviews
// Problem 12.13: Plagiarism detector
// =====================================================

#include <iostream>
#include <string>
#include <cmath>
#include <unordered_set>
#include <vector>

using namespace std;

const int MULTIPLIER = 997;
const int MOD_INVERSE = 333;
const int HASH_TABLE_SIZE = 1000;

int hash_fn(const string& s) {
  int res = 0;
  for (auto& c : s) res = (res * MULTIPLIER + c) % HASH_TABLE_SIZE;
  return res;
}

int delete_first_char(int hash, string s, size_t i, size_t k) {
  int pow = 1;
  for (size_t i = 0; i < k - 1; i++) 
    pow = (pow * MULTIPLIER) % HASH_TABLE_SIZE;
  hash = (hash - (pow * s[i])) % HASH_TABLE_SIZE;
  return (HASH_TABLE_SIZE + hash) % HASH_TABLE_SIZE;
}

int add_char(int& hash, string s, int i) {
  hash = (hash * MULTIPLIER + s[i]) % HASH_TABLE_SIZE;
  return (HASH_TABLE_SIZE + hash) % HASH_TABLE_SIZE;
}

// This function is not very efficient. An actual hash table 
// implementation should not use a vector on each key. We could
// store keys in the next empty slot, and store only the index
// in the first string instead of the actual key. But this shows
// how an efficient plagiarism detection method could be 
// implemented. The time complexity is O(m log(m) + n) where m
// is the size of the first string and n is the size of the second
// string.
bool compare_strings(string line1, string line2, int k) {
  vector<string> hash_table[1000];

  int hash = hash_fn(line1.substr(0, k));
  for (size_t i = 0; i < line1.size() - k + 1; i++) {
    if (i > 0) {
      hash = delete_first_char(hash, line1, i-1, k);
      hash = add_char(hash, line1, i+k-1);
    }

    string s = line1.substr(i, k);
    if (!hash_table[hash].size()) {
      hash_table[hash].push_back(s);
    } else {
      bool found = false;
      for (size_t j = 0; j < hash_table[hash].size(); j++) {
        if (hash_table[hash][j] == s) { found = true; break; }
      }
      if (!found) hash_table[hash].push_back(s);
    }
  }

  hash = hash_fn(line2.substr(0, k));
  for (size_t i = 0; i < line2.size() - k + 1; i++) {
    if (i > 0) {
      hash = delete_first_char(hash, line2, i-1, k);
      hash = add_char(hash, line2, i+k-1);
    }

    if (hash_table[hash].size() > 0) {
      string s = line2.substr(i, k);
      for (size_t j = 0; j < hash_table[hash].size(); j++)
        if (hash_table[hash][j] == s) 
          return true;
    }
  }
  return false;
}

int main() {
  string s1 = "pease porridge hot";
  string s2 = "pease porridge cold";
  string s3 = "some like it hot";
  string s4 = "some like it cold";

  cout << compare_strings(s1, s2, 5) << " should be true." << endl;
  cout << compare_strings(s1, s2, 14) << " should be true." << endl;
  cout << compare_strings(s1, s2, 16) << " should be false." << endl;
  cout << compare_strings(s1, s3, 3) << " should be true." << endl;
  cout << compare_strings(s1, s3, 5) << " should be false." << endl;
  cout << compare_strings(s3, s4, 13) << " should be true." << endl;
  cout << compare_strings(s3, s4, 14) << " should be false." << endl;
  return 0;
}
