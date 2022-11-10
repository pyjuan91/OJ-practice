#include <algorithm>
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
private:
    vector<double> res;
    vector<int> ln;

public:
    vector<double> averageOfLevels(TreeNode* root)
    {
        res.clear();
        ln.clear();
        solve(root, 0);

        for (int i = 0; i < res.size(); i++) {
            res[i] /= ln[i];
        }
        return res;
    }

    void solve(TreeNode* root, int level)
    {
        if (root == nullptr)
            return;
        if (level == res.size()) {
            res.push_back(0.0);
            ln.push_back(0);
        }
        res[level] += root->val;
        ln[level] += 1;
        solve(root->left, level + 1);
        solve(root->right, level + 1);
    }
};
int main(void) { return 0; }