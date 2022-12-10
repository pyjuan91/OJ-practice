#include <iostream>
#include <queue>
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
    int allSum = 0;
    long long res = 0;
    int calculateSum(TreeNode* root)
    {
        if (root == nullptr)
            return 0;
        return root->val + calculateSum(root->left) + calculateSum(root->right);
    }
    int solve(TreeNode* root)
    {
        if (root == nullptr)
            return 0;
        int leftSum = solve(root->left), rightSum = solve(root->right);
        res = max({ res,
            1LL * leftSum * (allSum - leftSum),
            1LL * rightSum * (allSum - rightSum) });
        return root->val + leftSum + rightSum;
    }
    int maxProduct(TreeNode* root)
    {
        allSum = calculateSum(root);
        long long mod = 1e9 + 7;
        solve(root);
        return res % mod;
    }
};
int main(void) { return 0; }