#include <bits/stdc++.h>
#define int long long
using namespace std;
int32_t main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int t, n, pre, x, tmp;
	cin >> t;
	while (t--) {
		cin >> n >> pre;
		int pre_two_pow = 0, res = 0;
		for (int i = 1; i < n; i++) {
			cin >> x;
			tmp = x;
			while (pre <= x && pre_two_pow > 0) {
				pre <<= 1;
				pre_two_pow--;
			}
			while (pre > x) {
				pre_two_pow++;
				x <<= 1;
			}
			res += pre_two_pow;
			pre = tmp;
		}
		cout << res << '\n';
	}
	return 0;
}