#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class Solution
{
public:
    bool hasPathSum(TreeNode *root, int targetSum)
    {
        if (!root)
            return false;
        return getpv(root, 0, targetSum);
    }
    bool getpv(TreeNode *root, int sum, int targetSum)
    {
        if (!root->left && !root->right)
        {
            if (targetSum != sum + root->val)
                return false;
            else
                return true;
        }
        else
        {
            bool lp = false, rp = false;
            if (root->left)
                lp = getpv(root->left, sum + root->val, targetSum);
            if (root->right)
                rp = getpv(root->right, sum + root->val, targetSum);
            return lp || rp;
        }
    }
};
int main(void)
{
    TreeNode *root = new TreeNode();
    root->val = 1;
    root->right = new TreeNode();
    root->right->val = 2;
    root->right->right = new TreeNode();
    root->right->right->val = 3;
    Solution s;
    cout << s.hasPathSum(root, 5) << endl;
    return 0;
}