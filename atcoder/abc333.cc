#include <bits/stdc++.h>
using namespace std;
int32_t main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n, a, b;
	cin >> n;
	vector<vector<int>> g(n + 1);
	for (int i = 1; i < n; i++) {
		cin >> a >> b;
		g[a].emplace_back(b);
		g[b].emplace_back(a);
	}
	function<int(int, int)> get_rank = [&](int u, int p) {
		int res = 1;
		for (int v : g[u]) {
			if (v != p) res += get_rank(v, u);
		}
		return res;
	};
	int su = 0, ma = INT32_MIN;
	for (auto x : g[1]) {
		int r = get_rank(x, 1);
		su += r, ma = max(ma, r);
	}
	cout << su - ma + 1 << '\n';
	return 0;
}
