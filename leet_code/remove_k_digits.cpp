// https://leetcode.com/problems/remove-k-digits/submissions/

#include <iostream>
#include <string>

using namespace std;

string remove_k_digits(string num, int k) {
  int i = 0;
  while (k > 0 && i < num.size() - 1) {
    if (num[i] > num[i+1]) {
      num = num.substr(0, i) + num.substr(i+1);
      if (i > 0) i--;
      k--;
    } else {
      i++;
    }
  }
  num = num.substr(0, num.size() - k);
  for (i = 0; num[i] == '0'; i++);
  return (i == num.size()) ? "0" : num.substr(i);
}

// string remove_k_digits(string num, int k) {
//   string result;
//   int final_digits = num.size() - k;
//   result.reserve(final_digits);
// 
//   for (int i = 0; k > 0 && i < num.size() - 1; i++) {
//     char next = num[i+1];
//     if (num[i] > next) {
//       for (int j = i; j >= 0; j--) {
//         if (num[j] != 'x' && num[j] > next && k > 0) {
//           num[j] = 'x', k--;
//         } else {
//           break;
//         }
//       }
//     }
//   }
//  
//   for (int i = 0, j = 0; j < final_digits; i++) {
//     if (num[i] != 'x') {
//     if (num[i] != '0' || result.size() > 0)
//       result += num[i];
//     j++;
//     }
//   } 
//   return (result.size() == 0) ? "0" : result;
// }

int main() {
  cout << remove_k_digits("1234567890", 9) << " should be 0." << endl;
  cout << remove_k_digits("1432219", 3) << " should be 1219." << endl;
  cout << remove_k_digits("100432219", 3) << " should be 2219." << endl;
  return 0;
}
