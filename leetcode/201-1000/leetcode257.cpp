#include <algorithm>
#include <cstring>
#include <iostream>
#include <string>
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
    vector<vector<int>> vv;
    vector<int> v;
    vector<string> binaryTreePaths(TreeNode* root)
    {
        dfs(root);
        vector<string> ans;
        string str;
        int first;
        for (auto i : vv) {
            first = 1, str = "";
            for (auto j : i) {
                if (first)
                    first = 0;
                else
                    str += "->";
                str += to_string(j);
            }
            ans.push_back(str);
        }
        return ans;
    }
    void dfs(TreeNode* root)
    {
        v.push_back(root->val);
        if (!root->left && !root->right) {
            vv.push_back(v);
            return;
        }
        if (root->left) {
            dfs(root->left);
            v.pop_back();
        }
        if (root->right) {
            dfs(root->right);
            v.pop_back();
        }
    }
};
int main(void)
{
    Solution s;
    TreeNode* root = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left = new TreeNode(1);
    vector<string> ans = s.binaryTreePaths(root);
    for (auto i : ans)
        cout << i << endl;
    // s.dfs(root);
    return 0;
}