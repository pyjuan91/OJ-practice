#include <bits/stdc++.h>
#define int long long
using namespace std;
const int maxn = 2e5 + 5;
int a[maxn], b[maxn], t, n, k;
int32_t main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	cin >> t;
	while (t--) {
		cin >> n >> k;
		for (int i = 1; i <= n; i++) cin >> a[i];
		for (int i = 1; i <= n; i++) cin >> b[i];
		int l = 1, hold = 0, res = 0;
		for (int r = 1; r <= n; r++) {
			while (hold + a[r] > k && l < r) {
				hold -= a[l];
				l++;
			}
			if (r == 1 || b[r - 1] % b[r] == 0) hold += a[r];
			else hold = a[r], l = r;
			if (hold <= k) res = max(res, r - l + 1);
		}
		cout << res << '\n';
	}
	return 0;
}
