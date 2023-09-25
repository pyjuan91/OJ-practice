#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;
int n, m, cat[maxn], a, b, res = 0, cons[maxn] = {};
vector<int> g[maxn];
int32_t main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> cat[i];
	for (int i = 1; i < n; i++) {
		cin >> a >> b;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	function<void(int, int)> dfs = [&](int cur, int prev) {
		if (cat[prev] && cat[cur]) cat[cur] += cat[prev];
		for (auto &i : g[cur])
			if (i != prev) dfs(i, cur);
	};
	dfs(1, 0);
	function<void(int, int)> dfs2 = [&](int cur, int prev) {
		cons[cur] = max(cat[cur], cons[prev]);
		for (auto &i : g[cur])
			if (i != prev) dfs2(i, cur);
	};
	dfs2(1, 0);
	function<void(int, int)> dfs3 = [&](int cur, int prev) {
		if (g[cur].size() == 1 && g[cur][0] == prev) {
			if (cons[cur] <= m) res++;
			return;
		}
		for (auto &i : g[cur])
			if (i != prev) dfs3(i, cur);
	};
	dfs3(1, 0);
	cout << res << '\n';
	return 0;
}
