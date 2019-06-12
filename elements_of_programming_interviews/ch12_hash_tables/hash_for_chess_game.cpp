// =====================================================
// Book: Elements of programming interviews
// Problem 12.2: Hash code for a chess game
// =====================================================

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

const int MULTIPLIER = 997;
const int MOD_INVERSE = 333;
const int HASH_TABLE_SIZE = 1000;

enum Piece {
  BLANK, W_PAWN, W_HORSE, W_BISHOP, W_TOWER, W_QUEEN, W_KING,
  B_PAWN, B_HORSE, B_BISHOP, B_TOWER, B_QUEEN, B_KING
};

int hash_fn(const vector<Piece>& s) {
  int res = 0;
  for (auto& i : s) res = (res * MULTIPLIER + i) % HASH_TABLE_SIZE;
  return res;
}

int move_piece(int hash, Piece p, int from, int to) {
  int c = 1;
  for (int i = 0; i < from; i++) c *= MULTIPLIER;
  
  hash = (hash - c * p) % HASH_TABLE_SIZE;
  hash = (hash + c * BLANK) % HASH_TABLE_SIZE;

  c = 1;
  for (int i = 0; i < to; i++) c *= MULTIPLIER;

  hash = (hash - c * BLANK) % HASH_TABLE_SIZE;
  hash = (hash + c * p) % HASH_TABLE_SIZE;
  return (HASH_TABLE_SIZE + hash) % HASH_TABLE_SIZE;
}

int main() {
  vector<Piece> chessboard(64, BLANK);
  vector<Piece> first_row(8, W_PAWN);
  vector<Piece> last_row(8, B_PAWN);

  copy(first_row.begin(), first_row.end(), chessboard.begin());
  copy(last_row.begin(), last_row.end(), chessboard.end() - 8);

  int hash = hash_fn(chessboard);
  cout << "Starting board hash: " << hash << endl;

  hash = move_piece(hash, W_PAWN, 2, 10);
  cout << "Move third white pawn down: " << hash << endl;

  hash = move_piece(hash, W_PAWN, 10, 2);
  cout << "Move third white pawn up: " << hash << endl;

  hash = move_piece(hash, B_PAWN, 78, 70);
  cout << "Move third black pawn up: " << hash << endl;

  hash = move_piece(hash, B_PAWN, 70, 78);
  cout << "Move third black pawn down: " << hash << endl;
  return 0;
}
