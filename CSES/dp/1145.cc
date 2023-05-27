#include <bits/stdc++.h>
using namespace std;
int main() {
	cin.tie()->sync_with_stdio(false);
	int n;
	cin >> n;
	vector<int> a(n), dp;
	for (auto &x : a) cin >> x;
	dp.emplace_back(a[0]);
	for (int i = 1; i < n; i++) {
		auto pos = lower_bound(dp.begin(), dp.end(), a[i]) - dp.begin();
		if (pos == dp.size()) dp.emplace_back(a[i]);
		else dp[pos] = a[i];
	}
	cout << dp.size();
	return 0;
}