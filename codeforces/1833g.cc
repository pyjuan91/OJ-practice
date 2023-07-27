#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
#define mp make_pair
#define pb emplace_back

const int maxn = 2e5 + 5;
vector<pii> g[maxn];
vector<int> res;
int t, n, dp[maxn], u, v;
bool sol;

void chaewon(int cur, int prev) {
	dp[cur] = 1;
	for (auto [child, id] : g[cur]) {
		if (child != prev) {
			chaewon(child, cur);
			if (dp[child] == 3) res.pb(id);
			else dp[cur] += dp[child];
			if (dp[cur] > 3) sol = false; 
		}
	}
}

int32_t main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	cin >> t;
	while (t--) {
		cin >> n;
		res.clear();
		sol = true;
		for (int i = 1; i <= n; i++) g[i].clear(), dp[i] = 0;
		for (int i = 1; i < n; i++) {
			cin >> u >> v;
			g[u].pb(mp(v, i));
			g[v].pb(mp(u, i));
		}
		chaewon(1, 0);
		if (n % 3 != 0 || !sol) cout << "-1\n";
		else {
			cout << res.size() << "\n";
			for (auto x : res) cout << x << " ";
			cout << "\n";
		}
	}
	return 0;
}