#include <bits/stdc++.h>
#define int long long
using namespace std;
const int mod = 1e9 + 7;
bool is_palin(int n) {
	if (n < 10) return true;
	vector<int> v;
	while (n) {
		v.push_back(n % 10);
		n /= 10;
	}
	for (int i = 0; i < (int) v.size() / 2; i++) {
		if (v[i] != v[v.size() - i - 1]) return false;
	}
	return true;
}
vector<int> palins;
int dp[40001][500];
int32_t main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	for (int i = 1; i <= 4e4; i++) {
		if (is_palin(i)) palins.push_back(i);
	}
	for (int i = 0; i < 498; i++) dp[1][i] = dp[0][i] = 1;
	for (int i = 1; i <= 4e4; i++) {
		dp[i][0] = 1;
		for (int j = 1; j < 498; j++) {
			dp[i][j] = dp[i][j - 1];
			if (i - palins[j] >= 0) {
				dp[i][j] += dp[i - palins[j]][j];
				dp[i][j] %= mod;
			}
		}
	}
	int t, n;
	cin >> t;
	while (t--) {
		cin >> n;
		cout << dp[n][497] << '\n';
	}
	return 0;
}
