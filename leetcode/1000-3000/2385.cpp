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
  int amountOfTime(TreeNode *root, int start) {
    vector<vector<int>> g(1e5 + 1);
    function<void(TreeNode *)> build = [&](TreeNode *cur) {
      if (cur->left) {
        g[cur->val].push_back(cur->left->val);
        g[cur->left->val].push_back(cur->val);
        build(cur->left);
      }
      if (cur->right) {
        g[cur->val].push_back(cur->right->val);
        g[cur->right->val].push_back(cur->val);
        build(cur->right);
      }
    };
    build(root);
    queue<int> q, d;
    q.push(start), d.push(0);
    vector<bool> vis(1e5 + 1, false);
    int res = 0;
    vis[start] = true;
    while (!q.empty()) {
      int cur = q.front();
      q.pop();
      int dep = d.front();
      res = max(res, dep);
      d.pop();
      for (int nxt : g[cur]) {
        if (vis[nxt]) continue;
        vis[nxt] = true;
        q.push(nxt);
        d.push(dep + 1);
      }
    }
    return res;
  }
};
