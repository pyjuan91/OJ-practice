#include <bits/stdc++.h>
#define int long long
using namespace std;
const int maxn = 1e5 + 5;
int a[maxn];
int32_t main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int t, n, m, d;
	cin >> t;
	while (t--) {
		cin >> n >> m >> d;
		int sum = 1, cnt = 0, org, neww;
		for (int i = 1; i <= m; i++) cin >> a[i];
		a[0] = 1;
		for (int i = 1; i <= m; i++) {
			if (a[i] == 1) continue;
			if (i == m)
				org = (a[i] - a[i - 1]) / d
					+ ((a[i] - a[i - 1]) % d != 0) + (n - a[i]) / d;
			else
				org = (a[i] - a[i - 1]) / d + ((a[i] - a[i - 1]) % d != 0)
					+ (a[i + 1] - a[i]) / d
					+ ((a[i + 1] - a[i]) % d != 0);
			if (i == m) neww = (n - a[i - 1]) / d;
			else
				neww = (a[i + 1] - a[i - 1]) / d
					 + ((a[i + 1] - a[i - 1]) % d != 0);
			if (neww < org) cnt++;
			sum += (a[i] - a[i - 1]) / d + ((a[i] - a[i - 1]) % d != 0);
		}
		if (cnt)
			cout << sum + ((n - a[m]) / d) - 1 << " " << cnt << "\n";
		else cout << sum + ((n - a[m]) / d) << " " << m << "\n";
	}
	return 0;
}
