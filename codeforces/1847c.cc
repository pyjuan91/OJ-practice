#include <bits/stdc++.h>
using namespace std;
int a[100005];
int32_t main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int t, n;
	cin >> t;
	while (t--) {
		cin >> n;
		for (int i = 1; i <= n; i++) cin >> a[i];
		int prexor = 0, res = INT32_MIN;
		bool pre[256] = {};
		pre[0] = true;
		for (int i = 1; i <= n; i++) {
			prexor ^= a[i];
			for (int j = 0; j < 256; j++) {
				if (pre[j]) res = max(res, prexor ^ j);
			}
            pre[prexor] = true;
		}
        cout << res << '\n';
	}
	return 0;
}
