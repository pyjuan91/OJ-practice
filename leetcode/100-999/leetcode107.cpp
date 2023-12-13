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
		vector<vector<int>> levelOrderBottom(TreeNode *root) {
			vector<pair<int, int>> a;
			vector<vector<int>> res;
			if (root == nullptr) return res;
			queue<TreeNode *> q;
			queue<int> level;
			q.push(root), level.push(0);
			while (!q.empty()) {
				TreeNode *now = q.front();
				int now_level = level.front();
				q.pop(), level.pop();
				a.push_back({now_level, now->val});
				if (now->right != nullptr) {
					q.push(now->right), level.push(now_level + 1);
				}
				if (now->left != nullptr) {
					q.push(now->left), level.push(now_level + 1);
				}
			}
			while (!a.empty()) {
				int now_level = a.back().first;
				vector<int> tmp;
				while (!a.empty() && a.back().first == now_level) {
					tmp.push_back(a.back().second);
					a.pop_back();
				}
				res.push_back(tmp);
			}
			return res;
		}
};
int main() {
	Solution s;

	TreeNode *root = new TreeNode(3);
	root->left = new TreeNode(9);
	root->right = new TreeNode(20);
	root->right->right = new TreeNode(7);
	root->right->left = new TreeNode(15);

	vector<vector<int>> ans = s.levelOrderBottom(root);
	for (int i = 0; i < ans.size(); i++) {
		for (int j = 0; j < ans[i].size(); j++) {
			cout << ans[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}