#include <bits/stdc++.h>
using namespace std;
int a[200005], pre[200005];
int32_t main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int t, n, k;
	cin >> t;
	while (t--) {
		cin >> n >> k;
		for (int i = 0; i < n + 5; i++) pre[i] = 0;
		for (int i = 1; i <= n; i++) {
			cin >> a[i];
			if (i > 1) {
				if (a[i] * 2 > a[i - 1]) pre[i] = 1;
				pre[i] += pre[i - 1];
			}
		}
		int res = 0;
		for (int i = 1; i + k <= n; i++) {
			if (pre[i + k] - pre[i] == k) res++;
		}
        cout << res << '\n';
	}
	return 0;
}
