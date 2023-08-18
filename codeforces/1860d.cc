#include <bits/stdc++.h>
using namespace std;
int dp[101][101][5001];
string s;
int cnt_0, cnt_1;
int chaewon(int pre_0, int pre_1, int balance) {
	if (pre_0 > cnt_0 || pre_1 > cnt_1) return INT32_MAX - 1;
	if (pre_0 == cnt_0 && pre_1 == cnt_1 && balance == 2500)
		return 0;
	if (dp[pre_0][pre_1][balance] != -1)
		return dp[pre_0][pre_1][balance];
	if (s[pre_0 + pre_1] == '0')
		return dp[pre_0][pre_1][balance] = min(
				 chaewon(pre_0 + 1, pre_1, balance - pre_1),
				 chaewon(pre_0, pre_1 + 1, balance + pre_0) + 1);
	return dp[pre_0][pre_1][balance] = min(
			 chaewon(pre_0, pre_1 + 1, balance + pre_0),
			 chaewon(pre_0 + 1, pre_1, balance - pre_1) + 1);
}
int32_t main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	memset(dp, -1, sizeof(dp));
	cin >> s;
	cnt_0 = cnt_1 = 0;
	for (auto x : s) {
		if (x == '0') cnt_0++;
		else cnt_1++;
	}
	cout << chaewon(0, 0, 2500) / 2 << '\n';
	return 0;
}
