#include <bits/stdc++.h>
using namespace std;

// Trie node class
class TrieNode {
 public:
  // A map to store children nodes
  std::unordered_map<char, std::unique_ptr<TrieNode>> children;
  // Flag to mark the end of a word
  int best_index = 0, best_length = numeric_limits<int>::max();
  // Method to get the next TrieNode given a character
  TrieNode* getNextNode(char c) {
    if (children.count(c)) {
      return children[c].get();
    }
    return nullptr;
  }
};

// Trie class
class Trie {
 private:
  std::unique_ptr<TrieNode> root;

 public:
  // Constructor
  Trie() : root(std::make_unique<TrieNode>()) {}

  TrieNode* getRoot() { return root.get(); }
  // Function to insert a word into the Trie
  void insert(const std::string& word, int index) {
    TrieNode* node = root.get();
    if (word.size() < node->best_length) {
      node->best_length = word.size();
      node->best_index = index;
    }
    for (char ch : word) {
      if (!node->children.count(ch)) {
        node->children[ch] = std::make_unique<TrieNode>();
      }
      node = node->children[ch].get();
      if (word.size() < node->best_length) {
        node->best_length = word.size();
        node->best_index = index;
      }
    }
  }

  // Function to search for a word in the Trie
  int search(const std::string& word) const {
    TrieNode* node = root.get();
    int res = node->best_index;
    for (char ch : word) {
      if (!node->children.count(ch)) {
        break;
      }
      node = node->children[ch].get();
      res = node->best_index;
    }
    return res;
  }
};

class Solution {
 public:
  vector<int> stringIndices(vector<string>& wordsContainer,
                            vector<string>& wordsQuery) {
    const int n = wordsContainer.size();
    const int m = wordsQuery.size();
    auto trie = Trie();
    for (int i = 0; i < n; i++) {
      reverse(wordsContainer[i].begin(), wordsContainer[i].end());
      trie.insert(wordsContainer[i], i);
    }
    vector<int> res;
    for (int i = 0; i < m; i++) {
      reverse(wordsQuery[i].begin(), wordsQuery[i].end());
      res.push_back(trie.search(wordsQuery[i]));
    }
    return res;
  }
};

int main() { return 0; }