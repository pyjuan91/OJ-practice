#include <bits/stdc++.h>
#define int long long
using namespace std;
const int maxn = 2e5 + 5;
int a[maxn];
bool dp[maxn];
bool chaewon(int n) {
	memset(dp, false, sizeof(dp));
	dp[0] = true;
	for (int i = 1; i <= n; i++) {
		if (i - a[i] >= 1 && dp[i - a[i] - 1]) dp[i] = true;
		if (i + a[i] <= n && dp[i - 1]) dp[i + a[i]] = true;
	}
	return dp[n];
}
int32_t main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int t, n;
	cin >> t;
	while (t--) {
		cin >> n;
		for (int i = 1; i <= n; i++) cin >> a[i];
		if (chaewon(n)) cout << "YES\n";
		else cout << "NO\n";
	}
	return 0;
}
