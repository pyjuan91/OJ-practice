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

class BSTIterator {
 public:
  BSTIterator(TreeNode *root) { push_left(root); }

  int next() {
    TreeNode *node = height_stk.top();
    height_stk.pop();
    push_left(node->right);
    return node->val;
  }

  bool hasNext() { return !height_stk.empty(); }

 private:
  stack<TreeNode *> height_stk;

  void push_left(TreeNode *node) {
    while (node) {
      height_stk.push(node);
      node = node->left;
    }
  }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
int main() {
  TreeNode *root = new TreeNode(7);
  root->left = new TreeNode(3);
  root->right = new TreeNode(15);
  root->right->left = new TreeNode(9);
  root->right->right = new TreeNode(20);

  BSTIterator *obj = new BSTIterator(root);
  return 0;
}