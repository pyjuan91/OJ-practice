#include <bits/stdc++.h>
using namespace std;
int32_t main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n, m, q, a, b, c;
	cin >> n >> m;
	vector<vector<pair<int, int>>> g(n + 1);
	while (m--) {
		cin >> a >> b >> c;
		g[a].emplace_back(b, c);
		g[b].emplace_back(a, c);
	}
	cin >> q;
	while (q--) {
		cin >> a >> b;
		function<bool(int, int, int, vector<bool>&)> chaewon
		  = [&](int cur, int end, int color, auto& vist) {
			if (cur == end) return true;
			for (auto [nxt, nxt_color] : g[cur]) {
				if (nxt_color == color && !vist[nxt]) {
					vist[nxt] = true;
					if (chaewon(nxt, end, color, vist))
						return true;
					vist[nxt] = false;
				}
			}
			return false;
		};
		int res = 0;
		vector<bool> used_color(n + 1, false);
		for (auto [nxt, nxt_color] : g[a]) {
			if (used_color[nxt_color]) continue;
			used_color[nxt_color] = true;
			vector<bool> vist(n + 1, false);
			if (chaewon(nxt, b, nxt_color, vist)) res++;
		}
		cout << res << "\n";
	}
	return 0;
}
