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
		TreeNode *node1 = nullptr;
		TreeNode *node2 = nullptr;
		TreeNode *prev = nullptr;
		void recoverTree(TreeNode *root) {
			chaewon(root);
			swap(node1->val, node2->val);
		}
		void chaewon(TreeNode *root) {
			if (root->left) chaewon(root->left);

			if (prev != nullptr && prev->val > root->val && node1 == nullptr)
				node1 = prev;
			if (prev != nullptr && prev->val > root->val && node1 != nullptr)
				node2 = root;
			prev = root;

			if (root->right) chaewon(root->right);
		}
};