#include <bits/stdc++.h>
using namespace std;
int32_t main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n, m, a, b, topo_size = 0, res = 0;
	string s;
	cin >> n >> m >> s;
	vector<vector<int>> adj(n + 1);
	vector<int> in_degree(n + 1);
	vector<vector<int>> dp(n + 1, vector<int>(26, 0));
	while (m--) {
		cin >> a >> b;
		adj[a].push_back(b);
		in_degree[b]++;
	}
	queue<int> q;
	for (int i = 1; i <= n; i++)
		if (in_degree[i] == 0) q.push(i);
	while (!q.empty()) {
		auto cur = q.front();
		topo_size += 1;
		q.pop();
		dp[cur][s[cur - 1] - 'a']++;
		for (auto child : adj[cur]) {
			for (int i = 0; i < 26; i++) {
				dp[child][i] = max(dp[child][i], dp[cur][i]);
			}
			in_degree[child]--;
			if (in_degree[child] == 0) q.push(child);
		}
	}
	if (topo_size != n) cout << -1;
	else {
		for (int i = 1; i <= n; i++) {
			for (int j = 0; j < 26; j++) {
				res = max(res, dp[i][j]);
			}
		}
		cout << res;
	}
	return 0;
}