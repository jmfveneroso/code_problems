// =====================================================
// Book: Elements of programming interviews
// Problem 16.3: Wiring a printed circuit board
// =====================================================

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
  int d = -1;
  vector< Vertex* > edges;
  Vertex(int id) : id(id) {}
};

// The wiring problem is a two coloring problem. A graph that can 
// be two colored will only have cycles with an even number of
// vertices. This means that, when we perform a BFS, connected
// vertices will never have the same distance from the starting
// vertex. If we find a vertex that does not conform to this,
// we can determine that the graph cannot be two colored. The
// time complexity to solve this problem is O(V) where V is the
// number of vertices. A vertex can only be visited once.
bool breadth_first_search(Vertex* v) {
  queue<Vertex*> q;
  q.emplace(v);

  while (!q.empty()) {
    Vertex* current = q.front();
    q.pop();
    for (auto& e : current->edges) {
      if (e->d == -1) {
        e->d = current->d + 1;
        q.emplace(e);
      } else if (e->d == current->d)
        return false;
    }
  }
  return true;
}

bool is_feasible(vector<Vertex>& graph) {
  for (auto& v : graph) {
    if (v.d != -1) continue;
    v.d = 0;
    if (!breadth_first_search(&v)) 
      return false;
  }
  return true;
}

int main () {
  vector<Vertex> graph1 {
    Vertex(1), Vertex(2), Vertex(3), Vertex(4)
  };

  vector<Vertex> graph2 {
    Vertex(1), Vertex(2), Vertex(3), Vertex(4), Vertex(5)
  };

  // This is an undirected graph. The cycle 1-2-3-4-1.
  graph1[0].edges = { &graph1[1], &graph1[3] };
  graph1[1].edges = { &graph1[0], &graph1[2] };
  graph1[2].edges = { &graph1[1], &graph1[3] };
  graph1[3].edges = { &graph1[2], &graph1[0] };

  // This is an undirected graph. The cycle 1-2-3-4-5-1.
  graph2[0].edges = { &graph2[1], &graph2[4] };
  graph2[1].edges = { &graph2[0], &graph2[2] };
  graph2[2].edges = { &graph2[1], &graph2[3] };
  graph2[3].edges = { &graph2[2], &graph2[4] };
  graph2[4].edges = { &graph2[3], &graph2[0] };

  cout << is_feasible(graph1) << " should be true." << endl;
  cout << is_feasible(graph2) << " should be false." << endl;
  return 0;
}
