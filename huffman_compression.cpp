// =====================================================
// Book: Elements of programming interviews
// Problem 15.26: Huffman encoding
// =====================================================

#include <iostream>
#include <string>
#include <unordered_map>
#include <queue>
#include <memory>

using namespace std;

class BinTree {
 public:
  char c;
  int counts;
  shared_ptr< BinTree > lft;
  shared_ptr< BinTree > rgt;

  BinTree(
    char c,
    int counts,
    shared_ptr<BinTree> lft,
    shared_ptr<BinTree> rgt
  ) : c(c), counts(counts), lft(lft), rgt(rgt) {}
};

class Comparator {
 public:
  bool operator()(const shared_ptr<BinTree>& a, const shared_ptr<BinTree>& b) const {
    return a->counts > b->counts;
  }
};

void print_codes(shared_ptr<BinTree> node, const string& prefix) {
  if (!node) return;
  if (!node->lft && !node->rgt)
    cout << node->c << "(" << node->counts << "): " << prefix << endl;

  print_codes(node->lft, prefix + "0");
  print_codes(node->rgt, prefix + "1");
}

void build_huffman_tree(string& s) {
  unordered_map<char, size_t> counts;

  for (auto& c : s) {
    if (c == ' ') continue;
    if (counts.find(c) == counts.end())
      counts[c] = 0;
    counts[c]++;
  }

  priority_queue<shared_ptr<BinTree>, vector< shared_ptr<BinTree> >, Comparator> q;
  for (auto& p : counts)
    q.push(make_shared<BinTree>(p.first, p.second, nullptr, nullptr));

  while (q.size() > 1) {
    shared_ptr<BinTree> first = q.top();
    q.pop();
    shared_ptr<BinTree> second = q.top();
    q.pop();

    shared_ptr<BinTree> new_node = make_shared<BinTree>(
      '\0', first->counts + second->counts, first, second
    );
    q.push(new_node);
  }

  print_codes(q.top(), "");
}

int main() {
  string s = "lorem ipsum dolor sit amet consectetur adipiscing elit \
              donec eleifend metus eget libero bibendum quis vulputate \
              arcu tincidunt duis sed feugiat diam integer sed venenatis \
              libero donec suscipit nibh faucibus eleifend viverra urna";

  build_huffman_tree(s);
  return 0;
}
