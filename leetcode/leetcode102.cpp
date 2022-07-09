#include <algorithm>
#include <iostream>
#include <queue>
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
    vector<vector<int>> levelOrder(TreeNode* root)
    {
        queue<TreeNode*> q;
        queue<int> levelRecord;
        int LR = 0;
        vector<vector<int>> ans;
        vector<int> single;
        q.push(root);
        levelRecord.push(LR);
        if (root != nullptr) {
            single.push_back(root->val);
            ans.push_back(single);
        }
        while (!q.empty()) {
            if (q.front() != nullptr) {
                int check = levelRecord.front();
                single.clear();
                while (!q.empty() && !levelRecord.empty() && levelRecord.front() == check) {
                    if (q.front()->left != nullptr) {
                        q.push(q.front()->left);
                        levelRecord.push(levelRecord.front() + 1);
                        single.push_back(q.front()->left->val);
                    }
                    if (q.front()->right != nullptr) {
                        q.push(q.front()->right);
                        levelRecord.push(levelRecord.front() + 1);
                        single.push_back(q.front()->right->val);
                    }
                    q.pop();
                    levelRecord.pop();
                }
                if (!single.empty()) {
                    ans.push_back(single);
                }
            } else {
                q.pop();
                levelRecord.pop();
            }
        }
        return ans;
    }
};
int main(void)
{
    Solution s;
    TreeNode *head, *now;
    now = head = new TreeNode(3);
    head->left = new TreeNode(9);
    head->left->left = new TreeNode(12);
    head->left->right = new TreeNode(11);
    head->right = new TreeNode(20);
    head = head->right;
    head->left = new TreeNode(15);
    head->right = new TreeNode(7);
    // s.anya(now);
    return 0;
}