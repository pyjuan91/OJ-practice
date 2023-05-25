#include <bits/stdc++.h>
using namespace std;
int chaewon(int n, vector<vector<int>>& tree, vector<int>& res, int cur) {
	if (res[cur] != -1) return res[cur];
	int rank = 1;
	for (auto child : tree[cur])
		rank += chaewon(n, tree, res, child);
	return res[cur] = rank;
}
int main() {
	cin.tie()->sync_with_stdio(false);
	int n, x;
	cin >> n;
	vector<vector<int>> tree(n + 1);
	vector<int> res(n + 1, -1);
	for (int i = 2; i <= n; i++) {
		cin >> x;
		tree[x].emplace_back(i);
	}
	chaewon(n, tree, res, 1);
	for (int i = 1; i <= n; i++) cout << res[i] - 1 << " ";
	return 0;
}