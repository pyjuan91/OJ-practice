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
    int minDepth(TreeNode *root)
    {
        if (!root)
            return 0;
        if (!root->left)
        {
            if (root->right)
                return 1 + minDepth(root->right);
            else
                return 1;
        }
        else
        {
            if (!root->right)
                return 1 + minDepth(root->left);
            else
                return 1 + min(minDepth(root->left), minDepth(root->right));
        }
    }
};
int main(void)
{
    return 0;
}