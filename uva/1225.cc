#include <bits/stdc++.h>
#define int long long
using namespace std;
int32_t main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int t, n;
	cin >> t;
	while (t--) {
		cin >> n;
		int cnt[10] = {};
		for (int i = 1; i <= n; ++i) {
			int x = i;
			while (x) {
				++cnt[x % 10];
				x /= 10;
			}
		}
		for (int i = 0; i < 9; ++i) cout << cnt[i] << ' ';
		cout << cnt[9] << '\n';
	}
	return 0;
}
