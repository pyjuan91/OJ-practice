#include <bits/stdc++.h>
#define int long long
using namespace std;
int cnt[100001] = {}, dp[100001] = {};
int32_t main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n, x;
	cin >> n;
	while (n--) cin >> x, cnt[x]++;
	dp[1] = cnt[1];
	for (int i = 2; i < 100001; i++)
		dp[i] = max(dp[i - 1], cnt[i] * i + dp[i - 2]);
    cout << dp[100000] << '\n';
	return 0;
}