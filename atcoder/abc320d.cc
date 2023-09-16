#include <bits/stdc++.h>
#define int long long
using namespace std;
struct Edge {
		int u, x, y;
		Edge(int u, int x, int y)
		  : u(u)
		  , x(x)
		  , y(y) {}
		Edge() {}
};

int32_t main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n, m, a, b, x, y;
	cin >> n >> m;
	vector<vector<Edge>> edges(n + 1);
	for (int i = 1; i <= m; i++) {
		cin >> a >> b >> x >> y;
		edges[a].push_back(Edge(b, x, y));
		edges[b].push_back(Edge(a, -x, -y));
	}
	// for (int i = 1; i <= n; i++) {
	// 	for (auto &[v, dx, dy] : edges[i]) {
	// 		cout << i << " " << v << " " << dx << " " << dy << '\n';
	// 	}
	// }
	queue<int> q;
	q.push(1);
	vector<pair<int, int>> pos(n + 1);
	vector<bool> deter(n + 1, false);
	deter[1] = true;
	pos[1] = make_pair(0, 0);
	while (!q.empty()) {
		int u = q.front();
		pair<int, int> p = pos[u];
		q.pop();
		for (auto &[v, dx, dy] : edges[u]) {
			if (!deter[v]) {
				deter[v] = true;
				pos[v] = make_pair(p.first + dx, p.second + dy);
				q.push(v);
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		auto [x, y] = pos[i];
		if (deter[i]) cout << x << ' ' << y << '\n';
		else cout << "undecidable" << '\n';
	}
	return 0;
}
