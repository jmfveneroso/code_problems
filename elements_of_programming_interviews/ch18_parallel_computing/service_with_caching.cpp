// =====================================================
// Book: Elements of programming interviews
// Problem 18.1: Service with Caching
// =====================================================

#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>
#include <string>
#include <vector>

using namespace std;

class SpellCheckService {
 public:
  static mutex m;
  static mutex m2;
  static string last_word;
  static vector<string> closest_words;

  vector<string> GetClosestWords(string w) {
    this_thread::sleep_for(chrono::milliseconds(100));
    if (w == "a")
      return { "ape", "ace", "axe" };
    return { "bag", "bog", "big" };
  }

  vector<string> ProcessRequest(string w) {
    {
      lock_guard<mutex> lock(m);
      if (w == last_word) {
        return closest_words; 
      }
    }

    vector<string> words = GetClosestWords(w);
 
    {
      lock_guard<mutex> lock(m);
      last_word = w;
      closest_words = words;
    }
    return words;
  }

  void operator()(string w) {
    lock_guard<mutex> lock(m2);
    vector<string> words = ProcessRequest(w);
    for (auto& word : words)
      cout << word << " ";
    cout << endl;
  }
};

mutex SpellCheckService::m;
mutex SpellCheckService::m2;
string SpellCheckService::last_word;
vector<string> SpellCheckService::closest_words;

int main() {
  thread t1(SpellCheckService(), "a");
  thread t2(SpellCheckService(), "a");
  thread t3(SpellCheckService(), "a");
  thread t4(SpellCheckService(), "b");
  t1.join();
  t2.join();
  t3.join();
  t4.join();
  return 0;
}
