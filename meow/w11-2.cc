#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e4 + 5;
void dfs(int i, vector<bool>& vist, vector<int>& dfs_tree,
         vector<vector<int>>& route) {
	for (auto node : route[i]) {
		if (vist[node])continue;
		vist[node] = true;
		dfs(node, vist, dfs_tree, route);
	}
	dfs_tree.emplace_back(i);
}
int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n, m, a, b;
	cin >> n >> m;
	vector < bitset < maxn >> dp(maxn);
	vector<vector<int>> route(n + 1, vector<int>());
	while (m--) {
		cin >> a >> b;
		route[a].emplace_back(b);
	}
	// for (int mid = 1; mid <= n; mid++) {
	// 	for (int start = 1; start <= n; start++) {
	// 		if (start == mid) continue;
	// 		for (int end = 1; end <= n; end ++) {
	// 			if (end == start || end == mid
	// 			        || g[start][end])continue;
	// 			g[start][end] = g[start][mid] && g[mid][end];
	// 		}
	// 	}
	// }
	vector<bool> vist(n + 1, false);
	vector<int> dfs_tree;
	for (int i = 1; i <= n; i++) {
		vist[i] = true;
		dfs(i, vist, dfs_tree, route);
	}
	for (auto cc : dfs_tree) {
		dp[cc][cc] = 1;
		for (auto edge : route[cc]) {
			dp[cc] |= dp[edge];
		}
	}
	for (int i = 1; i <= n; i++)
		cout << dp[i].count() << " ";
	return 0;
}