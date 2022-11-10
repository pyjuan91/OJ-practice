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

// class Solution {
// public:
//     void flatten(TreeNode* root)
//     {
//         TreeNode *pos = root, *pos2;
//         while (pos) {
//             if (pos->left) {
//                 pos2 = pos->left;
//                 while (pos2->right) {
//                     pos2 = pos2->right;
//                 }
//                 pos2->right = pos->right;
//                 pos->right = pos->left;
//                 pos->left = nullptr;
//             }
//             pos = pos->right;
//         }
//     }
// };
class Solution {
private:
    TreeNode* pos;

public:
    void flatten(TreeNode* root)
    {
        pos = nullptr;
        iu(root);
        return;
    }
    void iu(TreeNode* root)
    {
        if (root == nullptr)
            return;
        iu(root->right);
        iu(root->left);
        root->right = pos;
        root->left = nullptr;
        pos = root;
    }
};
int main(void)
{
    Solution s;
    TreeNode* root = new TreeNode(1);
    root->right = new TreeNode(5);
    root->left = new TreeNode(2);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->right->right = new TreeNode(6);
    s.flatten(root);
    return 0;
}