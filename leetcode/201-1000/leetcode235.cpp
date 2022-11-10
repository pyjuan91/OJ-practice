#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x)
        : val(x)
        , left(NULL)
        , right(NULL)
    {
    }
};

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)
    {
        TreeNode* now;
        if (q->val < p->val) {
            now = q;
            q = p;
            p = now;
        }
        now = root;
        while (now != nullptr) {
            if (now->val >= p->val && now->val <= q->val) {
                return now;
            } else if (now->val <= p->val) {
                now = now->right;
            } else {
                now = now->left;
            }
        }
        return now;
    }
};
int main(void)
{
    return 0;
}