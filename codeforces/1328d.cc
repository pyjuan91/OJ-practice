#include <bits/stdc++.h>
using namespace std;
int a[200005], color[200005];
int32_t main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int t, n;
	cin >> t;
	while (t--) {
		cin >> n;
		for (int i = 0; i < n; i++) cin >> a[i], color[i] = 0;
		int res = 1, start = 0, quota = -1;
		for (int i = 0; i < n; i++) {
			int nxt = (i + 1) % n, nxtt = (i + 2) % n;
			if (a[i] != a[nxt] && a[nxt] != a[nxtt] && a[nxtt] != a[i]) {
				start = i;
				break;
			}
		}
		color[start] = 1;
		for (int i = 1; i < n - 1; i++) {
			int cur = (start + i) % n, prv = (start + i - 1) % n;
			if (a[cur] == a[prv])
				color[cur] = color[prv], quota = cur;
			else {
				if (res == 1) color[cur] = ++res;
				else color[cur] = 3 - color[prv];
			}
		}
		int last = (start + n - 1) % n, prv = (start + n - 2) % n;
		// cout << "last: " << last << " prv: " << prv << '\n';
		if (a[last] == a[prv] && a[last] == a[start])
			color[last] = color[prv];
		else if (a[last] == a[prv] && a[last] != a[start])
			color[last] = 3 - color[start];
		else if (a[last] != a[prv] && a[last] == a[start])
			color[last] = 3 - color[prv];
		else {
			if (color[start] == color[prv])
				color[last] = 3 - color[start];
			else if (quota != -1) {
				color[prv] = color[start];
				color[last] = 3 - color[start];
				for (int i = (prv + n - 1) % n; i != quota;
					 i = (i + n - 1) % n)
					color[i] = 3 - color[(i + 1) % n];
				color[quota] = 3 - color[(quota + 1) % n];
			}
			else color[last] = 3;
		}
		for (int i = 0; i < n; i++) res = max(res, color[i]);
		cout << res << '\n';
		for (int i = 0; i < n; i++) cout << color[i] << ' ';
		cout << '\n';
	}
	return 0;
}
