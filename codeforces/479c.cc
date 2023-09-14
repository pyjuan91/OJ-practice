#include <bits/stdc++.h>
using namespace std;
int32_t main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n, cur;
	cin >> n;
	vector<pair<int, int>> a(n);
	for (auto &[x, y] : a) cin >> x >> y;
	sort(a.begin(), a.end());
	cur = a[0].second;
	for (auto &[x, y] : a) {
		if (y >= cur) cur = y;
		else cur = x;
	}
    cout << cur << '\n';
	return 0;
}
