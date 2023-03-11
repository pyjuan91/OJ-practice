#include <bits/stdc++.h>
using namespace std;

struct ListNode {
		int val;
		ListNode *next;
		ListNode()
			: val(0)
			, next(nullptr) {}
		ListNode(int x)
			: val(x)
			, next(nullptr) {}
		ListNode(int x, ListNode *next)
			: val(x)
			, next(next) {}
};

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
		TreeNode *sortedListToBST(ListNode *head) {
			vector<int> nodes;
			while (head) {
				nodes.emplace_back(head->val);
				head = head->next;
			}
			return chaewon(nodes);
		}
		TreeNode *chaewon(vector<int> nodes) {
			if (nodes.size() == 0) return nullptr;
			if (nodes.size() == 1)
				return new TreeNode(nodes[0]);
			int mid = nodes.size() / 2;
			TreeNode *res = new TreeNode(nodes[mid]);
			vector<int> right(
				nodes.begin() + mid + 1, nodes.end());

			nodes.erase(nodes.begin() + mid, nodes.end());
			res->left = chaewon(nodes);
			res->right = chaewon(right);
			return res;
		}
};
void print(TreeNode *head) {
	if (head == nullptr) return;
	cout << head->val << " ";
	print(head->left);
	print(head->right);
}
int main() {
	auto s = Solution();
	ListNode *head = new ListNode(9);
	head = new ListNode(5, head);
	head = new ListNode(0, head);
	head = new ListNode(-3, head);
	head = new ListNode(-10, head);
	TreeNode *res = s.sortedListToBST(head);
	print(res);
	return 0;
}