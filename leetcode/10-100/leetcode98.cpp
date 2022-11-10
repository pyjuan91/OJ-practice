#include <iostream>
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
    bool isValidBST(TreeNode* root)
    {
        return isValidBST(root, root->val, root->val, -1, -1);
    }
    bool isValidBST(TreeNode* root, int min, int max, int mostLeft, int mostRight)
    {
        if (root == nullptr)
            return true;
        if ((mostLeft != -1 && root->val <= min) || (mostRight != -1 && root->val >= max)) {
            return false;
        }
        return isValidBST(root->left, min, root->val, mostLeft, 0)
            && isValidBST(root->right, root->val, max, 0, mostRight);
    }
};
int main(void)
{
    Solution s;
    TreeNode* root = new TreeNode(2);
    root->left = new TreeNode(1);
    root->right = new TreeNode(3);
    cout << s.isValidBST(root) << endl;
    return 0;
}