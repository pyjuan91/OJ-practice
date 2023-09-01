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
	while (m--) {
		cin >> a >> b >> c;
		edges.emplace_back(Edge(a, b, c));
	}
	vector<int> dist(n + 1, 1e15), prev(n + 1, 0);
	int cyc_comp = -1;
	for (int i = 0; i <= n; i++) {
		for (auto &e : edges) {
			if (dist[e.v] > dist[e.u] + e.w) {
				dist[e.v] = dist[e.u] + e.w;
				prev[e.v] = e.u;
				if (i == n) cyc_comp = e.v;
			}
		}
	}
	if (cyc_comp == -1) {
		cout << "NO\n";
		return 0;
	}
	int u = prev[cyc_comp];
	for (int _ = 0; _ < n; _++) u = prev[u];
	cout << "YES\n";
	vector<int> path = {u};
	int node = u;
	while (prev[node] != u) {
		path.push_back(prev[node]);
		node = prev[node];
	}
	reverse(path.begin(), path.end());
	for (auto x : path) cout << x << ' ';
	cout << path[0] << '\n';
	return 0;
}
