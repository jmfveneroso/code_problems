#include <iostream>

int main() {
  int x = 12;
  int y = 0;

  std::cout << "Before swap - x: " << x << ", y: " << y << std::endl;

  x ^= y;
  y ^= x;
  x ^= y;

  std::cout << "After swap - x: " << x << ", y: " << y << std::endl;

  return 0;
}
