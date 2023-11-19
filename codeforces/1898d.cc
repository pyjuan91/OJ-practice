#include <bits/stdc++.h>
#define int long long
using namespace std;
const int maxn = 2e5 + 5;
int t, n, a[maxn], b[maxn];
int32_t main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	cin >> t;
	while (t--) {
		cin >> n;
		for (int i = 1; i <= n; i++) cin >> a[i];
		for (int i = 1; i <= n; i++) cin >> b[i];
		int res = 0;
		for (int i = 1; i <= n; i++) res += llabs(a[i] - b[i]);
		set<int> g, l;
		for (int i = 1; i <= n; i++) {
			if (a[i] >= b[i]) {
				g.insert(a[i]);
				l.insert(b[i]);
			}
			else {
				g.insert(b[i]);
				l.insert(a[i]);
			}
		}
		int nice_l = *l.rbegin(), nice_g = *g.begin();
		int nice = max(0ll, nice_l - nice_g);
		cout << res + 2 * nice << '\n';
	}
	return 0;
}
