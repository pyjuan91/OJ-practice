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
  int pathSum(TreeNode* root, int targetSum) {
    if (!root) return 0;
    int res_path_sum = 0;
    auto dfs = [&](this const auto& self,
                   TreeNode* root) -> unordered_map<int64_t, int64_t> {
      unordered_map<int64_t, int64_t> res, lc, rc;
      if (root->left) lc = self(root->left);
      if (root->right) rc = self(root->right);
      for (const auto& [k, v] : lc) {
        res[k + root->val] += v;
      }
      for (const auto& [k, v] : rc) {
        res[k + root->val] += v;
      }
      res[root->val] += 1;
      if (res.count(targetSum)) res_path_sum += res[targetSum];
      return res;
    };
    dfs(root);
    return res_path_sum;
  }
};

int main() { return 0; }