// =====================================================
// Book: Elements of programming interviews
// Problem 6.14: Sudoku Checker
// =====================================================

#include <iostream>

using namespace std;

// Checks if a sudoku solution is correct. O(n) with n
// being the size of the board.
bool sudoku_checker(int x[9][9]) {
  int correct = 1 ^ 2 ^ 3 ^ 4 ^ 5 ^ 6 ^ 7 ^ 8 ^ 9;

  for (int i = 0; i < 9; i++) {
    int row = 0;
    int col = 0;
    for (int j = 0; j < 9; j++) {
      row ^= x[i][j];
      col ^= x[j][i];
    }

    if (row != correct || col != correct)
      return false;
  }

  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      int square = 0;
      for (int m = 0; m < 3; m++) {
        for (int n = 0; n < 3; n++) {
          square ^= x[i*3 + m][j*3 + n];
        }
      }
      if (square != correct)
        return false;
    }
  }
  return true;
}

int main() {
  int correct[9][9] = {
    {5, 3, 4, 6, 7, 8, 9, 1, 2},
    {6, 7, 2, 1, 9, 5, 3, 4, 8},
    {1, 9, 8, 3, 4, 2, 5, 6, 7},
    {8, 5, 9, 7, 6, 1, 4, 2, 3},
    {4, 2, 6, 8, 5, 3, 7, 9, 1},
    {7, 1, 3, 9, 2, 4, 8, 5, 6},
    {9, 6, 1, 5, 3, 7, 2, 8, 4},
    {2, 8, 7, 4, 1, 9, 6, 3, 5},
    {3, 4, 5, 2, 8, 6, 1, 7, 9}
  };

  int incorrect[9][9] = {
    {5, 3, 4, 6, 7, 8, 9, 1, 2},
    {6, 7, 2, 9, 1, 5, 3, 4, 8},
    {1, 9, 8, 3, 4, 2, 5, 6, 7},
    {8, 5, 9, 7, 6, 1, 4, 2, 3},
    {4, 2, 6, 8, 5, 3, 7, 9, 1},
    {7, 1, 3, 9, 2, 4, 8, 5, 6},
    {9, 6, 1, 5, 3, 7, 2, 8, 4},
    {2, 8, 7, 4, 1, 9, 6, 3, 5},
    {3, 4, 5, 2, 8, 6, 1, 7, 9}
  };

  int incorrect2[9][9] = {
    {1, 2, 3, 4, 5, 6, 7, 8, 9},
    {2, 3, 4, 5, 6, 7, 8, 9, 1},
    {3, 4, 5, 6, 7, 8, 9, 1, 2},
    {4, 5, 6, 7, 8, 9, 1, 2, 3},
    {5, 6, 7, 8, 9, 1, 2, 3, 4},
    {6, 7, 8, 9, 1, 2, 3, 4, 5},
    {7, 8, 9, 1, 2, 3, 4, 5, 6},
    {8, 9, 1, 2, 3, 4, 5, 6, 7},
    {9, 1, 2, 3, 4, 5, 6, 7, 8}
  };

  cout << sudoku_checker(correct) << " should be true" << endl;
  cout << sudoku_checker(incorrect) << " should be false" << endl;
  cout << sudoku_checker(incorrect2) << " should be false" << endl;
  return 0;
}
