// =====================================================
// Book: Elements of programming interviews
// Problem 16.10: Quickest route
// =====================================================

#include <iostream>
#include <queue>
#include <vector>
#include <limits>
#include <unordered_map>

using namespace std;

ostream& operator<<(ostream& os, const vector<int>& v) {
  for (auto& i : v) cout << i << " ";
  return os;
}

class Flight {
 public:
  int id;
  int from;
  int to;
  int start_time;
  int arrival_time;
};

class City {
 public:
  int id = 0;
  int earliest_time = 0;
  bool visited = false;
  Flight* flight = nullptr;

  City(int id) : id(id) {}
};

class Compare {
 public:
  bool operator()(const City* a, const City* b) const {
    return a->earliest_time > b->earliest_time;
  }
};

int quickest_route(
  vector<Flight>& flights, vector<City>& cities, City* start, City* end
) {
  unordered_map<int, vector<Flight*> > from_flights;
  for (auto& f : flights) {
    if (from_flights.find(f.from) == from_flights.end())
      from_flights[f.from] = vector<Flight*>();
    from_flights[f.from].push_back(&f);
  }

  for (size_t i = 0; i < cities.size(); i++) {
    cities[i].visited = false;
    cities[i].earliest_time = numeric_limits<int>::max();
  }

  priority_queue< City*, vector< City* >, Compare > q;
  start->earliest_time = 0;
  q.push(start);

  while (!q.empty()) {
    City* current = q.top();
    q.pop();

    current->visited = true;
    for (auto& f : from_flights[current->id]) {
      if (cities[f->to-1].visited) continue;

      int min_time = 0;
      if (current != start)
        min_time = current->earliest_time + 60;
      if (f->start_time < min_time) continue;

      if (f->arrival_time < cities[f->to-1].earliest_time) {
        cities[f->to-1].earliest_time = f->arrival_time;
        cities[f->to-1].flight = f;
      }
      q.push(&cities[f->to-1]);
    }
  }

  return end->earliest_time;
}

int main () {
  vector<Flight> flights {
    {0, 1, 2, 0,   70 },
    {1, 1, 2, 30,  60 },
    {2, 1, 3, 200, 300},
    {3, 1, 4, 100, 400},
    {4, 2, 4, 150, 250},
    {5, 3, 5, 400, 500},
    {6, 4, 5, 380, 470}
  };

  vector<City> cities = vector<City>(5, City(0));
  for (size_t i = 0; i < cities.size(); i++) {
    cities[i].id = i+1;
  }

  int earliest_time = quickest_route(flights, cities, &cities[0], &cities[4]);
  cout << earliest_time << " should be 470." << endl;

  Flight* f = cities[4].flight;
  vector<Flight*> best_flights;
  while (f != nullptr) {
    best_flights.insert(best_flights.begin(), f);
    f = cities[f->from-1].flight;
  }

  for (auto& f : best_flights) {
    cout << "Fly from " << f->from << " to " << f->to << " arriving at " << f->arrival_time << endl;
  }
  return 0;
}
