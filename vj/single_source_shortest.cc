#include <bits/stdc++.h>
#define int long long
using namespace std;
int32_t main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n, m, s;
	cin >> n >> m >> s;
	vector<vector<pair<int, int>>> g(n);
	for (int i = 0; i < m; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		g[u].push_back({w, v});
	}
	vector<int> dist(n, 1e18);
	dist[s] = 0;
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.push({0, s});
	while (!pq.empty()) {
		auto e = pq.top();
		pq.pop();
		if (e.first > dist[e.second]) continue;
		for (auto nxt : g[e.second]) {
			if (dist[nxt.second] > dist[e.second] + nxt.first) {
				dist[nxt.second] = dist[e.second] + nxt.first;
				pq.push({dist[nxt.second], nxt.second});
			}
		}
	}
	for (int i = 0; i < n; i++) {
		if (dist[i] == 1e18) cout << "INF\n";
		else cout << dist[i] << '\n';
	}
	return 0;
}
