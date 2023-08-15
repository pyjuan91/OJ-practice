#include <bits/stdc++.h>
using namespace std;
vector<pair<int, int>> g[5005];
int ans[5005];
int32_t main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int t, n, m, a, b;
	cin >> t;
	while (t--) {
		cin >> n >> m;
		for (int i = 1; i <= n; i++) g[i].clear();
		for (int i = 0; i < m; i++) {
			ans[i] = 0;
			cin >> a >> b;
			g[a].push_back({b, i});
			g[b].push_back({a, i});
		}
		int consi = 0;
		for (int i = 1; i <= n; i++) {
			if ((int) g[i].size() != n - 1) {
				consi = i;
				break;
			}
		}
		if (consi == 0) {
			cout << "3\n";
			for (auto& [v, id] : g[1]) ans[id] = 1;
			ans[g[1][0].second] = 2;
			for (int i = 0; i < m; i++)
				if (ans[i]) cout << ans[i] << " ";
				else cout << 3 << " ";
			cout << "\n";
		}
		else {
			cout << "2\n";
			for (auto& [v, id] : g[consi]) ans[id] = 1;
			for (int i = 0; i < m; i++)
				if (ans[i]) cout << ans[i] << " ";
				else cout << 2 << " ";
			cout << "\n";
		}
	}
	return 0;
}
