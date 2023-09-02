#include <bits/stdc++.h>
#define int long long
using namespace std;
int32_t main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n, m, k, a, b, c;
	cin >> n >> m >> k;
	vector<vector<pair<int, int>>> g(n + 1);
	vector<vector<int>> dist(n + 1);
	while (m--) {
		cin >> a >> b >> c;
		g[a].push_back({b, c});
	}
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.push({0ll, 1ll});
	while (!pq.empty()) {
		auto [d, u] = pq.top();
		pq.pop();
		if (dist[u].size() == k) continue;
		dist[u].push_back(d);
		for (auto [v, w] : g[u]) pq.push({d + w, v});
	}
	for (auto v : dist[n]) cout << v << ' ';
	return 0;
}