#include <bits/stdc++.h>
#define int long long
using namespace std;
int32_t main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n, a, b, c;
	cin >> n >> a >> b >> c;
	vector<vector<int>> g(n, vector<int>(n));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) cin >> g[i][j];
	}
	auto dijkstra = [&](int b, int c, int s) {
		vector<int> d(n, 1e18);
		d[s] = 0;
		priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
		pq.push({0, s});
		while (!pq.empty()) {
			auto [du, u] = pq.top();
			pq.pop();
			if (du > d[u]) continue;
			for (int v = 0; v < n; v++) {
				int w = g[u][v];
				if (d[v] > d[u] + w * b + c) {
					d[v] = d[u] + w * b + c;
					pq.push({d[v], v});
				}
			}
		}
		return d;
	};
	auto d1 = dijkstra(a, 0, 0);
	auto d2 = dijkstra(b, c, n - 1);
	int res = INT64_MAX;
	for (int i = 0; i < n; i++) res = min(res, d1[i] + d2[i]);
	cout << res << '\n';
	return 0;
}
