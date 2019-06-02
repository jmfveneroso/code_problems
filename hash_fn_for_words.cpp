// =====================================================
// Book: Elements of programming interviews
// Problem 12.1: Hash function for words
// =====================================================

#include <iostream>
#include <string>
#include <cmath>

using namespace std;

const int MULTIPLIER = 997;
const int MOD_INVERSE = 3;

int get_mod_inverse(int a, int m) { 
  a = a % m; 
  for (int x = 1; x < m; x++) 
    if ((a * x) % m == 1) 
      return x; 
  return -1;
}

int hash_fn(const string& s, const int& hash_table_size) {
  int res = 0;
  for (auto& c : s) res = (res * MULTIPLIER + c) % hash_table_size;
  return res;
}

// A modular multiplicative inverse of an integer a is an integer x 
// such that the product ax is congruent to 1 with respect to the 
// modulus m. We can multiply the hash by this number to obtain a
// value congruent with the hash divided by the multiplier.
int replace_first_char(int& hash, string s, char c, const int& hash_table_size) {
  int pow = 1;
  for (size_t i = 0; i < s.size() - 1; i++) pow *= MULTIPLIER;
  hash = (hash - (pow * s[0])) % hash_table_size;
  hash = (hash + (pow * c)) % hash_table_size;
  return (hash_table_size + hash) % hash_table_size;
}

int add_last_char(int& hash, char c, const int& hash_table_size) {
  return (hash * MULTIPLIER + c) % hash_table_size;
}

int delete_first_char(int hash, string s, const int& hash_table_size) {
  int pow = 1;
  for (size_t i = 0; i < s.size() - 1; i++) pow *= MULTIPLIER;
  hash = (hash - (pow * s[0])) % hash_table_size;
  return (hash_table_size + hash) % hash_table_size;
}

int delete_last_char(int hash, string s, const int& hash_table_size) {
  hash = ((hash - s[s.size() - 1]) * MOD_INVERSE) % hash_table_size;
  return (hash_table_size + hash) % hash_table_size;
}

int main() {
  cout << "The mod inverse of " << MULTIPLIER << " % 10 is " << get_mod_inverse(MULTIPLIER, 10) << endl;

  int ca_hash = hash_fn("ca", 10);
  int cat_hash = hash_fn("cat", 10);
  int at_hash = hash_fn("at", 10);
  int bat_hash = hash_fn("bat", 10);

  cout << "cat yields " << cat_hash << endl;
  cout << "cat yields " << add_last_char(ca_hash, 't', 10) << endl;
  cout << "ca yields " << ca_hash << endl;
  cout << "ca yields " << delete_last_char(cat_hash, "cat", 10) << endl;
  cout << "at yields " << at_hash << endl;
  cout << "at yields " << delete_first_char(cat_hash, "cat", 10) << endl;
  cout << "bat yields " << bat_hash << endl;
  cout << "bat yields " << replace_first_char(cat_hash, "cat", 'b', 10) << endl;
  return 0;
}
