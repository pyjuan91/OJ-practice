#include <bits/stdc++.h>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie();
#define int long long
	int n, k;
	cin >> n >> k;
	vector<int> a(n + 1), dp(n + 1, 2e15);
	for (int i = 1; i <= n; i++) cin >> a[i];
	dp[1] = 0;
	for (int i = 1; i < n; i++) {
		for (int j = 1; j <= k && i + j <= n; j++) {
			dp[i + j] = min(
			  dp[i + j], dp[i] + abs(a[i + j] - a[i]));
		}
	}
	cout << dp[n] << "\n";
	return 0;
}