#include <bits/stdc++.h>
#define int long long
using namespace std;
int32_t main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int t, n;
	cin >> t;
	while (t--) {
		cin >> n;
		int res = INT64_MAX, sum = 0, ma = INT64_MIN, vist = 0;
		vector<int> a(2 * n);
		for (int i = 0; i < 2 * n; i++) {
			cin >> a[i];
			sum += llabs(a[i]);
			ma = max(ma, a[i]);
		}
		res = sum;
		if (n == 2) {
			int diff = 0;
			for (int i = 0; i < 4; i++) diff += llabs(a[i] - 2);
			res = min(res, diff);
		}
		if (n == 1) res = min(res, llabs(a[1] - a[0]));
		if (n % 2 == 0) {
			int diff = 0;
			for (int i = 0; i < 2 * n; i++) {
				if (a[i] == ma && !vist) {
					vist = 1;
					diff += abs(a[i] - n);
				}
				else diff += abs(a[i] + 1);
			}
			res = min(res, diff);
		}
		cout << res << "\n";
	}
	return 0;
}