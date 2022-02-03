#include <iostream>
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
    bool isSymmetric(TreeNode *root)
    {
        if (root == nullptr)
            return true;
        if (root->left == nullptr && root->right == nullptr)
            return true;
        if (root->left == nullptr && root->right != nullptr)
            return false;
        if (root->left != nullptr && root->right == nullptr)
            return false;
        if (root->left->val != root->right->val)
            return false;
        // both have
        TreeNode *neo = new TreeNode();
        bool sym1 = true, sym2 = true;
        if (root->left->left)
        {
            if (!root->right->right)
                return false;
            else
            {
                neo->left = root->left->left;
                neo->right = root->right->right;
                sym1 = isSymmetric(neo);
            }
        }
        else if (root->right->right)
            return false;

        if (root->left->right)
        {
            if (!root->right->left)
                return false;
            else
            {
                neo->left = root->left->right;
                neo->right = root->right->left;
                sym2 = isSymmetric(neo);
            }
        }
        else if (root->right->left)
            return false;

        return sym1 && sym2;
    }
};
int main(void)
{
    return 0;
}