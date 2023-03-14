#include <bits/stdc++.h>
using namespace std;
int chaewon(vector<int>& dp, vector<int>& a, int k) {
	if (dp[k] >= 0) return dp[k];
	for (auto i : a) {
		if (i == k) return dp[k] = 1;
		if (i < k && chaewon(dp, a, k - i) == 0)
			return dp[k] = 1;
	}
	return dp[k] = 0;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie();
	int n, k;
	cin >> n >> k;
	vector<int> a(n), dp(k + 1, -1);
	for (int i = 0; i < n; i++) cin >> a[i];
	if (chaewon(dp, a, k) == 1) cout << "First";
	else cout << "Second";
	return 0;
}