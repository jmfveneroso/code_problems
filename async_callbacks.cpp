// =====================================================
// Book: Elements of programming interviews
// Problem 18.3: Asynchronous callbacks
// =====================================================

#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>
#include <string>
#include <cstdlib>
#include <vector>

using namespace std;

class RequestObj {
 public:
  string request;

  RequestObj(string request) : request(request) {}

  string Execute(const string& request) {
    this_thread::sleep_for(chrono::milliseconds(rand() % 1000));
    return "response-" + request;
  }

  string ProcessResponse(const string& response) {
    this_thread::sleep_for(chrono::milliseconds(100));
    return string("Processed ") + response;
  }
};

class Requester {
 public:
  vector<thread> thread_pool;
  vector<RequestObj> objs;
  vector<bool> done;

  void Dispatch(RequestObj obj) {
    thread_pool.push_back(thread([&] {
      string response = obj.Execute(obj.request);    
      cout << obj.ProcessResponse(response) << endl;     
    }));
  }

  void ProcessRequests() {
    for (auto& t : thread_pool) {
      t.join();
    }
  }
};

int main() {
  Requester requester;
  requester.Dispatch(RequestObj("A"));
  requester.Dispatch(RequestObj("B"));
  requester.Dispatch(RequestObj("C"));
  requester.Dispatch(RequestObj("D"));
  requester.Dispatch(RequestObj("E"));
  requester.ProcessRequests();
  return 0;
}
