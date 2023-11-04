#include <bits/stdc++.h>
using namespace std;
int main() {
	cin.tie(nullptr)->sync_with_stdio(false);

	int n, m, s, a, b, res = 0;
	cin >> n >> m >> s;

	vector<vector<int>> g(n + 1);
	vector<bool> good(n + 1, false);

	while (m--) {
		cin >> a >> b;
		g[a].emplace_back(b);
	}

	function<void(int)> dfs_good = [&](int u) {
		good[u] = true;
		for (auto v : g[u])
			if (!good[v]) dfs_good(v);
	};
	dfs_good(s);

	vector<pair<int, int>> bad_components;
	for (int i = 1; i <= n; i++) {
		if (!good[i]) {
			vector<bool> bad(n + 1, false);
			function<int(int)> dfs_bad = [&](int u) {
				bad[u] = true;
				int res = 1;
				for (auto v : g[u]) {
					if (!good[v] && !bad[v]) res += dfs_bad(v);
				}
				return res;
			};
			bad_components.emplace_back(dfs_bad(i), i);
		}
	}

	sort(bad_components.begin(), bad_components.end());

	while (!bad_components.empty()) {
		int node = bad_components.back().second;
		bad_components.pop_back();
		if (!good[node]) dfs_good(node), res++;
	}

	cout << res << '\n';

	return 0;
}