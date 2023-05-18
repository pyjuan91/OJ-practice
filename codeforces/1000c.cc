#include <bits/stdc++.h>
#define int long long
using namespace std;
int32_t main() {
	cin.tie()->sync_with_stdio(false);
	int n, current = 0, l, r;
	cin >> n;
	vector<pair<int, int>> a;
	vector<int> ans(n + 1);
	for (int i = 0; i < n; i++) {
		cin >> l >> r;
		a.emplace_back(make_pair(l, 1));
		a.emplace_back(make_pair(r + 1, -1));
	}
	sort(a.begin(), a.end());
	for (int i = 0; i < 2 * n - 1; i++) {
		current += a[i].second;
		if (a[i].first != a[i + 1].first)
			ans[current] += a[i + 1].first - a[i].first;
	}
	for (int i = 1; i <= n; i++) cout << ans[i] << " ";
	return 0;
}