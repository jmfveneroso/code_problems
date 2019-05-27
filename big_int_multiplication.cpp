// =====================================================
// Book: Elements of programming interviews
// Problem 6.9: Big Integer Multiplication
// =====================================================

#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

string sum(string x, string y) {
  unsigned int n = (x.size() > y.size()) ? x.size() : y.size();
  string result;
  result.resize(n+1);
  memset(&result[0], '0', n+1);

  int carry = 0;
  for (unsigned int i = 0; i < n; i++) {
    int a = (i < x.size()) ? (x[x.size()-1-i] - '0') : 0;
    int b = (i < y.size()) ? (y[y.size()-1-i] - '0') : 0;
    result[n-i] = '0' + ((a + b + carry) % 10);
    carry = (a + b + carry) / 10;
  }
  result[0] = carry + '0';
  return result;
}

string mult_unit(string x, int y) {
  string result;
  result.resize(x.size()+1);
  memset(&result[0], '0', x.size()+1);

  int carry = 0;
  for (unsigned int i = 0; i < x.size(); i++) {
    int a = (x[x.size()-1-i] - '0') * y;
    result[x.size()-i] = '0' + ((a + carry) % 10);
    carry = (a + carry) / 10;
  }
  result[0] = carry + '0';
  return result;
}

string mult(string x, string y) {
  string result = "0";

  for (unsigned int i = 0; i < y.size(); i++) {
    int a = (y[y.size()-1-i] - '0');
    string b = mult_unit(x, a);
    for (unsigned int j = i; j > 0; j--)
      b.append("0");

    result = sum(result, b);
  }
  return result;
}

ostream& operator<<(ostream& out, vector<int>& arr) {
  for(const auto& a: arr) cout << a;
  return out;
}

vector<int> mult_better(string x, string y) {
  vector<int> result(x.size() + y.size(), 0);
  for (int i = x.size()-1; i >= 0; i--) {
    for (int j = y.size()-1; j >= 0; j--) {
      int a = x[i] - '0';
      int b = y[j] - '0';

      result[i+j+1] += a * b;
      result[i+j  ] += result[i+j+1] / 10;
      result[i+j+1]  = result[i+j+1] % 10;
      cout << result << endl;
    }
  }
  return result;
}

int main() {
  string x = "123";
  string y = "459";
  string res = sum(x, y);
  string res2 = mult_unit(res, 9);
  string res3 = mult(res2, "452");
  vector<int> res4 = mult_better(res2, "452");

  cout << res << " should be 582." << endl;
  cout << res2 << " should be 5238." << endl;
  cout << res3 << " should be 2367576." << endl;
  cout << res4 << " should be 2367576." << endl;

  return 0;
}
