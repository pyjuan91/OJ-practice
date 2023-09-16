#include <bits/stdc++.h>
#define int long long
using namespace std;
const int mod = 1e9 + 7;
int prefix[100005] = {}, dp[100005];
void init(int k) {
	for (int i = 0; i < k; i++) dp[i] = 1;
	for (int i = k; i <= 100000; i++) {
		dp[i] = dp[i - 1];
		dp[i] += dp[i - k];
		dp[i] %= mod;
	}
	for (int i = 1; i <= 100000; i++) {
		prefix[i] = prefix[i - 1] + dp[i];
		prefix[i] %= mod;
	}
}
int32_t main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int t, k, a, b;
	cin >> t >> k;
	init(k);
	while (t--) {
		cin >> a >> b;
		cout << (prefix[b] + mod - prefix[a - 1]) % mod << "\n";
	}
	return 0;
}
