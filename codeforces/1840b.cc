#include <bits/stdc++.h>
#define int long long
using namespace std;
int32_t main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int t, n, k;
	cin >> t;
	while (t--) {
		cin >> n >> k;
		k = min(33ll, k);
		cout << min(n + 1, 1ll << k) << "\n";
	}
	return 0;
}