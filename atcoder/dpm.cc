#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
long long dp[105][100005];
int main() {
#define int long long
	ios_base::sync_with_stdio(false);
	cin.tie();
	int n, k, sum = 0;
	cin >> n >> k;
	vector<int> a(n + 1, 0), prefix(k + 1, 0);
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		sum += a[i];
	}
	if (sum < k) {
		cout << 0 << "\n";
		return 0;
	}
	prefix[0] = 1;
	for (int i = 0; i <= k; i++) {
		if (i <= a[1]) dp[1][i] = 1;
		if (i) prefix[i] = prefix[i - 1] + dp[1][i];
	}
	for (int i = 2; i <= n; i++) {
		for (int j = 0; j <= k; j++) {
			if (j > a[i])
				dp[i][j] = (prefix[j] - prefix[j - a[i] - 1] + mod) % mod;
			else dp[i][j] = prefix[j];
		}
		for (int j = 1; j <= k; j++)
			prefix[j] = (prefix[j - 1] + dp[i][j]) % mod;
	}
	cout << dp[n][k];
	return 0;
}