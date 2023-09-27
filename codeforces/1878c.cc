#include <bits/stdc++.h>
#define int long long
using namespace std;
int32_t main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int t, n, k, x;
	cin >> t;
	while (t--) {
		cin >> n >> k >> x;
		int mi = k * (k + 1) / 2;
		int ma = k * (n - k + 1 + n) / 2;
		if (x < mi || x > ma) cout << "NO\n";
		else cout << "YES\n";
	}
	return 0;
}
