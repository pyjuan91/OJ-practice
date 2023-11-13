#include <bits/stdc++.h>
#define int long long
using namespace std;
const int mod = 1e9 + 7;
int n, m, a, b;
vector<int> g[100005], dp(100005, -1);
void chaewon(int x) {
	if (x == n) {
		dp[x] = 1;
		return;
	}
	if (dp[x] != -1) return;
	dp[x] = 0;
	for (auto i : g[x]) {
		chaewon(i);
		dp[x] = (dp[x] + dp[i]) % mod;
	}
}
int32_t main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	cin >> n >> m;
	while (m--) {
		cin >> a >> b;
		g[a].push_back(b);
	}
	chaewon(1);
	cout << dp[1] << '\n';
	return 0;
}
