#include <bits/stdc++.h>
#define int long long
const int mod = 1e9 + 7;
const int ma = 1e6 + 5;
using namespace std;
int dp[ma];
int chaewon(int n) {
	if (n < 0) return 0;
	if (dp[n]) return dp[n];
	int res = 0;
	for (int i = 1; i <= 6; i++) {
		res += chaewon(n - i);
		res %= mod;
	}
	return dp[n] = res;
}
int32_t main() {
	cin.tie()->sync_with_stdio(false);
	memset(dp, 0, sizeof(dp));
	dp[0] = dp[1] = 1;
	int n;
	cin >> n;
	cout << chaewon(n) << "\n";
	return 0;
}