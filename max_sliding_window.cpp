// =====================================================
// Book: Elements of programming interviews
// Problem 8.14: Max of a sliding window
// =====================================================

#include <iostream>
#include <queue>
#include <deque>
#include <vector>

using namespace std;

template<typename T>
class QueueWithMax {
  queue<T> data;
  deque<T> candidates;

 public:
  void enqueue(const T& value) {
    while (!candidates.empty() && value > candidates.back()) {
      candidates.pop_back();
    }

    candidates.push_back(value);
    data.push(value);
  }

  T dequeue() {
    if (candidates.front() == data.front())
      candidates.pop_front();

    T value = data.front();
    data.pop();
    return value;
  }

  T max() {
    return candidates.front();
  }

  T front() {
    return data.front();
  }
};

class TimeVolume {
 public:
  int time, volume;

  TimeVolume(int time, int volume) : time(time), volume(volume) {}

  bool operator<(const TimeVolume& that) const {
    return time < that.time;
  }

  bool operator>(const TimeVolume& that) const {
    return volume > that.volume;
  }

  bool operator==(const TimeVolume& that) const {
    return time == that.time && volume == that.volume;
  }
};

// Problem  Max of a sliding window
vector<int> max_sliding_window(
  vector<TimeVolume>& tv, int window_size
) {
  vector<int> result;
  QueueWithMax<TimeVolume> q;
  for (size_t i = 0; i < tv.size(); i++) {
    q.enqueue(tv[i]);
    while (tv[i].time - q.front().time > window_size)
      q.dequeue();
    result.push_back(q.max().volume);
  }
  return result;
}

ostream& operator<<(ostream& os, vector<int> x) {
  for (size_t i = 0; i < x.size(); i++) {
    cout << x[i];
    if (i < x.size() - 1) cout << ", ";
  }
  return os;
}

int main() {
  vector<TimeVolume> tv;
  tv.push_back(TimeVolume(0, 5));
  tv.push_back(TimeVolume(2, 2));
  tv.push_back(TimeVolume(3, 4));
  tv.push_back(TimeVolume(5, 3));
  tv.push_back(TimeVolume(6, 7));
  tv.push_back(TimeVolume(7, 8));
  tv.push_back(TimeVolume(9, 2));

  vector<int> r = max_sliding_window(tv, 3);
  cout << r << " should be 5, 5, 4, 4, 7, 8, 8." << endl;
}
