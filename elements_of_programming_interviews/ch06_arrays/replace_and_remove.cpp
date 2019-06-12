// =====================================================
// Book: Elements of programming interviews
// Problem 6.21: Replace and remove.
// =====================================================

#include <iostream>
#include <string>

using namespace std;

void replace_and_remove(string& s) {
  for (unsigned int i = 0; i < s.size(); i++) {
    if (s[i] == 's') {
      bool found_a = false;
      unsigned int j = i + 1;
      for (; j < s.size(); j++) {
        if (s[j] == 'a') {
          found_a = true;
          break;
        }
      }
     
      // Shift left.
      for (unsigned int k = i+1; k <= j; k++) s[k-1] = s[k];
      if (found_a) {
        s[j-1] = 'd';
        s[j] = 'd';
      }
    } else if (s[i] == 'a') {
      unsigned int j = i+1;
      for (; j < s.size(); j++) {
        if (s[j] == 's') break;
      }

      // Shift right.
      for (unsigned int k = j; k > i+1; k--) s[k] = s[k-1];
      s[i] = 'd';
      s[i+1] = 'd';
    }
  }
}

void replace_and_remove2(string& s) {
  unsigned int a_count = 0; 
  unsigned int write_index = 0; 

  for (unsigned int i = 0; i < s.size(); i++) {
    if (s[i] != 's')
      s[write_index++] = s[i];

    if (s[i] == 'a')
      a_count++;
  }

  unsigned int write_size = write_index + a_count;
  s[write_size] = '\0'; 

  for (
    int i = write_index - 1, j = write_size - 1; 
    j >= 0; 
    i--, j--
  ) {
    if (s[i] == 'a') {
      s[j--] = 'd';
      s[j] = 'd';
    } else {
      s[j] = s[i];
    }
  }
}

int main() {
  string s = "axasssxas";
  replace_and_remove(s);
  cout << s << " should be ddxddxdd." << endl;
  s = "axasssxas";
  replace_and_remove2(s);
  cout << s << " should be ddxddxdd." << endl;
  return 0;
}
