#include <algorithm>
#include <iostream>
#include <set>
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

struct entry {
    int v, r, c;

    entry(int v, int r, int c)
    {
        this->v = v;
        this->r = r;
        this->c = c;
    }

    bool operator<(const entry& b) const
    {
        if (c == b.c) {
            if (r == b.r) {
                return v < b.v;
            }
            return r < b.r;
        }
        return c < b.c;
    }
};

class Solution {
private:
    multiset<entry> s;

public:
    vector<vector<int>> verticalTraversal(TreeNode* root)
    {
        s.clear();
        traverse(root, 0, 0);
        vector<vector<int>> res;
        vector<int> tmp;
        int pre = 10005;
        for (entry i : s) {
            if (i.c != pre) {
                if (!tmp.empty())
                    res.push_back(tmp);
                tmp.clear();
                pre = i.c;
                tmp.push_back(i.v);
            } else {
                tmp.push_back(i.v);
            }
            // cout << i.v << " " << i.r << " " << i.c << endl;
        }
        if (!tmp.empty())
            res.push_back(tmp);
        return res;
    }

    void traverse(TreeNode* root, int r, int c)
    {
        if (root == nullptr)
            return;
        // cout << root->val << " " << r << " " << c << endl;
        entry e(root->val, r, c);
        s.insert(e);

        traverse(root->left, r + 1, c - 1);
        traverse(root->right, r + 1, c + 1);
    }
};
int main(void)
{
    Solution s;
    // TreeNode* head = new TreeNode(3);
    // head->left = new TreeNode(9);
    // head->right = new TreeNode(20);
    // head->right->left = new TreeNode(15);
    // head->right->right = new TreeNode(7);

    TreeNode* head = new TreeNode(1);
    head->left = new TreeNode(2);
    head->right = new TreeNode(3);
    head->left->left = new TreeNode(4);
    head->left->right = new TreeNode(5);
    head->right->left = new TreeNode(5);
    head->right->right = new TreeNode(7);
    s.verticalTraversal(head);
    return 0;
}