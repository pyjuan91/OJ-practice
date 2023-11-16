#include <bits/stdc++.h>
#define int long long
using namespace std;
int32_t main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n, best_x, best_y;
	cin >> n;
	vector<pair<int, int>> a(n);
	for (auto& [x, y] : a) cin >> x >> y;
	best_x = a[0].first, best_y = a[0].second;
	auto custom_ceil = [](int x, int y) {
		int sca = x / y;
		if (sca * y == x) return sca;
		return sca + 1;
	};
	for (int i = 1; i < n; i++) {
		int scalar_x = custom_ceil(best_x, a[i].first);
		int scalar_y = custom_ceil(best_y, a[i].second);
		int scalar = max(scalar_x, scalar_y);
		best_x = a[i].first * scalar;
		best_y = a[i].second * scalar;
	}
	cout << best_x + best_y << '\n';
	return 0;
}
