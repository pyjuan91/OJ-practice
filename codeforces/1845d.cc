#include <bits/stdc++.h>
#define int long long
using namespace std;
int a[(size_t) 3e5 + 5];
int32_t main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int t, n;
	cin >> t;
	while (t--) {
		cin >> n;
		for (int i = 0; i < n; i++) cin >> a[i];
		int ss = 0, res[2] = {}, ns = 0;
		res[0] = INT64_MAX;
		for (int i = 0; i < n; i++) {
			ss += a[i];
			if (ss > 0) {
				ns = i;
				ss = 0;
			}
			else {
				if (ss < res[0]) {
					res[0] = ss;
					res[1] = ns;
				}
			}
		}
		ss = 0;
		for (int i = 0; i <= res[1]; i++) ss += a[i];
		cout << max(0LL, ss) << "\n";
	}
	return 0;
}