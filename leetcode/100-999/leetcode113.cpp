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
		vector<vector<int>> pathSum(TreeNode *root, int targetSum) {
			vector<vector<int>> res;
			function<void(TreeNode *, int, vector<int> &)> dfs
			  = [&](TreeNode *root, int sum, vector<int> &path) {
				if (root->left == nullptr && root->right == nullptr) {
					if (sum == targetSum) {
						res.push_back(path);
					}
					return;
				}
				if (root->left != nullptr) {
					path.push_back(root->left->val);
					dfs(root->left, sum + root->left->val, path);
                    path.pop_back();
				}
				if (root->right != nullptr) {
					path.push_back(root->right->val);
					dfs(root->right, sum + root->right->val, path);
                    path.pop_back();
				}
			};
			if (root == nullptr) return res;
			vector<int> path = {root->val};
			dfs(root, root->val, path);
			return res;
		}
};
int main() {
	Solution s;
	return 0;
}