#include <bits/stdc++.h>
using namespace std;
int32_t main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int t, n, m, k, x, y, xi, yi;
	cin >> t;
	while (t--) {
		cin >> n >> m >> k;
		cin >> x >> y;
		bool yes = true;
		while (k--) {
			cin >> xi >> yi;
			if ((abs(x - xi) + abs(y - yi)) % 2 == 0)
				yes = false;
		}
		if (yes) cout << "YES\n";
		else cout << "NO\n";
	}
	return 0;
}