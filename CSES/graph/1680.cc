#include <bits/stdc++.h>
using namespace std;
int32_t main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n, m, a, b;
	cin >> n >> m;
	vector<vector<int>> adj(n + 1);
	vector<int> in_degree(n + 1), dp(n + 1), prev(n + 1), res;
	while (m--) {
		cin >> a >> b;
		adj[a].emplace_back(b);
		in_degree[b]++;
	}
	queue<int> q;
	for(int i = 1; i <= n; i++)
        if (in_degree[i] == 0) q.push(i);
	dp[1] = 1;
	while (!q.empty()) {
		auto cur = q.front();
		q.pop();
		for (auto child : adj[cur]) {
			if (dp[cur] && dp[cur] + 1 > dp[child]) {
				dp[child] = dp[cur] + 1;
				prev[child] = cur;
			}
			in_degree[child]--;
			if (in_degree[child] == 0) q.push(child);
		}
	}
	if (prev[n] == 0) {
		cout << "IMPOSSIBLE";
		return 0;
	}
	int cur = n;
	while (cur != 1) {
		res.emplace_back(cur);
		cur = prev[cur];
	}
	res.emplace_back(1);
	reverse(res.begin(), res.end());
	cout << res.size() << "\n";
	for (auto x : res) cout << x << " ";
	return 0;
}