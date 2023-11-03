#include <bits/stdc++.h>
#define int long long
using namespace std;
int chaewon(int x, int y, int k) {
	if (y <= x) return x;
	return y + max(0ll, y - (x + k));
}
int32_t main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int t, x, y, k;
	cin >> t;
	while (t--) {
		cin >> x >> y >> k;
		cout << chaewon(x, y, k) << '\n';
	}
	return 0;
}
