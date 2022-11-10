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
    bool isBalanced(TreeNode *root)
    {
        if (!root)
            return true;
        if (abs(cd(root->left) - cd(root->right)) > 1)
            return false;
        else
            return isBalanced(root->left) && isBalanced(root->right);
    }
    int cd(TreeNode *root)
    {
        if (!root)
            return 0;
        return 1 + max(cd(root->left), cd(root->right));
    }
};
int main(void)
{
    return 0;
}