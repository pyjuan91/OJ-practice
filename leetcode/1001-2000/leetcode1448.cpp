#include <algorithm>
#include <iostream>
#include <vector>
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
private:
    int ans;

public:
    int goodNodes(TreeNode* root)
    {
        ans = 0;
        solve(root, -10005);
        return ans;
    }
    void solve(TreeNode* root, int parentMaxVal)
    {
        if (root == nullptr)
            return;
        if (parentMaxVal <= root->val)
            ans++;
        solve(root->left, max(parentMaxVal, root->val));
        solve(root->right, max(parentMaxVal, root->val));
    }
};
int main(void) { return 0; }