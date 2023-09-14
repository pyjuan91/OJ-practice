#include <bits/stdc++.h>
#define int long long
using namespace std;
int32_t main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n, m, k;
	cin >> n >> m >> k;
	if (n > m) swap(n, m);
	int left = 0, right = n * m + 1, mid, res = right;
	auto check = [&](int mid) {
		int res = 0;
		for (int i = 1; i <= n; i++) {
			res += min(m, (mid - 1) / i);
		}
		return res;
	};
	while (left <= right) {
		mid = (left + right) / 2;
		if (check(mid) < k) {
			res = mid;
			left = mid + 1;
		}
		else right = mid - 1;
	}
	cout << res << '\n';
	return 0;
}
