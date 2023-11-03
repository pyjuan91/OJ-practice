#include <bits/stdc++.h>
#define int long long
using namespace std;
int32_t main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int t, n, x, ma;
	cin >> t;
	for (int kase = 1; kase <= t; kase++) {
		cin >> n;
		ma = INT32_MIN;
		while (n--) {
			cin >> x;
			ma = max(ma, x);
		}
		cout << "Case " << kase << ": " << ma << '\n';
	}
	return 0;
}
