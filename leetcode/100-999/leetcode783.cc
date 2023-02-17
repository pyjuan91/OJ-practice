#include <bits/stdc++.h>
using namespace std;
int main() { return 0; };
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
  int res;
  void go(TreeNode *node) {
    if (node->left) {
      res = min(res, node->val - rightMost(node->left));
      go(node->left);
    }
    if (node->right) {
      res = min(res, leftMost(node->right) - node->val);
      go(node->right);
    }
  }
  int rightMost(TreeNode *node) {
    if (node->right == nullptr) return node->val;
    return rightMost(node->right);
  }
  int leftMost(TreeNode *node) {
    if (node->left == nullptr) return node->val;
    return leftMost(node->left);
  }
  int minDiffInBST(TreeNode *root) {
    res = 1e9;
    go(root);
    return res;
  }
};