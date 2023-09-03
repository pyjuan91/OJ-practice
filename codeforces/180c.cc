#include <bits/stdc++.h>
using namespace std;
bool a[100005];
int n, dp[100005][2];
int chaewon(int id, bool changed) {
	if (id == n) return 0;
	if (dp[id][changed] != -1) return dp[id][changed];
	int res = 0;
	if (changed == false) {
		if (a[id]) res = chaewon(id + 1, false);
		else
			res = min(1 + chaewon(id + 1, false), chaewon(id + 1, true));
	}
	else {
		if (a[id]) res = 1 + chaewon(id + 1, true);
		else res = chaewon(id + 1, true);
	}
	return dp[id][changed] = res;
}
int32_t main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	string s;
	cin >> s;
	n = s.length();
	for (int i = 0; i <= s.length(); i++)
		dp[i][0] = dp[i][1] = -1;
	for (int i = 0; i < n; i++) {
		if (s[i] >= 'A' && s[i] <= 'Z') a[i] = true;
		else a[i] = false;
	}
	cout << chaewon(0, false) << '\n';
	return 0;
}
