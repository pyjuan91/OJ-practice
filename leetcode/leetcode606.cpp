#include <iostream>
#include <string>
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
    string tree2str(TreeNode* root)
    {
        string str = "";
        if (root == nullptr)
            return "";
        str += to_string(root->val);
        if (root->left == nullptr && root->right == nullptr) {
            return str;
        } else if (root->left == nullptr) {
            str += "()(";
            str += tree2str(root->right);
            str += ")";
            return str;
        } else if (root->right == nullptr) {
            str += "(";
            str += tree2str(root->left);
            str += ")";
            return str;
        } else {
            str += "(";
            str += tree2str(root->left);
            str += ")";
            str += "(";
            str += tree2str(root->right);
            str += ")";
            return str;
        }
    }
};
int main(void) { return 0; }