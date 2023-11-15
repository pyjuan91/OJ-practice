#include <bits/stdc++.h>
#define int long long
using namespace std;
int32_t main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int t, n, a[101];
	cin >> t;
	while (t--) {
		cin >> n;
		int cnt[101] = {};
		for (int i = 1; i <= n; ++i) cin >> a[i], cnt[a[i]]++;
		int good = 0;
		for (int i = 1; i <= 100; ++i)
			if (cnt[i] >= 2) good++;
		if (good < 2) { cout << "-1\n"; }
		else {
			int two_done = 0;
			for (int i = 1; i <= n; i++) {
				if (cnt[a[i]] >= 2) {
					cout << "1 ";
					cnt[a[i]]--;
					if (two_done == 0) two_done = a[i];
				}
				else {
					if (a[i] == two_done) cout << "2 ";
					else cout << "3 ";
				}
			}
			cout << '\n';
		}
	}
	return 0;
}
