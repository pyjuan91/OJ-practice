#include <bits/stdc++.h>
#define int long long
using namespace std;
int chaewon(vector<int>& num, int l, int r, vector<vector<int>>& dp, int ts) {
	if (l > r) return 0;
	if (l == r) return dp[l][l] = num[l];
	if (dp[l][r] != INT64_MIN) return dp[l][r];
	return dp[l][r] = max(
			 ts - chaewon(num, l + 1, r, dp, ts - num[l]),
			 ts - chaewon(num, l, r - 1, dp, ts - num[r]));
}
int32_t main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n, ts = 0;
	cin >> n;
	vector<int> num(n);
	vector<vector<int>> dp(n + 1, vector<int>(n + 1, INT64_MIN));
	for (auto& x : num) cin >> x, ts += x;
	cout << chaewon(num, 0, n - 1, dp, ts);
	return 0;
}