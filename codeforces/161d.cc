#include <bits/stdc++.h>
#define int long long
using namespace std;
int32_t main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n, k, a, b, res = 0;
	cin >> n >> k;
	vector<vector<int>> g(n + 1);
	for (int i = 1; i < n; i++) {
		cin >> a >> b;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));
	function<void(int, int)> chaewon = [&](int cur, int prev) {
		dp[cur][0] = 1;
		for (int nxt : g[cur]) {
			if (nxt == prev) continue;
			chaewon(nxt, cur);
			for (int dis = 0; dis < k; dis++)
				res += dp[cur][dis] * dp[nxt][k - dis - 1];
			for (int dis = 1; dis <= k; dis++)
				dp[cur][dis] += dp[nxt][dis - 1];
		}
	};
    chaewon(1, 0);
	cout << res;
	return 0;
}
