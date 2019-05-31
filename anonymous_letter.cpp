// =====================================================
// Book: Elements of programming interviews
// Problem 12.9: Anonymous Letter
// =====================================================

#include <iostream>
#include <unordered_map>

using namespace std;

// Example function.
bool anonymous_letter(string& magazine, string& letter) {
  unordered_map<char, size_t> hash_map;

  for (char c : magazine) {
    if (hash_map.find(c) == hash_map.end())
      hash_map[c] = 0;
    hash_map[c]++;
  }  

  for (char c : letter) {
    if (hash_map.find(c) == hash_map.end()) return false;
    if (hash_map[c] == 0) return false;
    hash_map[c]--;
  }  

  return true;
}

int main() {
  string a = "pease porridge hot pease porridge cold";
  string b = "porridge hot pease cold";
  string c = "quick brown fox jumps over the lazy dog";

  cout << anonymous_letter(a, b) << " should be true." << endl;
  cout << anonymous_letter(a, c) << " should be false." << endl;
  cout << anonymous_letter(b, c) << " should be false." << endl;
  return 0;
}
