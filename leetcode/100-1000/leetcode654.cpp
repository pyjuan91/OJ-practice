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
public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums)
    {
        return build(nums, 0, nums.size());
    }

    TreeNode* build(vector<int>& nums, int left, int right)
    {
        if (left == right)
            return nullptr;
        int index, mv = -1;
        for (int i = left; i < right; i++) {
            if (nums[i] > mv) {
                mv = nums[i];
                index = i;
            }
        }
        TreeNode* head = new TreeNode(mv);
        head->left = build(nums, left, index);
        head->right = build(nums, index + 1, right);
        return head;
    }
};
int main(void)
{
    return 0;
}