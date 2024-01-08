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
  TreeNode *recoverFromPreorder(string traversal) {
    int n = traversal.size(), idx = 0;

    auto get_depth = [&]() {
      int res = 0;
      while (idx < n && traversal[idx] == '-') {
        res++;
        idx++;
      }
      return res;
    };

    auto get_num = [&]() {
      int res = 0;
      while (idx < n && traversal[idx] != '-') {
        res = res * 10 + (traversal[idx] - '0');
        idx++;
      }
      return res;
    };

    vector<TreeNode *> stk;
    vector<int> depth;
    TreeNode *root = new TreeNode(get_num());
    stk.push_back(root), depth.push_back(0);

    while (idx < n) {
      int cur_depth = get_depth();
      int cur_num = get_num();
      TreeNode *cur_node = new TreeNode(cur_num);
      while (depth.back() >= cur_depth) {
        stk.pop_back();
        depth.pop_back();
      }
      if (stk.back()->left == nullptr) {
        stk.back()->left = cur_node;
      } else {
        stk.back()->right = cur_node;
      }
      stk.push_back(cur_node), depth.push_back(cur_depth);
    }
    return root;
  }
};