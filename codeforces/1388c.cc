#include <bits/stdc++.h>
#define int long long
using namespace std;
int32_t main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int t, n, m, a, b;
	cin >> t;
	while (t--) {
		cin >> n >> m;
		vector<int> citizens(n), happiness(n), happy(n, 0), sad(n, 0);
		vector<vector<int>> g(n);
		for (int i = 0; i < n; i++) cin >> citizens[i];
		for (int i = 0; i < n; i++) cin >> happiness[i];
		for (int i = 1; i < n; i++) {
			cin >> a >> b;
			a--, b--;
			g[a].push_back(b);
			g[b].push_back(a);
		}
		function<bool(int, int)> dfs = [&](int u, int p) {
			int happy_people = 0, sad_people = 0;
			for (auto nxt : g[u]) {
				if (nxt == p) continue;
				if (!dfs(nxt, u)) return false;
				happy_people += happy[nxt];
				sad_people += sad[nxt];
			}
			int total_people = happy_people + sad_people + citizens[u];
			happy[u] = (total_people + happiness[u]) / 2;
			sad[u] = total_people - happy[u];
			return (happy[u] >= happy_people)
				&& (((total_people + happiness[u]) % 2) == 0)
				&& (sad[u] >= 0 && happy[u] >= 0);
		};
		cout << (dfs(0, -1) ? "YES\n" : "NO\n");
	}
	return 0;
}
