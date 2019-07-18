#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;

struct Node
{
  int cost;
  vector<Node *> children;
  Node *parent;
  
  Node(int cost) : cost(cost), parent(nullptr), children() {
  }
};

int getCheapestCost( Node *rootNode ) {
   if (!rootNode) return 0;
  
   int min_cost = 99999999;
   
   queue< pair<Node*, int> > q;
   q.push({ rootNode, 0 });
   
   while (!q.empty()) {
     pair<Node*, int> current = q.front();
     q.pop();
     
     Node* node = current.first;
     int current_cost = current.second + node->cost;
     
     // It is a leaf node.
     if (!node->children.size()) {
       min_cost = min(min_cost, current_cost);
     } else {
       for (auto& c : node->children) {
         q.push({ c, current_cost });
       }
     }
   }
   return min_cost;
}

int main() {
  vector<Node*> nodes {
    new Node(0),
    new Node(5),
    new Node(3),
    new Node(6),
    new Node(4),
    new Node(2),
    new Node(0),
    new Node(1),
    new Node(5),
    new Node(1),
    new Node(10),
    new Node(1)
  };
  
  nodes[0]->children.push_back(nodes[1]);
  nodes[0]->children.push_back(nodes[2]);
  nodes[0]->children.push_back(nodes[3]);
  
  nodes[1]->children.push_back(nodes[4]);
  
  nodes[2]->children.push_back(nodes[5]);
  nodes[2]->children.push_back(nodes[6]);
  
  nodes[3]->children.push_back(nodes[7]);
  nodes[3]->children.push_back(nodes[8]);
  
  nodes[5]->children.push_back(nodes[9]);
  nodes[6]->children.push_back(nodes[10]);
  
  nodes[9]->children.push_back(nodes[11]);
  
  cout << getCheapestCost(nodes[0]) << " should be 7." << endl;
  
  return 0;
}
