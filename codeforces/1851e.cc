#include <bits/stdc++.h>
#define int long long
using namespace std;
int t, n, k, a[200005], x, m;
bool vis[200005];
vector<int> g[200005];
int chaewon(int u) {
	if (vis[u]) return a[u];
	vis[u] = true;
	if (g[u].empty()) return a[u];
	int alter = 0;
	for (auto v : g[u]) alter += chaewon(v);
	return a[u] = min(a[u], alter);
}
int32_t main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	cin >> t;
	while (t--) {
		cin >> n >> k;
		for (int i = 1; i <= n; i++)
			cin >> a[i], g[i].clear(), vis[i] = false;
		for (int i = 0; i < k; i++) cin >> x, a[x] = 0;
		for (int i = 1; i <= n; i++) {
			cin >> m;
			while (m--) {
				cin >> x;
				g[i].push_back(x);
			}
		}
		for (int i = 1; i <= n; i++) {
			if (!vis[i]) chaewon(i);
			cout << a[i] << " ";
		}
		cout << '\n';
	}
	return 0;
}