#include <bits/stdc++.h>
#define int long long
using namespace std;
int32_t main() {
	ifstream cin("div7.in");
	ofstream cout("div7.out");

	cin.tie(nullptr)->sync_with_stdio(false);
	int n;
	cin >> n;
	vector<int> a(n);
	for (int &x : a) cin >> x;
	vector<vector<int>> dp(7, vector<int>(n, 0));
	for (int i = 0; i < n; i++) {
		dp[a[i] % 7][i] = 1;
		for (int j = 0; j < 7; j++) {
			if (i && dp[j][i - 1])
				dp[(j + a[i]) % 7][i] = dp[j][i - 1] + 1;
		}
	}
	cout << *max_element(dp[0].begin(), dp[0].end()) << endl;
	return 0;
}
