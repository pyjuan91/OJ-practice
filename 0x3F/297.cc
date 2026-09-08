#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Codec {
 public:
  // Encodes a tree to a single string.
  string serialize(TreeNode* root) {
    if (root == nullptr) return "[]";
    queue<TreeNode*> q;
    q.push(root);
    string res = "[" + to_string(root->val);
    while (not q.empty()) {
      TreeNode* node = q.front();
      q.pop();

      if (node->left == nullptr)
        res += ",null";
      else {
        res += "," + to_string(node->left->val);
        q.push(node->left);
      }

      if (node->right == nullptr)
        res += ",null";
      else {
        res += "," + to_string(node->right->val);
        q.push(node->right);
      }
    }
    while (res.size() > 4 and res.substr(res.size() - 4) == "null") {
      res.resize(res.size() - 5);
    }
    res.push_back(']');
    return res;
  }

  // Decodes your encoded data to tree.
  TreeNode* deserialize(string data) {
    if (data.size() == 2) return nullptr;
    int idx = 0;
    auto eat = [&]() {
      while (idx < data.size() and not isdigit(data[idx]) and
             data[idx] != 'n' and data[idx] != '-') {
        idx++;
      }
      int sign = 1;
      if (idx < data.size() and data[idx] == '-') {
        idx++;
        sign = -1;
      }
      if (idx < data.size() and isdigit(data[idx])) {
        int res = 0;
        while (idx < data.size() and isdigit(data[idx])) {
          res = res * 10 + (data[idx] - '0');
          idx++;
        }
        return res * sign;
      }
      if (idx < data.size() and not isdigit(data[idx])) {
        idx++;
      }
      return 1005;
    };
    TreeNode* root = new TreeNode(eat());
    queue<TreeNode*> q;
    q.push(root);

    while (not q.empty()) {
      TreeNode* cur = q.front();
      q.pop();
      int left = eat();
      if (left != 1005) {
        cur->left = new TreeNode(left);
        q.push(cur->left);
      }
      int right = eat();
      if (right != 1005) {
        cur->right = new TreeNode(right);
        q.push(cur->right);
      }
    }

    return root;
  }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));

int main() { return 0; }