#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

class Edge {
 public:
  int a, b, weight;
};

bool Compare(const Edge& a, const Edge& b) {
  return a.weight < b.weight;
}

ostream& operator<<(ostream& os, vector<Edge> edges) {
  for (auto& e : edges) {
    cout << e.a << " - " << e.b << endl; 
  }
  return os;
}

vector<Edge> Kruskal(vector<Edge>& edges, size_t num_vertices) {
  vector<Edge> result;
  vector<int> disjoint_sets(num_vertices, -1);
  sort(edges.begin(), edges.end(), Compare);

  for (auto& e : edges) {
    int parent1 = e.a, parent2 = e.b;
    while (disjoint_sets[parent1] >= 0) parent1 = disjoint_sets[parent1];
    while (disjoint_sets[parent2] >= 0) parent2 = disjoint_sets[parent2];
    if (parent1 == parent2) continue;
 
    result.push_back(e);
    int parent1_size = -disjoint_sets[parent1];
    int parent2_size = -disjoint_sets[parent2];

    if (parent1_size >= parent2_size) {
      disjoint_sets[parent2] = parent1;
      disjoint_sets[parent1] -= parent2_size;
    } else {
      disjoint_sets[parent1] = parent2;
      disjoint_sets[parent2] -= parent1_size;
    }
  }
  return result;
}

int main() {
  vector<Edge> edges {
    { 0, 1, 1 }, { 1, 3, 5 },
    { 0, 2, 7 }, { 2, 3, 2 },
    { 1, 4, 6 }, { 4, 5, 3 },
    { 4, 6, 9 }, { 5, 7, 8 },
    { 6, 7, 4 }
  };

  cout << Kruskal(edges, 8);

  cout << "Should contain seven edges and ";
  cout << "should not contain (0, 2) or (4, 6)." << endl;
  return 0;
}
