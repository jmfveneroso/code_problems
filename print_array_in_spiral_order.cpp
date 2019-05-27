// =====================================================
// Book: Elements of programming interviews
// Problem 6.15: Print array in spiral order.
// =====================================================

#include <iostream>

using namespace std;

// Prints matrix in spiral order. Time complexity O(n).
void print_spiral(int matrix[][4], int size) {
  bool toprgt = true;
  int x = -1; int y = 0;
  for (int step = size; step > 0; step--) {
    if (toprgt) {
      for (int i = 0; i < step; i++) {
        x++;
        cout << matrix[y][x] << endl;
      }
      for (int i = 1; i < step; i++) {
        y++;
        cout << matrix[y][x] << endl;
      }
    } else {
      for (int i = 0; i < step; i++) {
        x--;
        cout << matrix[y][x] << endl;
      }
      for (int i = 1; i < step; i++) {
        y--;
        cout << matrix[y][x] << endl;
      }
    }
    toprgt = !toprgt;
  }
}

int main() {
  int mat[4][4] = {
    { 1 , 2 , 3 , 4 },
    { 12, 13, 14, 5 },
    { 11, 16, 15, 6 },
    { 10, 9 , 8 , 7 }
  };
 
  print_spiral(mat, 4);
  return 0;
}
