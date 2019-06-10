// =====================================================
// Book: Elements of programming interviews
// Problem 19.7: UNIX tail command
// =====================================================
 
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <algorithm>

using namespace std;

void tail(string filename, int num_lines) {
  fstream file;
  file.open(filename);

  file.seekg(0, ios::end);
  int file_size = file.tellg();

  string result;
  int num_chars = 0;
  int line_count = 0;

  char c;
  while (line_count <= num_lines && num_chars < file_size) {
    file.seekg(file_size-1-num_chars++, ios::beg);
    file.get(c);
    result.push_back(c);
    if (c == '\n') line_count++;
  }
  file.close();

  reverse(result.begin(), result.end());
  cout << result << endl;
}

int main() {
  tail("unix_tail_file.txt", 5);
  return 0;
}
