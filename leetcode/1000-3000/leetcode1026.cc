#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode()
        : val(0)
        , left(nullptr)
        , right(nullptr)
    {
    }
    TreeNode(int x)
        : val(x)
        , left(nullptr)
        , right(nullptr)
    {
    }
    TreeNode(int x, TreeNode* left, TreeNode* right)
        : val(x)
        , left(left)
        , right(right)
    {
    }
};
class Solution {
public:
    int mi = INT32_MAX, ma = INT32_MIN;
    void update(TreeNode* root)
    {
        if (root == nullptr)
            return;
        mi = min(mi, root->val);
        ma = max(ma, root->val);
        update(root->left);
        update(root->right);
    }
    int maxAncestorDiff(TreeNode* root)
    {
        int res = 0;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            TreeNode* cur = q.front();
            q.pop();
            mi = INT32_MAX, ma = INT32_MIN;
            update(cur);
            res = max({ res, abs(mi - cur->val), abs(ma - cur->val) });
            if (cur->left)
                q.push(cur->left);
            if (cur->right)
                q.push(cur->right);
        }
        return res;
    }
};

int main(void) { return 0; }