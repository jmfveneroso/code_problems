// =====================================================
// book: Elements of Programming Interviews
// problem 8.6: Views of the sunset
// =====================================================

#include <iostream>
#include <cstring>
#include <stack>

using namespace std;

void views_of_the_sunset(stack<int>& s_i, stack<int>& s_h, int index, int height) {
  while (!s_h.empty() && s_h.top() <= height) {
    s_i.pop();
    s_h.pop();
  }

  s_i.push(index);
  s_h.push(height);
}

int main() {
  stack<int> s_indices;
  stack<int> s_heights;

  /* 
                  =
          =       =
        = =   =   =
      = = = = =   =
      = = = = = = =

      The buildings that have views to the west are: 0, 1, 2, and 6.
  */

  views_of_the_sunset(s_indices, s_heights, 5, 5);
  views_of_the_sunset(s_indices, s_heights, 4, 3);
  views_of_the_sunset(s_indices, s_heights, 3, 2);
  views_of_the_sunset(s_indices, s_heights, 2, 4);
  views_of_the_sunset(s_indices, s_heights, 1, 3);
  views_of_the_sunset(s_indices, s_heights, 0, 2);

  while (!s_indices.empty()) {
    cout << "(" << s_indices.top() << ", " << s_heights.top() << ")";
    s_indices.pop();
    s_heights.pop();
    if (!s_indices.empty()) 
      cout << ", ";
  }

  cout << " should be (0, 2), (1, 3), (2, 4), (5, 5)." << endl;
  return 0;
}
