// =====================================================
// Book: Elements of programming interviews
// Problem 16.6: Theory of equality
// =====================================================

#include <iostream>
#include <vector>

using namespace std;

class Constraint {
 public:
  int a, b;
};

class Vertex {
 public:
  int id = 0;
  int group = -1;
  bool visited = false;
  vector<Vertex*> edges;

  Vertex(int id) : id(id) {}
};

void assign_group(Vertex* v, int group) {
  if (v->visited) return;

  v->visited = true;
  v->group = group;
  for (auto& e : v->edges)
    assign_group(e, group);
}

// This function checks the feasibility of a set of equality and
// inequality constraints in a set of variables. The time complexity
// is linear in the number of variables and constraints O(V + E).
bool is_feasible(
  vector<Vertex>& vertices,
  vector<Constraint>& equality,
  vector<Constraint>& inequality
) {
  for (auto& v : vertices) {
    v.visited = false;
    v.group = -1;
    v.edges = vector<Vertex*>();
  }

  for (auto& constraint : equality) {
    vertices[constraint.a].edges.push_back(&vertices[constraint.b]);
  }

  int group = 0;
  for (auto& v : vertices) {
    if (!v.visited)
      assign_group(&v, group++);
  }

  for (auto& constraint : inequality) {
    int group_a = vertices[constraint.a].group;
    int group_b = vertices[constraint.b].group;
    if (group_a == group_b && group_a != -1)
      return false;
  }
  return true;
}

int main() {
  vector<Vertex> vertices = {
    Vertex(0), Vertex(1),
    Vertex(2), Vertex(3)
  };
 
  vector<Constraint> equality {
    { 0, 1 }, { 1, 2 }
  };

  vector<Constraint> inequality {
    { 2, 1 }
  };

  cout << is_feasible(vertices, equality, inequality) << " should be false." << endl;

  vector<Constraint> equality2 {
    { 0, 1 }
  };

  vector<Constraint> inequality2 {
    { 2, 1 }
  };

  cout << is_feasible(vertices, equality2, inequality2) << " should be true." << endl;
  return 0;
}
