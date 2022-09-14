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
    int map[15], res;

public:
    int pseudoPalindromicPaths(TreeNode* root)
    {
        for (int i = 0; i < 15; i++) {
            map[i] = 0;
        }
        res = 0;
        dfs(root);
        return res;
    }

    void dfs(TreeNode* root)
    {
        if (root == nullptr)
            return;
        map[root->val] = 1 - map[root->val];
        if (root->left == nullptr && root->right == nullptr) {
            int mid = 0;
            for (int i = 1; i < 10; i++) {
                if (map[i])
                    mid++;
            }
            if (mid < 2)
                res++;
        }
        
        if (root->left)
            dfs(root->left);
        if (root->right)
            dfs(root->right);
        map[root->val] = 1 - map[root->val];
    }
};
int main(void) { return 0; }