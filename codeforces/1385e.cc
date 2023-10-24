#include <bits/stdc++.h>
#define int long long
using namespace std;
int32_t main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int t, n, m, op, x, y;
	cin >> t;
	while (t--) {
		cin >> n >> m;
		vector<vector<int>> d(n + 1), ud(n + 1);
		vector<int> in_degree(n + 1), topo;
		vector<bool> vis(n + 1, false);
		while (m--) {
			cin >> op >> x >> y;
			if (op == 0)
				ud[x].emplace_back(y), ud[y].emplace_back(x);
			else d[x].emplace_back(y), in_degree[y]++;
		}
		queue<int> q;
		for (int i = 1; i <= n; i++) {
			if (in_degree[i] == 0) q.emplace(i);
		}
		while (!q.empty()) {
			int u = q.front();
			topo.emplace_back(u);
			q.pop();
			for (int v : d[u]) {
				in_degree[v]--;
				if (in_degree[v] == 0) q.emplace(v);
			}
		}
		for (int i = 1; i <= n; i++) {
			if (in_degree[i] > 0) {
				cout << "NO\n";
				goto end;
			}
		}
		cout << "YES\n";
		for (auto x : topo) {
			for (auto y : d[x]) cout << x << " " << y << "\n";
			for (auto y : ud[x])
				if (!vis[y]) cout << x << " " << y << "\n";
			vis[x] = true;
		}
	end:;
	}
	return 0;
}
