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
    void dfs(TreeNode* root, vector<int>& leaves)
    {
        if (root->left == nullptr && root->right == nullptr) {
            leaves.emplace_back(root->val);
            return;
        }
        if (root->left)
            dfs(root->left, leaves);
        if (root->right)
            dfs(root->right, leaves);
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2)
    {
        vector<int> leaves_one, leaves_two;
        dfs(root1, leaves_one);
        dfs(root2, leaves_two);
        if (leaves_one == leaves_two)
            return true;
        return false;
    }
};
int main(void) { return 0; }