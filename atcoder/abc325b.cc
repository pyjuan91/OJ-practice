#include <bits/stdc++.h>
#define int long long
using namespace std;
int32_t main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n, res = INT32_MIN;
	cin >> n;
	vector<pair<int, int>> v(n);
	for (auto &[x, y] : v) cin >> x >> y;
	for (int i = 0; i < 24; i++) {
		int cnt = 0;
		for (auto [x, y] : v) {
			auto great = [&](int times) {
				return times >= 9 && times + 1 <= 18;
			};
			if (great((y + i) % 24)) cnt += x;
		}
		res = max(res, cnt);
	}
	cout << res << '\n';
	return 0;
}
