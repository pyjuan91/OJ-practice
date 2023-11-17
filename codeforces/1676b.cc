#include <bits/stdc++.h>
#define int long long
using namespace std;
int32_t main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int t, n, a[55];
	cin >> t;
	while (t--) {
		cin >> n;
		for (int i = 0; i < n; i++) cin >> a[i];
		int mi = *min_element(a, a + n), res = 0;
		for (int i = 0; i < n; i++) res += a[i] - mi;
        cout << res << '\n';
	}
	return 0;
}
