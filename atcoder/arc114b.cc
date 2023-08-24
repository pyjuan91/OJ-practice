#include <bits/stdc++.h>
#define int long long
const int mod = 998244353;
using namespace std;
bool dfs(int cur, auto& vis, auto& g, auto& cyc) {
	if (cyc[cur]) return true;
	if (vis[cur]) return false;
	cyc[cur] = true;
	vis[cur] = true;
	return dfs(g[cur], vis, g, cyc);
}
int32_t main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n, cycle_cnt = 0;
	cin >> n;
	vector<int> g(n + 1);
	for (int i = 1; i <= n; i++) cin >> g[i];
	vector<bool> vis(n + 1, false);
	for (int i = 1; i <= n; i++) {
		if (vis[i]) continue;
		vector<bool> cyc(n + 1, false);
		if (dfs(i, vis, g, cyc)) cycle_cnt++;
	}
	auto fast_power = [&](int base, int exp) {
		int res = 1;
		while (exp) {
			if (exp & 1) res = res * base % mod;
			base = base * base % mod;
			exp >>= 1;
		}
		return res;
	};
	cout << fast_power(2, cycle_cnt) - 1ll;
	return 0;
}
