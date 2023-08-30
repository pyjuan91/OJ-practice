#include <bits/stdc++.h>
using namespace std;
int32_t main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int t, n, a, b;
	cin >> t;
	while (t--) {
		cin >> n;
		vector<vector<int>> g(n + 1);
		bool ok = true;
		for (int i = 0; i < n; i++) {
			cin >> a >> b;
			if (a == b) ok = false;
			g[a].push_back(b);
			g[b].push_back(a);
		}
		for (int i = 1; i <= n; i++) {
			if (g[i].size() != 2) ok = false;
		}
		if (!ok) {
			cout << "NO\n";
			continue;
		}
		vector<int> color(n + 1, -1);
		function<void(int)> dfs = [&](int cur) {
			int adj_color = 1 - color[cur];
			for (auto child : g[cur]) {
				if (color[child] == -1) {
					color[child] = adj_color;
					dfs(child);
				}
				else if (color[child] != adj_color) {
					ok = false;
				}
			}
		};
		for (int i = 1; i <= n; i++) {
			if (color[i] == -1) {
				color[i] = 0;
				dfs(i);
			}
		}
        if (!ok) {
            cout << "NO\n";
            continue;
        }
        cout << "YES\n";
	}
	return 0;
}
