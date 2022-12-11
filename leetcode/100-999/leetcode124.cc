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
    int res = -2000;
    int dfs(TreeNode* root)
    {
        if (root == nullptr)
            return -2000;
        int left = dfs(root->left), right = dfs(root->right);
        res = max({ res, root->val, root->val + left, root->val + right,
            root->val + left + right, left, right });
        return (max(left, right) > 0 ? max(left, right) : 0) + root->val;
    }
    int maxPathSum(TreeNode* root)
    {
        dfs(root);
        return res;
    }
};
int main(void) { return 0; }