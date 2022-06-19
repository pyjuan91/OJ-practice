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
    vector<int> postorderTraversal(TreeNode *root)
    {
        vector<int> ans;
        pos(root, ans);
        return ans;
    }
    void pos(TreeNode *root, vector<int> &ans)
    {
        if (!root)
            return;
        pos(root->left, ans);
        pos(root->right, ans);
        ans.push_back(root->val);
    }
};
int main(void)
{
    return 0;
}