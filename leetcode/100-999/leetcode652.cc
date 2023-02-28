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
  const int none = 205;
  const int rootFlag = 300;
  map<string, vector<TreeNode *>> m;
  string chaewon(TreeNode *root) {
    if (root == nullptr) return "#";
    string cur = to_string(root->val) + "," + chaewon(root->left) + "," +
                 chaewon(root->right);
    m[cur].emplace_back(root);
    return cur;
  }
  vector<TreeNode *> findDuplicateSubtrees(TreeNode *root) {
    chaewon(root);
    vector<TreeNode *> res;
    for (auto p : m) {
      if (p.second.size() > 1) {
        // cout << p.first << endl;
        res.emplace_back(p.second[0]);
      }
    }
    return res;
  }
};
int main() {
  TreeNode *root = new TreeNode(2);
  root->left = new TreeNode(1);
  root->right = new TreeNode(11);
  root->left->left = new TreeNode(11);
  root->right->left = new TreeNode(1);
  // root->right->right->right = new TreeNode(0);
  auto s = Solution();
  s.findDuplicateSubtrees(root);
  return 0;
};