#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode* left, TreeNode* right)
      : val(x), left(left), right(right) {}
};

class Solution {
 public:
  int findBottomLeftValue(TreeNode* root) {
    int res = root->val;
    queue<TreeNode*> q1, q2;
    q1.push(root);

    for (;;) {
      if (q1.empty()) break;
      while (!q1.empty()) {
        auto cur = q1.front();
        q1.pop();
        if (cur->left) q2.push(cur->left);
        if (cur->right) q2.push(cur->right);
      }
      if (!q2.empty()) res = q2.front()->val;
      swap(q1, q2);
      while (!q2.empty()) q2.pop();
    }
    return res;
  }
};

int main() { return 0; }