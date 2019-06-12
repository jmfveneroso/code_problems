#include <iostream>
#include <unordered_set>
#include <vector>
#include <memory>

using namespace std;

class TrieNode {
public:
    char c;
    bool endword = false;
    bool found = false;
    shared_ptr<TrieNode> children[26];
    
    TrieNode(char c) : c(c) {}
};

void AddWord(shared_ptr<TrieNode> node, string& word) {
    for (auto& c : word) {
        if (!node->children[c - 'a'])
            node->children[c - 'a'] = make_shared<TrieNode>(c);
        node = node->children[c - 'a'];
    }
    node->endword = true;
}

class HashFn {
public:
     bool operator()(const pair<int,int>& a) const {
         return hash<int>()(a.first) ^ hash<int>()(a.second);
     }   
};

class Solution {
public:
    void findWordsAux(
        vector<vector<char>>& board, shared_ptr<TrieNode> node, 
        int x, int y, unordered_set<pair<int,int>, HashFn>& visited_nodes
    ) {
        if (visited_nodes.find({ x, y }) != visited_nodes.end()) return;
        if (x < 0 || x >= board.size() || y < 0 || y >= board[0].size()) return;
        
        char cur_char = board[x][y]; 
        if (!node->children[cur_char - 'a']) return;
        node = node->children[cur_char - 'a'];
       
 
        if (node->endword) node->found = true;
        visited_nodes.insert({ x, y });
            
        for (int i = -1; i <= 1; i += 2) {
             findWordsAux(board, node, x+i, y, visited_nodes);
             findWordsAux(board, node, x, y+i, visited_nodes);
        }
        
        visited_nodes.erase({ x, y });
    }
    
    void getWords(shared_ptr<TrieNode> node, vector<string>& result, string prefix) {
        if (node->endword && node->found)
            result.push_back(prefix);
            
        for (auto& n : node->children) {
            if (n)
                getWords(n, result, prefix + n->c);
        }
    }
    
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        // Build Trie.
        shared_ptr<TrieNode> root = make_shared<TrieNode>('\0');
        for (auto& w : words) AddWord(root, w);
        
        for (int x = 0; x < board.size(); x++) {
            for (int y = 0; y < board[0].size(); y++) {
                unordered_set<pair<int,int>, HashFn> visited_nodes;
                findWordsAux(board, root, x, y, visited_nodes);
            }
        }
        vector<string> result;
        getWords(root, result, "");
        return result;
    }
};

int main() {
  vector<vector<char>> board = {
    {'o','a','a','n'},
    {'e','t','a','e'},
    {'i','h','k','r'},
    {'i','f','l','v'}
  };

  vector<string> words { "oath","pea","eat","rain" };

  Solution s;
  vector<string> ws = s.findWords(board, words);
  for (auto& w : ws) cout << w << " ";

  cout << "should be: eat oath." << endl;
  return 0;
}
