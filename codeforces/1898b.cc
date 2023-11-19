#include <bits/stdc++.h>
#define int long long
using namespace std;
int t, n, a[200005];
int32_t main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	cin >> t;
	while (t--) {
		cin >> n;
		for (int i = 1; i <= n; i++) cin >> a[i];
		int ans = 0, bound = a[n];
		for (int i = n - 1; i >= 1; i--) {
			if (a[i] > bound) {
				if (a[i] % bound == 0) ans += a[i] / bound - 1;
				else {
					int scale = a[i] / bound + 1;
					ans += scale - 1;
					bound = a[i] / scale;
				}
			}
			else bound = a[i];
		}
		cout << ans << '\n';
	}
	return 0;
}
