// =====================================================
// Book: Elements of programming interviews
// Problem 6.15: Print array in spiral order.
// =====================================================

#include <iostream>

using namespace std;

// Prints matrix in spiral order. Time complexity O(n).
void print_spiral(int matrix[][4]) {
  bool toprgt = true;
  int x = -1; int y = 0;
  for (int step = 4; step > 0; step--) {
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

// Just another way to think. Same complexity.
void print_spiral2(int matrix[][4]) {
  int x1 = 0;
  int y1 = 0;
  int x2 = 3;
  int y2 = 3;
  
  while (x1 < x2 && y1 < y2) {
    for (int i = x1; i <= x2; i++)
      cout << matrix[y1][i] << endl;
    y1++;
  
    if (x1 == x2) break;
  
    for (int j = y1; j <= y2; j++)
      cout << matrix[j][x2] << endl;
    x2--;

    for (int i = x2; i >= x1; i--)
      cout << matrix[y2][i] << endl;
    y2--;

    for (int j = y2; j >= y1; j--)
      cout << matrix[j][x1] << endl;
    x1++;
  }
}

int main() {
  int mat[4][4] = {
    { 1 , 2 , 3 , 4 },
    { 12, 13, 14, 5 },
    { 11, 16, 15, 6 },
    { 10, 9 , 8 , 7 }
  };
 
  print_spiral(mat);
  print_spiral2(mat);
  return 0;
}
