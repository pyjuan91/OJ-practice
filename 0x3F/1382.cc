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
  TreeNode* balanceBST(TreeNode* root) {
    vector<TreeNode*> nodes;
    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
      TreeNode* cur_node = q.front();
      q.pop();
      nodes.push_back(cur_node);
      if (cur_node->left) q.push(cur_node->left);
      if (cur_node->right) q.push(cur_node->right);
    }
    for (auto& node : nodes) {
      node->left = node->right = nullptr;
    }
    sort(nodes.begin(), nodes.end(),
         [](const auto& lhs, const auto& rhs) { return lhs->val < rhs->val; });

    auto build_bst = [&](this auto& self, int left, int right) -> TreeNode* {
      if (left + 1 == right) return nodes[left];
      if (left == right) return nullptr;
      int root_id = left + (right - left) / 2;
      TreeNode* cur_root = nodes[root_id];
      cur_root->left = self(left, root_id);
      cur_root->right = self(root_id + 1, right);
      return cur_root;
    };

    return build_bst(0, nodes.size());
  }
};