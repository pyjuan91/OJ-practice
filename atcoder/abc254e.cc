#include <bits/stdc++.h>
#define int long long
using namespace std;
int32_t main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n, m, Q, a, b;
	cin >> n >> m;
	vector<vector<int>> g(n + 1);
	while (m--) {
		cin >> a >> b;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	cin >> Q;
	queue<int> q;
	vector<int> dist(n + 1, -1), res;
	while (Q--) {
		cin >> a >> b;
		q.push(a);
		dist[a] = 0;
		while (!q.empty()) {
			int u = q.front();
			q.pop();
			res.push_back(u);
			if (dist[u] == b) continue;
			for (auto v : g[u]) {
				if (dist[v] == -1) {
					dist[v] = dist[u] + 1;
					q.push(v);
				}
			}
		}
		int su = 0;
		for (auto x : res) su += x, dist[x] = -1;
        res.clear();
		cout << su << '\n';
	}
	return 0;
}
