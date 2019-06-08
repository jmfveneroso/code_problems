// =====================================================
// Book: Elements of programming interviews
// Problem 18.8: Producer-consumer queue
// =====================================================

#include <iostream>
#include <queue>
#include <thread>
#include <mutex>
#include <sstream>

using namespace std;

class StringHolder {
  static mutex m;
  static queue<string> q;

 public:
  bool Write(string s) {
    lock_guard<mutex> lock(m);
    if (q.size() > 3) 
      return false;

    this_thread::sleep_for(chrono::milliseconds(100));
    q.push(s);
    return true;
  }

  bool Read(string& s) {
    lock_guard<mutex> lock(m);
    if (q.size() == 0) 
      return false;

    this_thread::sleep_for(chrono::milliseconds(10));
    s = q.front();
    q.pop();
    return true;
  }
};

mutex StringHolder::m;
queue<string> StringHolder::q;

int main() {
  StringHolder sh;
  mutex m;

  thread reader([&] {
    string s = "                          ";
    for (int i = 0; i < 10; i++) {
      while (!sh.Read(s)) {
        this_thread::sleep_for(chrono::milliseconds(100));
        cout << s << endl;
      }
    }
  });

  thread writer([&] {
    for (int i = 0; i < 10; i++) {
      stringstream ss;
      ss << "String number " << i << '\0';
      while (!sh.Write(ss.str())) {
        this_thread::sleep_for(chrono::milliseconds(100));
      }
    }
  });

  writer.join();
  reader.join();
  return 0;
}
