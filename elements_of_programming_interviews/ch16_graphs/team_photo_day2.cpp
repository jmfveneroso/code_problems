// =====================================================
// Book: Elements of programming interviews
// Problem 16.7: Team photo day 2
// =====================================================

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Vertex {
 public:
  int id = 0;
  int max_distance = 0;
  vector< Vertex* > edges;
  bool visited = false;

  Vertex() {}
};

void depth_first_search(Vertex* v, vector<Vertex*>& vertex_order) {
  if (v->visited) return;
  v->visited = true; 
  for (auto& e : v->edges) {
    depth_first_search(e, vertex_order);
  } 
  vertex_order.push_back(v);
}

void topo_sort(vector<Vertex>& vertices, vector<Vertex*>& vertex_order) {
  for (size_t i = 0; i < vertices.size(); i++) 
    vertices[i].visited = false;

  for (auto& v : vertices)
    if (!v.visited)
      depth_first_search(&v, vertex_order);
}

int find_longest_path(vector<Vertex*>& vertex_order) {
  int max_distance = 0;
  while (vertex_order.size()) {
    auto v = vertex_order.back();
    max_distance = max(max_distance, v->max_distance);
    for (auto& e : v->edges) {
      e->max_distance = max(e->max_distance, v->max_distance + 1);
    }
    vertex_order.pop_back();
  }
  return max_distance;
}

int main () {
  vector<Vertex> vertices = vector<Vertex>(6, Vertex());
  for (int i = 0; i < 6; i++) vertices[i].id = i;
  vertices[2].edges = { &vertices[3] };
  vertices[3].edges = { &vertices[1] };
  vertices[4].edges = { &vertices[0], &vertices[1] };
  vertices[5].edges = { &vertices[0], &vertices[2] };

  vector<Vertex*> vertex_order;
  depth_first_search(&vertices[5], vertex_order);
  for (auto& v : vertex_order) cout << v->id << " ";
  cout << "should be 0 1 3 2 5." << endl;
 
  vertex_order = vector<Vertex*>();
  topo_sort(vertices, vertex_order);

  vector<Vertex*> vertex_order2 = vertex_order;
  while (vertex_order.size()) {
    cout << vertex_order.back()->id << " ";
    vertex_order.pop_back();
  }
  cout << "should be 5 4 2 3 1 0." << endl; 

  cout << find_longest_path(vertex_order2) << " should be 3." << endl;
  return 0;
}
