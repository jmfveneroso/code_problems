// =====================================================
// Book: Elements of programming interviews
// Problem 5.12: Rectangle Intersect
// =====================================================

#include <iostream>
#include <vector>

using namespace std;

std::vector<int> rect_intersect(std::vector<int> r, std::vector<int> s) {
  int r_rgt = r[0] + r[2];
  int s_rgt = s[0] + s[2];
  int r_top = r[1] + r[3];
  int s_top = s[1] + s[3];

  if (r_rgt < s[0] || s_rgt < r[0] || r_top < s[1] || s_top < r[1])
    return {0, 0, 0, 0};

  int x = (r[0] > s[0]) ? r[0] : s[0];
  int y = (r[1] > s[1]) ? r[1] : s[1];
  int rgt = (r_rgt < s_rgt) ? r_rgt : s_rgt;
  int top = (r_top < s_top) ? r_top : s_top;
  return {x, y, rgt - x, top - y};
}

int main() {
  std::vector<int> r { 1, 1, 10, 5 };
  std::vector<int> s { 3, 3, 8, 4 };
  std::vector<int> res = rect_intersect(r, s);
  
  cout << "Result is: " << res[0] << ", " << res[1] << ", " << res[2] << ", " << res[3] << endl;
  cout << "Should be: 3, 3, 8, 3" << endl;
  return 0;
}
