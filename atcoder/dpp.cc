#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll mod = 1e9 + 7;
void chaewon(vector<vector<int>>& edges, vector<vector<ll>>& dp, int cur, int prev) {
	dp[cur][0] = dp[cur][1] = 1LL;
	for (auto e : edges[cur]) {
		if (e == prev) continue;
		chaewon(edges, dp, e, cur);
		dp[cur][0] = (dp[cur][0] * dp[e][1]) % mod;
		dp[cur][1] = (dp[cur][1] * ((dp[e][0] + dp[e][1]) % mod)) % mod;
	}
}
int main() {
	cin.tie()->sync_with_stdio(false);
	int n, a, b, res = 0;
	cin >> n;
	vector<vector<int>> edges(n + 1);
	for (int i = 1; i < n; i++) {
		cin >> a >> b;
		edges[a].emplace_back(b);
		edges[b].emplace_back(a);
	}
	vector<vector<ll>> dp(n + 1, vector<ll>(2, 0LL));
	chaewon(edges, dp, 1, 0);
	cout << (dp[1][0] + dp[1][1]) % mod;
	return 0;
}