#include <bits/stdc++.h>
#define int long long
using namespace std;
struct Edge {
		int u, v, w;
		Edge(int u, int v, int w)
		  : u(u)
		  , v(v)
		  , w(w) {}
		Edge() {}
};
int32_t main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n, m, a, b, c;
	vector<Edge> edges;
	cin >> n >> m;
	vector<vector<int>> adj(n + 1);
	for (int i = 0; i < m; ++i) {
		cin >> a >> b >> c;
		edges.emplace_back(a, b, -c);
		adj[a].emplace_back(b);
	}
	vector<int> dist(n + 1, INT64_MAX);
	dist[1] = 0;
	for (int i = 1; i < n; i++) {
		for (auto& e : edges) {
			int u = e.u, v = e.v, w = e.w;
			if (dist[u] != INT64_MAX) {
				dist[v] = min(dist[v], dist[u] + w);
			}
		}
	}
	for (auto& e : edges) {
		int u = e.u, v = e.v, w = e.w;
		if (dist[u] == INT64_MAX) continue;
		if (dist[v] > dist[u] + w) {
			vector<bool> vis(n + 1, false);
			vis[v] = true;
			function<bool(int)> dfs = [&](int u) {
				if (u == n) return true;
				for (auto child : adj[u]) {
					if (!vis[child]) {
						vis[child] = true;
						if (dfs(child)) return true;
					}
				}
				return false;
			};
			if (dfs(v)) {
				cout << -1 << '\n';
				return 0;
			}
		}
	}
	cout << -dist[n] << '\n';
	return 0;
}