#include <bits/stdc++.h>
using namespace std;
struct TreeNode {
		int val;
		TreeNode *left;
		TreeNode *right;
		TreeNode()
		  : val(0)
		  , left(nullptr)
		  , right(nullptr) {}
		TreeNode(int x)
		  : val(x)
		  , left(nullptr)
		  , right(nullptr) {}
		TreeNode(int x, TreeNode *left, TreeNode *right)
		  : val(x)
		  , left(left)
		  , right(right) {}
};
class Solution {
	public:
		TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
			return chaewon(
			  preorder, inorder, 0, preorder.size(), 0, inorder.size());
		}
		TreeNode *chaewon(
		  const vector<int> &preorder, const vector<int> &inorder,
		  int pre_left, int pre_right, int in_left, int in_right) {
			if (pre_left == pre_right) return nullptr;
			TreeNode *root = new TreeNode(preorder[pre_left]);
			if (pre_right - pre_left == 1) return root;
			int left_cnt = 0;
			for (int i = in_left; i < in_right; i++) {
				if (inorder[i] == preorder[pre_left]) break;
				left_cnt++;
			}
			root->left = chaewon(
			  preorder, inorder, pre_left + 1,
			  pre_left + left_cnt + 1, in_left, in_left + left_cnt);
			root->right = chaewon(
			  preorder, inorder, pre_left + left_cnt + 1,
			  pre_right, in_left + left_cnt + 1, in_right);
			return root;
		}
};
int main() {}