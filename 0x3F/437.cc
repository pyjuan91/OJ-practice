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
    int64_t res_path_sum = 0, cur = 0;
    unordered_map<int64_t, int64_t> cnt;
    auto dfs = [&](this const auto& self, TreeNode* root) -> void {
      if (root == nullptr) return;
      cur += root->val;
      if (cur == targetSum) res_path_sum++;
      if (cnt.count(cur - targetSum)) res_path_sum += cnt[cur - targetSum];
      cnt[cur]++;
      if (root->left) self(root->left);
      if (root->right) self(root->right);
      cnt[cur]--;
      cur -= root->val;
    };
    dfs(root);
    return static_cast<int32_t>(res_path_sum);
  }
};

int main() { return 0; }