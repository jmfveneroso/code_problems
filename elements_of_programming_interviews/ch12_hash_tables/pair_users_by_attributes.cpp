// =====================================================
// Book: Elements of programming interviews
// Problem 12.5: Pair users by attributes
// =====================================================

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

void pair_users(
  unordered_map<string, vector<int> >& user_map, 
  int user_id, 
  vector<string> attributes
) {
  string hash;
  for (auto& s : attributes) hash.append(s);

  if (user_map.find(hash) == user_map.end())
    user_map[hash] = vector<int>();
  user_map[hash].push_back(user_id);
}

int main() {
  unordered_map<string, vector<int> > user_map;

  pair_users(user_map, 0, { "white", "tall", "32" });
  pair_users(user_map, 1, { "black", "short", "12" });
  pair_users(user_map, 2, { "white", "tall", "32" });
  pair_users(user_map, 4, { "black", "tall", "5" });
  pair_users(user_map, 5, { "black", "short", "21" });

  int counter = 1;
  for (auto& key : user_map) {
    cout << "Set: " << counter++ << endl;
    for (auto& id : key.second) cout << id << endl; 
  }
  cout << "0 and 2 should be paired." << endl;
  return 0;
}
