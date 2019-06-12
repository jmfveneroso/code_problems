// =====================================================
// Book: Elements of programming interviews
// Problem 8.5: Tower of Hanoi
// =====================================================

#include <iostream>

using namespace std;

void tower_of_hanoi(int n, int from, int to, int aux) {
  if (n == 1) {
    cout << "Move disk 1 from " << from << " to " << to << endl;
    return;
  }

  tower_of_hanoi(n-1, from, aux, to);
  cout << "Move disk " << n << " from "<< from << " to " << to << endl;
  tower_of_hanoi(n-1, aux, to, from);
}

int main () {
  tower_of_hanoi(4, 1, 2, 3);
  return 0;
}
