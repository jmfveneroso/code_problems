// =====================================================
// Book: Elements of programming interviews
// Problem 5.6: String to Int, Int to String
// =====================================================

#include <iostream>
#include <vector>
#include <string>

using namespace std;

// O(n) time complexity.
string int_to_str(int x) {
  if (x == 0) return "0";

  int decimal_places = 0;
  int aux = x;
  for (; aux > 0; aux /= 10) decimal_places++;

  char buffer[10];
  buffer[decimal_places] = '\0';
  for (int i = 0; i < decimal_places; i++) {
    buffer[decimal_places - i - 1] = '0' + (x % 10);
    x /= 10;
    if (x == 0) break;
  }
  return buffer;
}

// O(n) time complexity.
int str_to_int(string x) {
  int accumulator = 0;
  int multiplier = 1;
  for (int i = x.size() - 1; i >= 0; i--) {
    accumulator += multiplier * (x[i] - '0');
    multiplier *= 10; 
  }
  return accumulator;
}

int main() {
  vector<int> i_numbers { 5, 123, 4432, 2123, 54313 };
  vector<string> s_numbers { "5", "123", "4432", "2123", "54313" };

  for (int i = 0; i < i_numbers.size(); i++) {
    cout << int_to_str(i_numbers[i]) << " should be " << i_numbers[i] << endl;
    cout << str_to_int(s_numbers[i]) << " should be " << s_numbers[i] << endl;
  }
  return 0;
}
