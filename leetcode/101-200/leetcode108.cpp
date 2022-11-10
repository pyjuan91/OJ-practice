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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        TreeNode *root = new TreeNode();
        if(nums.empty())return nullptr;
        root->val = nums[nums.size()/2];
        vector<int> lt;
        vector<int> rt;
        lt.assign(nums.begin(), nums.begin()+nums.size()/2);
        root->left = sortedArrayToBST(lt);
        rt.assign(nums.begin() + nums.size()/2 + 1, nums.end());
        root->right = sortedArrayToBST(rt);
        return root;
    }
};
int main(void)
{
    return 0;
}