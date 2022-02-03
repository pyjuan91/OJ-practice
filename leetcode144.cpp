#include <iostream>
#include <vector>
#include <algorithm>
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
    vector<int> preorderTraversal(TreeNode *root)
    {
        vector<int> ans;
        pre(root, ans);
        return ans;
    }
    void pre(TreeNode *root, vector<int> &ans)
    {
        if(!root) return;
        ans.push_back(root->val);
        pre(root->left, ans);
        pre(root->right, ans);
    }
};
int main(void)
{
    return 0;
}