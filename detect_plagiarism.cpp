// =====================================================
// Book: Elements of programming interviews
// Problem 12.13: Plagiarism detector
// =====================================================

#include <iostream>
#include <string>
#include <cmath>
#include <unordered_set>

using namespace std;

const int MULTIPLIER = 997;
const int MOD_INVERSE = 333;
const int HASH_TABLE_SIZE = 1000;

int hash_fn(const string& s) {
  int res = 0;
  for (auto& c : s) res = (res * MULTIPLIER + c) % HASH_TABLE_SIZE;
  return res;
}

int delete_first_char(int hash, string s) {
  int pow = 1;
  for (size_t i = 0; i < s.size() - 1; i++) pow *= MULTIPLIER;
  hash = (hash - (pow * s[0])) % HASH_TABLE_SIZE;
  return (HASH_TABLE_SIZE + hash) % HASH_TABLE_SIZE;
}

int add_char(int& hash, string s, int i) {
  hash = (hash * MULTIPLIER + s[i]) % HASH_TABLE_SIZE;
  return (HASH_TABLE_SIZE + hash) % HASH_TABLE_SIZE;
}

// bool compare_strings(string line1, string line2, int k) {
//   unordered_set<int> substrings;
// 
//   int hash = hash_fn(line1.substr(0, k));
//   for (size_t i = 0; i < line1.size() - k + 1; i++) {
//     cout << line1.substr(i, k) << endl;
// 
//     if (i > 0) {
//       hash = add_char(hash, line1, i+k);
//     }
// 
//     cout << hash << endl;
//     if (substrings.find(hash) == substrings.end())
//       substrings.insert(hash);
//     hash = delete_first_char(hash, line1, i, k);
//   }
// 
//   cout << "============" << endl;
//   hash = hash_fn(line2.substr(0, k));
//   for (size_t i = 0; i < line2.size() - k + 1; i++) {
//     cout << line2.substr(i, k) << endl;
// 
//     if (i > 0) {
//       hash = add_char(hash, line2, i+k);
//     }
// 
//     cout << hash << endl;
//     if (substrings.find(hash) != substrings.end()) return true;
//     hash = delete_first_char(hash, line2, i, k);
//   }
//   return false;
// }

int main() {
  string s1 = "pease porridge hot";
  string s2 = "pease porridge cold";
  string s3 = "some like it hot";
  string s4 = "some like it cold";

  int h = hash_fn("bato");
  cout << h << " pease." << endl;
  int h2 = hash_fn("ato");
  cout << h2 << " ato" << endl;
  h = delete_first_char(h, "bato");
  cout << h << " at" << endl;

  // cout << compare_strings(s1, s2, 5) << " should be true." << endl;
  // cout << compare_strings(s1, s2, 14) << " should be true." << endl;
  // cout << compare_strings(s1, s2, 16) << " should be false." << endl;
  // cout << compare_strings(s1, s3, 3) << " should be true." << endl;
  // cout << compare_strings(s1, s3, 5) << " should be false." << endl;
  // cout << compare_strings(s3, s4, 13) << " should be true." << endl;
  // cout << compare_strings(s3, s4, 14) << " should be false." << endl;
  return 0;
}
