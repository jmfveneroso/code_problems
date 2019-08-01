#include <iostream>
#include <memory>
#include <vector>

using namespace std;

#define TABLE_SIZE 10

int hash_fn(const string& s) {
  unsigned int accumulator = 0;
  for (const char& c : s) {
    accumulator += (79 * (unsigned int) c);
    accumulator %= TABLE_SIZE;
  }
  return accumulator;
}

class HashNode {
 public:
  string key;
  int value;
  shared_ptr<HashNode> next;

  HashNode(string key, int value) : key(key), value(value), next(nullptr) {}
};

class HashTable {
  vector< shared_ptr<HashNode> > entries_;

 public:
  HashTable() : entries_(TABLE_SIZE, nullptr) {}

  void Put(const string& key, int value) {
    int index = hash_fn(key);
    shared_ptr<HashNode> node = entries_[index];
    if (!node) {
      entries_[index] = make_shared<HashNode>(key, value);
      return; 
    }

    while (node->next) {
      if (node->key == key) {
        node->value = value;
        return;
      }
      node = node->next;
    }
    node->next = make_shared<HashNode>(key, value);
  }

  int Get(const string& key) {
    int index = hash_fn(key);
    shared_ptr<HashNode> node = entries_[index];
    while (node) {
      if (node->key == key)
        return node->value; 
      node = node->next;
    } 

    if (!node) return -1;
    return node->value;
  }

  void Remove(const string& key) {
    int index = hash_fn(key);
    shared_ptr<HashNode> node = entries_[index];
    shared_ptr<HashNode> prev = nullptr;
    while (node) {
      if (node->key == key) break; 
      prev = node;
      node = node->next;
    } 

    if (!node) return;

    if (!prev) {
      entries_[index] = node->next;
    } else {
      prev->next = node->next;
    }
  }
};

int main() {
  cout << hash_fn("one")   << " should be 8." << endl;
  cout << hash_fn("two")   << " should be 4." << endl;
  cout << hash_fn("three") << " should be 4." << endl;
  cout << hash_fn("four")  << " should be 6." << endl;
  cout << hash_fn("five")  << " should be 4." << endl;
  cout << hash_fn("six")   << " should be 0." << endl;
  cout << hash_fn("seven") << " should be 5." << endl;

  HashTable ht;
  ht.Put("one", 1);
  ht.Put("two", 2);
  ht.Put("three", 3);

  cout << ht.Get("one") << " should be 1." << endl;
  cout << ht.Get("two") << " should be 2." << endl;
  cout << ht.Get("three") << " should be 3." << endl;
  ht.Remove("three");
  cout << ht.Get("three") << " should be -1." << endl;

  ht.Put("five", 5);
  cout << ht.Get("five") << " should be 5." << endl;

  return 0;
}
