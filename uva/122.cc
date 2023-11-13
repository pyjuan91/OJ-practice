#include <bits/stdc++.h>
using namespace std;
struct Node {
		Node *left, *right;
		int val;
		Node(int val)
		  : val(val)
		  , left(nullptr)
		  , right(nullptr) {}
		Node()
		  : Node(0) {}
};
int32_t main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	string cmd;
	queue<Node*> q;
	while (cin >> cmd) {
		if (cmd == "())") {
			cout << "not complete\n";
			continue;
		}
		vector<string> nodes = {cmd};
		vector<int> ans;
		while (cin >> cmd && cmd != "()") nodes.push_back(cmd);
		auto get_number = [&](const string& s) {
			int res = 0;
			for (int i = 1; i < s.length() && isdigit(s[i]); ++i)
				res = res * 10 + s[i] - '0';
			return res;
		};
		auto get_position = [&](const string& s) {
			string suf;
			for (int i = s.length() - 2; i >= 0 && s[i] != ','; --i)
				suf.push_back(s[i]);
			reverse(suf.begin(), suf.end());
			return suf;
		};
		Node* root = new Node(0);
		for (auto s : nodes) {
			int val = get_number(s);
			string suf = get_position(s);
			auto cur = root;
			for (auto c : suf) {
				if (c == 'L') {
					if (!cur->left) cur->left = new Node(0);
					cur = cur->left;
				}
				else {
					if (!cur->right) cur->right = new Node(0);
					cur = cur->right;
				}
			}
			if (cur->val) {
				cout << "not complete\n";
				goto end;
			}
			cur->val = val;
		}
		while (!q.empty()) q.pop();
		q.push(root);
		while (!q.empty()) {
			auto cur = q.front();
			q.pop();
			if (cur->val == 0) {
				cout << "not complete\n";
				goto end;
			}
			ans.push_back(cur->val);
			if (cur->left) q.push(cur->left);
			if (cur->right) q.push(cur->right);
		}
		for (int i = 0; i < ans.size(); ++i) {
			if (i) cout << ' ';
			cout << ans[i];
		}
		cout << '\n';
	end:;
	}
	return 0;
}
