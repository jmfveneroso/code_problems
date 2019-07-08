#include <memory>
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

template<typename T>
class Node {
 public:
  T value;

  Node(T value) : value(value) {}

  vector< shared_ptr< Node<T> > > adjacent;

  void AddEdge(shared_ptr< Node<T> > node) {
    if (find(adjacent.begin(), adjacent.end(), node) != adjacent.end())
      return;

    adjacent.push_back(node);
  }

  void RemoveEdge(shared_ptr< Node<T> > node) {
    if (find(adjacent.begin(), adjacent.end(), node) != adjacent.end())
      return;

    adjacent.push_back(node);
  }
};

vector<int> KahnsAlgorithm(vector< shared_ptr< Node<int> > >& nodes) {
  vector<int> sorted_list;
  queue< shared_ptr< Node<int> > > without_edges;

  vector<int> degree(nodes.size(), 0);
  for (size_t i = 0; i < nodes.size(); i++) {
    for (auto& n : nodes[i]->adjacent)
      degree[n->value]++;
  }

  for (size_t i = 0; i < degree.size(); i++) {
    if (degree[i] == 0)
      without_edges.push(nodes[i]); 
  }

  while (!without_edges.empty()) {
    shared_ptr< Node<int> > current = without_edges.front();
    sorted_list.push_back(current->value);
    without_edges.pop();

    for (auto& n : current->adjacent) {
      degree[n->value]--;
      if (degree[n->value] == 0)
        without_edges.push(nodes[n->value]);
    }
  }

  if (sorted_list.size() != nodes.size())
    throw invalid_argument("The graph contains cycles.");
  return sorted_list; 
}

void DFSVisit(
  shared_ptr< Node<int> >& node, 
  vector<bool>& permanent,
  vector<bool>& temporary,
  vector<int>& sorted_nodes
) {
  if (permanent[node->value]) return;
  if (temporary[node->value])
    throw invalid_argument("The graph contains cycles.");
 
  temporary[node->value] = true;
  for (auto& n : node->adjacent)
    DFSVisit(n, permanent, temporary, sorted_nodes);
  temporary[node->value] = false;
   
  sorted_nodes.push_back(node->value);
  permanent[node->value] = true;
}

vector<int> DFS(vector< shared_ptr< Node<int> > >& nodes) {
  vector<int> sorted_nodes;
  vector<bool> permanent(nodes.size(), false);
  vector<bool> temporary(nodes.size(), false);

  for (size_t i = 0; i < nodes.size(); i++) {
    DFSVisit(nodes[i], permanent, temporary, sorted_nodes);
  }

  reverse(sorted_nodes.begin(), sorted_nodes.end());
  return sorted_nodes;
}

vector< shared_ptr< Node<int> > > CreateGraph1() {
  vector< shared_ptr< Node<int> > > nodes;
  for (int i = 0; i < 8; i++)
    nodes.push_back(make_shared< Node<int> >(i));

  nodes[0]->AddEdge(nodes[3]);
  nodes[1]->AddEdge(nodes[3]);
  nodes[1]->AddEdge(nodes[4]);
  nodes[2]->AddEdge(nodes[4]);
  nodes[2]->AddEdge(nodes[7]);
  nodes[3]->AddEdge(nodes[5]);
  nodes[3]->AddEdge(nodes[6]);
  nodes[3]->AddEdge(nodes[7]);
  nodes[4]->AddEdge(nodes[6]);
  return nodes;
}

vector< shared_ptr< Node<int> > > CreateGraph2() {
  vector< shared_ptr< Node<int> > > nodes;
  for (int i = 0; i < 8; i++)
    nodes.push_back(make_shared< Node<int> >(i));

  nodes[0]->AddEdge(nodes[3]);
  nodes[1]->AddEdge(nodes[3]);
  nodes[1]->AddEdge(nodes[4]);
  nodes[2]->AddEdge(nodes[4]);
  nodes[2]->AddEdge(nodes[7]);
  nodes[3]->AddEdge(nodes[5]);
  nodes[3]->AddEdge(nodes[6]);
  nodes[3]->AddEdge(nodes[7]);
  nodes[4]->AddEdge(nodes[6]);
  nodes[7]->AddEdge(nodes[2]);
  return nodes;
}

ostream& operator<<(ostream& os, const vector<int>& values) {
 for (auto& v : values) cout << v << " ";
 return os;
}

int main() {
  vector< shared_ptr< Node<int> > > nodes = CreateGraph1();
  cout << KahnsAlgorithm(nodes) << endl;

  try {
    nodes = CreateGraph2();
    cout << KahnsAlgorithm(nodes) << endl;
  } catch (invalid_argument& e) {
    cout << "Should catch exception." << endl;
  }

  nodes = CreateGraph1();
  cout << DFS(nodes) << endl;

  try {
    nodes = CreateGraph2();
    cout << DFS(nodes) << endl;
  } catch (invalid_argument& e) {
    cout << "Should catch exception." << endl;
  }

  return 0;
}
