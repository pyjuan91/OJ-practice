#include <bits/stdc++.h>
#define int long long
using namespace std;
using pii = pair<int, int>;
int32_t main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n, m, k, a, b, c, res = 0;
	cin >> n >> m >> k;
	vector<vector<pii>> g(n + 1);
	vector<int> train_route(n + 1, 0);
	while (m--) {
		cin >> a >> b >> c;
		g[a].emplace_back(b, c);
		g[b].emplace_back(a, c);
	}
	while (k--) {
		cin >> b >> c;
		if (train_route[b]) {
			train_route[b] = min(train_route[b], c);
			res++;
			continue;
		}
		train_route[b] = c;
	}
	for (int i = 2; i <= n; i++) {
		if (train_route[i]) {
			g[1].emplace_back(i, train_route[i]);
			g[i].emplace_back(1, train_route[i]);
		}
	}
	vector<int> dist(n + 1, 1e18), pass_through(n + 1, 0);
	priority_queue<pii, vector<pii>, greater<pii>> pq;
	pq.emplace(0, 1);
	dist[1] = 0;
	while (!pq.empty()) {
		auto [d, u] = pq.top();
		pq.pop();
		if (d > dist[u]) continue;
		for (auto [v, w] : g[u]) {
			if (d + w == dist[v]) pass_through[v]++;
			if (d + w < dist[v]) {
				pass_through[v] = 1;
				dist[v] = d + w;
				pq.emplace(dist[v], v);
			}
		}
	}
	for (int i = 2; i <= n; i++) {
		if (train_route[i]) {
			if (dist[i] == train_route[i])
				res += (pass_through[i] > 1);
			else if (dist[i] < train_route[i]) res++;
		}
	}
	cout << res;
	return 0;
}