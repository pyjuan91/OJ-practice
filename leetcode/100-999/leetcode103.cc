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
  vector<vector<int>> zigzagLevelOrder(TreeNode *root) {
    vector<vector<int>> res;
    if (root == nullptr) return res;
    queue<TreeNode *> q, nq;
    q.push(root);
    bool left_to_right = true;
    while (!q.empty()) {
      vector<int> v;
      while (!q.empty()) {
        v.push_back(q.front()->val);
        if (q.front()->left) nq.push(q.front()->left);
        if (q.front()->right) nq.push(q.front()->right);
        q.pop();
      }
      if (left_to_right == false) reverse(v.begin(), v.end());
      left_to_right = !left_to_right;
      swap(q, nq);
      res.push_back(v);
    }
    return res;
  }
};