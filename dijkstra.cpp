// Dijkstra.

#include <iostream>
#include <queue>
#include <vector>
#include <limits>

using namespace std;

ostream& operator<<(ostream& os, const vector<int>& v) {
  for (auto& i : v) cout << i << " ";
  return os;
}

class Vertex {
 public:
  int id = 0;
  bool visited = false;
  vector< pair<Vertex*, int> > edges;
  int min_distance = numeric_limits<int>::max(); 
  Vertex* prev = nullptr;

  Vertex(int id) : id(id) {}
};

class Compare {
 public:
  bool operator()(const Vertex* a, const Vertex* b) const {
    return a->min_distance > b->min_distance;
  }
};

int dijkstra(
  vector< Vertex >& vertices, Vertex* start, Vertex* end
) {
  for (auto& v : vertices) {
    v.visited = false;
    v.min_distance = numeric_limits<int>::max();
  }

  priority_queue< Vertex*, vector< Vertex* >, Compare > q;
  start->min_distance = 0;
  q.push(start);

  while (!q.empty()) {
    Vertex* current = q.top();
    q.pop();

    current->visited = true;
    for (auto& e : current->edges) {
      Vertex* destination = e.first;
      if (destination->visited) continue;

      int cost = e.second;
      int distance = current->min_distance + cost;
      if (distance < destination->min_distance) {
        destination->min_distance = distance;
        destination->prev = current;
      }
      q.push(destination);
    }
  }
  return end->min_distance;
}

int main () {
  vector<Vertex> vertices {
    Vertex(1),
    Vertex(2),
    Vertex(3),
    Vertex(4),
    Vertex(5),
    Vertex(6),
  };

  vertices[0].edges = { { &vertices[1], 7 }, { &vertices[2], 9 }, { &vertices[5], 14 } };
  vertices[1].edges = { { &vertices[5], 15 }, { &vertices[2], 10 } };
  vertices[2].edges = { { &vertices[3], 11 }, { &vertices[5], 2 } };
  vertices[3].edges = { { &vertices[4], 6 } };
  vertices[4].edges = { };
  vertices[5].edges = { { &vertices[4], 9 } };

  int min_distance = dijkstra(vertices, &vertices[0], &vertices[4]);
  cout << min_distance << " should be 20." << endl;

  vector<int> path;
  Vertex* current = &vertices[4];
  while (current) {
    path.insert(path.begin(), current->id);
    current = current->prev;
  }

  cout << path << "should be 1 3 6 5." << endl;
  return 0;
}
