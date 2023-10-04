#include <bits/stdc++.h>
#define int long long
using namespace std;
int32_t main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int t, n, x;
	cin >> t;
	while (t--) {
		cin >> n;
		vector<vector<int>> g(n + 1);
		vector<int> in_degree(n + 1, 0), b(n + 1), res;
		for (int i = 1; i <= n; ++i) {
			cin >> x;
			g[i].push_back(x);
			++in_degree[x];
		}
		for (int i = 1; i <= n; i++) cin >> b[i];
		// conduct topo sort
		queue<int> q;
		for (int i = 1; i <= n; i++) {
			if (in_degree[i] == 0) q.push(i);
		}
		while (!q.empty()) {
			int u = q.front();
			q.pop();
			res.push_back(u);
			for (auto v : g[u]) {
				if (--in_degree[v] == 0) q.push(v);
			}
		}
		for (int i = 1; i <= n; i++) {
			if (in_degree[i] == 0) continue;
			vector<int> cur_loop;
			pair<int, int> start_point = {i, INT32_MAX};
			function<void(int)> dfs = [&](int u) {
				in_degree[u] = 0;
				cur_loop.push_back(u);
				if (b[u] < start_point.second) {
					start_point = {u, b[u]};
				}
				for (auto nxt : g[u]) {
					if (in_degree[nxt] == 0) continue;
					dfs(nxt);
				}
			};
			dfs(i);
			int start = 0;
			for (int j = 0; j < cur_loop.size(); j++)
				if (cur_loop[j] == start_point.first) start = j;
			start = start + 1 % cur_loop.size();
			for (int j = 0; j < cur_loop.size(); j++) {
				res.push_back(cur_loop[(start + j) % cur_loop.size()]);
			}
		}
		for (auto x : res) cout << x << " ";
		cout << endl;
	}
	return 0;
}
