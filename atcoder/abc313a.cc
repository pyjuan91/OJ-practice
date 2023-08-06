#include <bits/stdc++.h>
using namespace std;
int32_t main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n, p1, ma = INT32_MIN, x;
	cin >> n >> p1;
	for (int i = 1; i < n; i++) {
		cin >> x;
		ma = max(ma, x);
	}
	if (ma >= p1) cout << ma - p1 + 1;
	else cout << 0;
	return 0;
}
