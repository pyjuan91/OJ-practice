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
		bool isCompleteTree(TreeNode *root) {
			queue<TreeNode *> q;
			q.push(root);
			while (!q.empty()) {
				auto n1 = q.front();
				q.pop();
				if (n1 == nullptr) {
					while (!q.empty()) {
						auto n2 = q.front();
						q.pop();
						if (n2 != nullptr) return false;
					}
					return true;
				}
				q.push(n1->left);
				q.push(n1->right);
			}
			return true;
		}
};
int main() { return 0; }