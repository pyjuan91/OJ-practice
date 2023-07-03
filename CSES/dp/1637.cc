#include <bits/stdc++.h>
#define int long long
using namespace std;
int chaewon(vector<int>& dp, int n) {
	if (dp[n] != INT64_MAX) return dp[n];
	int nn = n, res = INT64_MAX;
	while (nn) {
		if (nn % 10)
			res = min(res, chaewon(dp, n - nn % 10) + 1);
		nn /= 10;
	}
	return dp[n] = res;
}
int32_t main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n;
	cin >> n;
	vector<int> dp(n + 5, INT64_MAX);
	dp[0] = 0;
	cout << chaewon(dp, n);
	return 0;
}