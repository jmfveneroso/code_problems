// =====================================================
// Book: Elements of programming interviews
// Problem 15.11: Levenshtein distance
// =====================================================

#include <iostream>
#include <algorithm>

using namespace std;

int levenshtein_distance(const string& a, const string& b) {
  int **matrix = new int*[a.size()+1];
  for (size_t i = 0; i < a.size()+1; i++)
    matrix[i] = new int[b.size()+1];

  for (size_t i = 0; i < a.size()+1; i++)
    matrix[i][0] = i;

  for (size_t j = 0; j < b.size()+1; j++)
    matrix[0][j] = j;
  
  for (size_t i = 0; i < a.size(); i++) {
    for (size_t j = 0; j < b.size(); j++) {
      int cost = (a[i] == b[j]) ? 0 : 1;

      int x = matrix[i][j] + cost;
      int y = matrix[i][j+1] + 1;
      int z = matrix[i+1][j] + 1;
 
      int min = (x < y) ? x : y;
      min = (min < z) ? min : z;
      matrix[i+1][j+1] = min;
    }
  } 

  int value = matrix[a.size()][b.size()];
  for (size_t i = 0; i < a.size()+1; i++)
    delete[] matrix[i];
  delete[] matrix;
  return value;
}

int main() {
  cout << levenshtein_distance("kitten", "sitting") << " should be 3." << endl;
  cout << levenshtein_distance("saturday", "sunday") << " should be 3." << endl;;
  cout << levenshtein_distance("cat", "bat") << " should be 1." << endl;;
  return 0;
}
