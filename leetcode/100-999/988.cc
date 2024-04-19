#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};

class Solution {
 public:
  string smallestFromLeaf(TreeNode *root) {
    set<string> result = stringSetFromLeaf(root);
    return *result.begin();
  }
  set<string> stringSetFromLeaf(TreeNode *root) {
    if (root == nullptr) return {};
    if (!root->left && !root->right) {
      return {string(1, root->val + 'a')};
    }
    set<string> leftSet = stringSetFromLeaf(root->left);
    set<string> rightSet = stringSetFromLeaf(root->right);
    set<string> result;
    for (auto &s : leftSet) {
      result.insert(s + string(1, root->val + 'a'));
    }
    for (auto &s : rightSet) {
      result.insert(s + string(1, root->val + 'a'));
    }
    return result;
  }
};
int main() {
  Solution s;
  return 0;
}