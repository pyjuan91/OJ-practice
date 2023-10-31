#include <bits/stdc++.h>
#define int long long
using namespace std;
int chaewon(int n, int m) {
	n -= 2, m -= 2;
	return ceil(1.0 * n / 3) * ceil(1.0 * m / 3);
}
int32_t main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int t, n, m;
	cin >> t;
	while (t--) {
		cin >> n >> m;
		cout << chaewon(n, m) << '\n';
	}
	return 0;
}
