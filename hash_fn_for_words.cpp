// =====================================================
// Book: Elements of programming interviews
// Problem 12.1: Hash function for words
// =====================================================

#include <iostream>
#include <string>
#include <cmath>

using namespace std;

const int MULTIPLIER = 997;
const int HASH_TABLE_SIZE = 100;
const int MOD_INVERSE = 333;

int hash_fn(const string& s) {
  int res = 0;
  for (auto& c : s) res = (res * MULTIPLIER + c) % HASH_TABLE_SIZE;
  return res;
}

// A modular multiplicative inverse of an integer a is an integer x 
// such that the product ax is congruent to 1 with respect to the 
// modulus m. We can multiply the hash by this number to obtain a
// value congruent with the hash divided by the multiplier.
int replace_first_char(int& hash, string s, char c) {
  int pow = 1;
  for (size_t i = 0; i < s.size() - 1; i++) pow = (pow * MULTIPLIER) % HASH_TABLE_SIZE;
  hash = (hash - (pow * s[0])) % HASH_TABLE_SIZE;
  hash = (hash + (pow * c)) % HASH_TABLE_SIZE;
  return (HASH_TABLE_SIZE + hash) % HASH_TABLE_SIZE;
}

int add_last_char(int& hash, char c) {
  return (hash * MULTIPLIER + c) % HASH_TABLE_SIZE;
}

int delete_first_char(int hash, string s) {
  int pow = 1;
  for (size_t i = 0; i < s.size() - 1; i++) pow = (pow * MULTIPLIER) % HASH_TABLE_SIZE;

  hash = (hash - (pow * s[0])) % HASH_TABLE_SIZE;
  return (HASH_TABLE_SIZE + hash) % HASH_TABLE_SIZE;
}

int delete_last_char(int hash, string s) {
  hash = ((hash - s[s.size() - 1]) * MOD_INVERSE) % HASH_TABLE_SIZE;
  return (HASH_TABLE_SIZE + hash) % HASH_TABLE_SIZE;
}

int main() {
  int ca_hash = hash_fn("ca");
  int cat_hash = hash_fn("cat");
  int at_hash = hash_fn("at");
  int bat_hash = hash_fn("bat");
  int yielding_hash = hash_fn("yielding");
  int ielding_hash = hash_fn("ielding");
  int fielding_hash = hash_fn("fielding");

  cout << "cat yields " << cat_hash << endl;
  cout << "cat yields " << add_last_char(ca_hash, 't') << endl;
  cout << "ca yields " << ca_hash << endl;
  cout << "ca yields " << delete_last_char(cat_hash, "cat") << endl;
  cout << "at yields " << at_hash << endl;
  cout << "at yields " << delete_first_char(cat_hash, "cat") << endl;
  cout << "bat yields " << bat_hash << endl;
  cout << "bat yields " << replace_first_char(cat_hash, "cat", 'b') << endl;
  cout << "ielding yields " << ielding_hash << endl;
  cout << "ielding yields " << delete_first_char(yielding_hash, "yielding") << endl;
  cout << "fielding yields " << fielding_hash << endl;
  cout << "fielding yields " << replace_first_char(yielding_hash, "yielding", 'f') << endl;
  return 0;
}
