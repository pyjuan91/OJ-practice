#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	const int mod = 1e9 + 7;
	int t, n, m, a, b;
	cin >> t;
	while (t--) {
		cin >> n;
		vector<vector<int>> g(n + 1);
		for (int i = 1; i < n; i++) {
			cin >> a >> b;
			g[a].push_back(b);
			g[b].push_back(a);
		}
		vector<int> child_cnt(n + 1, 0), sz;
		int res = 0;
		function<void(int, int)> dfs = [&](int u, int p) {
			for (auto nxt : g[u]) {
				if (nxt == p) continue;
				dfs(nxt, u);
				child_cnt[u] += child_cnt[nxt] + 1;
				sz.emplace_back(
				  (child_cnt[nxt] + 1) * (n - child_cnt[nxt] - 1));
			}
		};
		dfs(1, 0);
		sort(sz.rbegin(), sz.rend());
		cin >> m;
		vector<int> p(m);
		for (int i = 0; i < m; i++) cin >> p[i];
		sort(p.begin(), p.end());
		while (p.size() > n - 1) {
			int drop = p.back();
			p.pop_back();
			p.back() = (p.back() * drop) % mod;
		}
		reverse(p.begin(), p.end());
		while (p.size() < sz.size())
			res = (res + sz.back()) % mod, sz.pop_back();
		for (int i = 0; i < p.size(); i++)
			res = (res + p[i] * sz[i]) % mod;
		cout << res << '\n';
	}
	return 0;
}