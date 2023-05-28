#include <bits/stdc++.h>
using namespace std;
int main() {
	cin.tie()->sync_with_stdio(false);
	int n, x;
	cin >> n;
	vector<int> pos(n + 1), c(n + 1), dp;
	for (int i = 1; i <= n; i++) cin >> x, pos[x] = i;
	for (int i = 1; i <= n; i++) cin >> x, c[i] = pos[x];
	for (int i = 1; i <= n; i++) {
		int pos = lower_bound(dp.begin(), dp.end(), c[i]) - dp.begin();
		if (pos == dp.size()) dp.emplace_back(c[i]);
		else dp[pos] = c[i];
	}
	cout << dp.size();
	return 0;
}