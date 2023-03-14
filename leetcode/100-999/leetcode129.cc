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
		void chaewon(TreeNode *root, int &cur, int &res) {
			if (!root->left && !root->right) {
				res += 10 * cur + root->val;
				return;
			}
			cur = cur * 10 + root->val;
			if (root->left) chaewon(root->left, cur, res);
			if (root->right) chaewon(root->right, cur, res);
			cur /= 10;
		}
		int sumNumbers(TreeNode *root) {
			int res = 0, cur = 0;
			chaewon(root, cur, res);
			return res;
		}
};