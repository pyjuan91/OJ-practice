#include <iostream>
#include <cstdbool>
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
    bool isSameTree(TreeNode *p, TreeNode *q)
    {
        if(p == nullptr && q != nullptr) return false;
        if(p != nullptr && q == nullptr) return false;
        if(p == nullptr && q == nullptr) return true;
        bool left_same = true;
        bool right_same = true;
        if (p->left != nullptr)
        {
            if (q->left == nullptr)
                return false;
            else
                left_same = isSameTree(p->left, q->left);
        }
        else if(q->left != nullptr) return false;

        if(p->right != nullptr)
        {
            if(q->right == nullptr)
                return false;
            else
                right_same = isSameTree(p->right, q->right);
        }
        else if(q->right != nullptr) return false;

        return q->val == p->val && left_same && right_same;
    }
};

int main(void)
{
    return 0;
}