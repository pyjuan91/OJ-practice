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
public:
    int rangeSumBST(TreeNode* root, int low, int high)
    {
        int res = 0;
        if (root == nullptr)
            return 0;
        if (root->val >= low && root->val <= high) {
            res += root->val;
            res += rangeSumBST(root->left, low, high);
            res += rangeSumBST(root->right, low, high);
        }

        if (root->val < low)
            res += rangeSumBST(root->right, low, high);

        if (root->val > high)
            res += rangeSumBST(root->left, low, high);

        return res;
    }
};
int main(void) { return 0; }