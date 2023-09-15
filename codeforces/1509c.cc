#include <bits/stdc++.h>
using namespace std;
#define int long long
int32_t main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n;
	cin >> n;
	vector<int> a(n);
	for (auto &x : a) cin >> x;
	sort(a.begin(), a.end());
	vector<vector<int>> dp(n, vector<int>(n, INT64_MAX));
	function<int(int, int)> chaewon = [&](int l, int r) {
		if (l == r) return 0LL;
		if (dp[l][r] != INT64_MAX) return dp[l][r];
		return dp[l][r] = a[r] - a[l] + min(chaewon(l + 1, r), chaewon(l, r - 1));
	};
	cout << chaewon(0, n - 1) << '\n';
	return 0;
}