#include <bits/stdc++.h>
#define int long long
using namespace std;
int32_t main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n, m, left, right, mid;
	cin >> n >> m;
	vector<int> a(n + 1);
	for (int i = 1; i <= n; i++) cin >> a[i];
	auto check_constructable = [&](int guess) {
		int odd_test_len = 0, even_test_len = 0, odd_max = 0, even_max = 0;
		// test if odd_max or even_max generates a valid sequence
		for (int i = 1; i <= n; i++) {
			if (odd_test_len % 2 == 1) odd_test_len++;
			else if (a[i] <= guess)
				odd_test_len++, odd_max = max(odd_max, a[i]);
			if (even_test_len % 2 == 0) even_test_len++;
			else if (a[i] <= guess)
				even_test_len++, even_max = max(even_max, a[i]);
		}
		return odd_test_len >= m || even_test_len >= m;
	};
	left = 0, right = 1e9 + 5;
	while (left + 1 < right) {
		mid = left + (right - left) / 2;
		if (check_constructable(mid)) right = mid;
		else left = mid;
	}
	cout << right << '\n';
	return 0;
}
