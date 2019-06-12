// Overflow test.
// Article about overflow http://www.cplusplus.com/articles/DE18T05o/.

#include <limits>
#include <iostream>

using namespace std;

int main () {
  unsigned char x = numeric_limits<unsigned char>::max();
  cout << (int) x << endl;

  x += 200;
  cout << "Addition overflow 255 + 200: " << (int) x << " should be 455." << endl;
  cout << "We can predict the overflow with the modulo operator." << endl;
  cout << "The erroneous number is 455 % 256: " << (int) 455 % 256 << "." << endl << endl;

  cout << "No overflow is possible on divisions or subtractions." << endl << endl;

  x = 100;
  x *= 3; 
  cout << "Multiplication overflow: " << (int) x << " should be 300." << endl;
 
  if (x/3 != 100) 
    cout << "Overflow has occurred." << endl;

  return 0;
}
