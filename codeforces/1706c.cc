#include <bits/stdc++.h>
#define int long long
using namespace std;
int h[100005], pre[100005], suf[100005];
int32_t main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int t, n;
	cin >> t;
	while (t--) {
		cin >> n;
		for (int i = 0; i < n; i++) cin >> h[i];
		int res = 0;
		if (n % 2 == 1) {
			for (int i = 1; i < n; i += 2) {
				if (h[i] <= h[i - 1] || h[i] <= h[i + 1]) {
					res += max(h[i - 1], h[i + 1]) - h[i] + 1;
				}
			}
		}
		else {
			for (int i = 0; i < n + 5; i++) pre[i] = suf[i] = 0;
			for (int i = 1; i + 1 < n; i += 2) {
				if (h[i] <= h[i - 1] || h[i] <= h[i + 1]) {
					pre[i] = max(h[i - 1], h[i + 1]) - h[i] + 1;
				}
				pre[i] += pre[i - 2];
			}
			for (int i = n - 2; i - 1 >= 0; i -= 2) {
				if (h[i] <= h[i - 1] || h[i] <= h[i + 1]) {
					suf[i] = max(h[i - 1], h[i + 1]) - h[i] + 1;
				}
				suf[i] += suf[i + 2];
			}
			res = INT64_MAX;
			for (int i = 1; i + 1 < n; i += 2)
				res = min(res, pre[i] + suf[i + 3]);
			res = min(res, suf[2]);
		}
		cout << res << '\n';
	}
	return 0;
}
