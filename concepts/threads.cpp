// Thread examples

#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>

using namespace std;

void no_args() {
  cout << "Thread 1." << endl;
}

void args_by_val(int i) {
  i++;
}

void args_by_ref(int& i, int& j) {
  i++, j++;
}

void concurrent(int& k) {
  k++;
}

class thread_obj { 
 public: 
  void operator()(int& i) { 
    i++;
  } 
}; 

int main() {
  int i = 0, j = 0, k = 1;

  // Threads without parameters.
  thread t1(no_args);
  t1.join();

  // Threads with parameters passed by value.
  thread t2(args_by_val, i);
  t2.join();
  cout << "i: " << i << endl;

  // Threads with parameters passed by reference.
  thread t3(args_by_ref, ref(i), ref(j));
  t3.join();
  cout << "i: " << i << ", j: " << j << endl;

  // Concurrent threads without lock guard.
  thread t4([&] {
    k *= 3;
  });
 
  {
    this_thread::sleep_for(chrono::milliseconds(100));
    k += 1;
  }

  t4.join();
  cout << "k: " << k << endl;

  k = 1;

  // Concurrent threads with lock guard.
  mutex m;

  thread t5([&] {
    lock_guard<mutex> lock{m};
    k *= 3;
  });
 
  {
    lock_guard<mutex> lock{m};
    this_thread::sleep_for(chrono::milliseconds(100));
    k += 1;
  }

  t5.join();
  cout << "k: " << k << endl;

  // Thread object.
  thread t6(thread_obj(), ref(i));
  t6.join();
  cout << "i: " << i << endl;
  return 0;
}
