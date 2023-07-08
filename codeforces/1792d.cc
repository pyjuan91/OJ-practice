#include <bits/stdc++.h>
#define int long long
using namespace std;
struct Trie {
		int value;
		vector<Trie*> child;
		Trie(int _value) { value = _value; }
		Trie* find_child(int tar) {
			for (auto tr : child)
				if (tr->value == tar) return tr;
			return nullptr;
		}
};
void insert_trie(vector<int>& pos, int m, Trie* head) {
	auto cur = head;
	for (int i = 1; i <= m; i++) {
		if (cur->find_child(pos[i]) == nullptr)
			cur->child.push_back(new Trie(pos[i]));
		cur = cur->find_child(pos[i]);
	}
}
int find_longest_trie(vector<int>& a, Trie* head, int m) {
	int res = 0;
	auto cur = head;
	for (int i = 1; i <= m; i++) {
		if (cur->find_child(a[i]) == nullptr) break;
		res++, cur = cur->find_child(a[i]);
	}
	return res;
}
int32_t main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int t, n, m;
	cin >> t;
	while (t--) {
		cin >> n >> m;
		vector<vector<int>> a(n + 1, vector<int>(m + 1)),
		  trie(m + 1, vector<int>(m + 1, 0));
		vector<int> pos(m + 1);
		auto head = new Trie(-1);
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++)
				cin >> a[i][j], pos[a[i][j]] = j;
			insert_trie(pos, m, head);
		}
		for (int i = 1; i <= n; i++)
			cout << find_longest_trie(a[i], head, m) << " ";
		cout << "\n";
	}
	return 0;
}