#include <bits/stdc++.h>
#define int long long
const int mod = 998244353;
int dp[3005][3005][2];
using namespace std;
int chaewon(size_t n, string& s, size_t cur, int left) {
	if (cur == n) return left == 0;
	if (s[cur] == ')') {
		if (left == 0) return 0;
		if (dp[cur][left][1] == -1)
			dp[cur][left][1] = chaewon(n, s, cur + 1, left - 1);
		return dp[cur][left][1];
	}
	if (s[cur] == '(') {
		if (dp[cur][left][0] == -1)
			dp[cur][left][0] = chaewon(n, s, cur + 1, left + 1);
		return dp[cur][left][0];
	}
	if (dp[cur][left][0] == -1)
		dp[cur][left][0] = chaewon(n, s, cur + 1, left + 1);
	if (dp[cur][left][1] == -1) {
		if (left)
			dp[cur][left][1] = chaewon(n, s, cur + 1, left - 1);
		else dp[cur][left][1] = 0;
	}
	return (dp[cur][left][0] + dp[cur][left][1]) % mod;
}
int32_t main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	string s;
	cin >> s;
	size_t n = s.size();
	bool ques = false;
	for (size_t i = 0; i < n; i++)
		if (s[i] == '?') ques = true;
	if (n % 2 != 0 || !ques) {
		cout << 0 << '\n';
		return 0;
	}
	memset(dp, -1, sizeof(dp));
	cout << chaewon(n, s, 0, 0) << '\n';
	return 0;
}
