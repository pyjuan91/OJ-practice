#include <bits/stdc++.h>
using namespace std;
int main() {
	cin.tie()->sync_with_stdio(false);
	int n, x;
	cin >> n >> x;
	vector<int> a(n), b(n);
	for (auto& x : a) cin >> x;
	for (auto& x : b) cin >> x;
	vector<int> dp(x + 1, -1);
	dp[0] = 0;
	for (int i = 1; i <= n; i++)
		for (int j = x; j >= 1; j--)
			if (j - a[i - 1] >= 0 && dp[j - a[i - 1]] >= 0)
				dp[j] = max(dp[j], dp[j - a[i - 1]] + b[i - 1]);
	int res = 0;
	for (auto x : dp) res = max(res, x);
	cout << res;
	return 0;
}