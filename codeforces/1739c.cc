#include <bits/stdc++.h>
#define int long long
using namespace std;
const int mod = 998244353;
int fast_power(int base, int power) {
	int res = 1;
	while (power) {
		if (power & 1) res = res * base % mod;
		power >>= 1;
		base = base * base % mod;
	}
	return res;
}
int find_inv(int a) { return fast_power(a, mod - 2); }
int factorial(int a) {
	int res = 1;
	for (int i = 2; i <= a; i++) res = res * i % mod;
	return res;
}
int Combination(int n, int k) {
	int numerator = factorial(n);
	int denominator = factorial(n - k) * factorial(k) % mod;
	return numerator * find_inv(denominator) % mod;
}
void init(vector<vector<int>>& dp) {
	dp[2] = {1, 0, 1};
	for (int i = 4; i <= 60; i += 2) {
		dp[i][0] = dp[i - 2][1] + Combination(i - 1, i / 2);
        dp[i][0] %= mod;
		dp[i][1] = dp[i - 2][0] + Combination(i - 2, i / 2);
        dp[i][1] %= mod;
		dp[i][2] = 1;
	}
}
int32_t main() {
	cin.tie(nullptr)->sync_with_stdio(false);
    // cout << fast_power(6, 3) << endl;
	int t, n;
	vector<vector<int>> dp(61, vector<int>(3, 0));
	init(dp);
	cin >> t;
	while (t--) {
		cin >> n;
		cout << dp[n][0] << " " << dp[n][1] << " " << dp[n][2] << "\n";
	}
	return 0;
}