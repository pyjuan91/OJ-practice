#include <bits/stdc++.h>
using namespace std;

// Trie node class
class TrieNode {
 public:
  // A map to store children nodes
  std::unordered_map<char, std::unique_ptr<TrieNode>> children;
  // Flag to mark the end of a word
  bool isEndOfWord = false;
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

  TrieNode* getRoot() {
    return root.get();
  }
  // Function to insert a word into the Trie
  void insert(const std::string& word) {
    TrieNode* node = root.get();
    for (char ch : word) {
      if (!node->children.count(ch)) {
        node->children[ch] = std::make_unique<TrieNode>();
      }
      node = node->children[ch].get();
    }
    node->isEndOfWord = true;
  }

  // Function to search for a word in the Trie
  bool search(const std::string& word) const {
    TrieNode* node = root.get();
    for (char ch : word) {
      if (!node->children.count(ch)) {
        return false;
      }
      node = node->children[ch].get();
    }
    return node->isEndOfWord;
  }

  // Function to check if there is any word in the Trie that starts with the
  // given prefix
  bool startsWith(const std::string& prefix) const {
    TrieNode* node = root.get();
    for (char ch : prefix) {
      if (!node->children.count(ch)) {
        return false;
      }
      node = node->children[ch].get();
    }
    return true;
  }
};
