#include <bits/stdc++.h>
#define int long long
using namespace std;

const int maxn = 2e5 + 5;
using pii = pair<int, int>;
#define fi first
#define se second
#define pb push_back
#define mp make_pair
vector<pii> g[maxn];
bool vis[maxn];
unordered_map<int, int> pos;

int32_t main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int t, n, m, a, b, c;
	cin >> t;
	while (t--) {
		cin >> n >> m;
		pos.clear();
		for (int i = 1; i <= n; i++)
			g[i].clear(), vis[i] = false;
		while (m--) {
			cin >> a >> b >> c;
			g[a].pb(mp(b, c));
			g[b].pb(mp(a, -c));
		}
		bool ok = true;
		for (int i = 1; i <= n; i++) {
			if (vis[i]) continue;
			queue<int> q;
			q.push(i);
			vis[i] = true;
			pos[i] = 0;
			while (!q.empty()) {
				auto u = q.front();
				q.pop();
				for (auto [v, d] : g[u]) {
					if (vis[v]) {
						if (pos[v] != pos[u] + d) {
							ok = false;
							break;
						}
					}
					else {
						vis[v] = true;
						pos[v] = pos[u] + d;
						q.push(v);
					}
				}
			}
		}
		if (ok) cout << "YES\n";
		else cout << "NO\n";
	}
	return 0;
}
