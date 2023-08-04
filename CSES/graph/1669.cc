#include <bits/stdc++.h>
using namespace std;
bool dfs(int cur, int prev, vector<int>& par, vector<vector<int>>& adj, vector<int>& dis) {
	for (auto nxt : adj[cur]) {
		if (nxt != prev) {
			if (dis[nxt] == -1) {
				dis[nxt] = dis[cur] + 1;
				par[nxt] = cur;
				if (dfs(nxt, cur, par, adj, dis)) return true;
			}
			else {
				if (dis[cur] - dis[nxt] >= 2) {
					cout << dis[cur] - dis[nxt] + 2 << '\n';
					cout << nxt << ' ';
					while (cur != nxt) {
						cout << cur << ' ';
						cur = par[cur];
					}
					cout << nxt << '\n';
					return true;
				}
			}
		}
	}
	return false;
}
int32_t main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n, m, a, b;
	cin >> n >> m;
	vector<vector<int>> adj(n + 1);
	for (int i = 0; i < m; ++i) {
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	vector<int> par(n + 1, -1), dis(n + 1, -1);
	for (int i = 1; i <= n; ++i) {
		if (dis[i] == -1) {
			dis[i] = 0;
			if (dfs(i, -1, par, adj, dis)) return 0;
		}
	}
	cout << "IMPOSSIBLE\n";
	return 0;
}
