#include <bits/stdc++.h>
#define int long long
using namespace std;
int32_t main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int t, n, a[105], b;
	cin >> t;
	while (t--) {
		cin >> n;
		for (int i = 0; i < n; i++) cin >> a[i];
		b = 0;
		for (int i = 0; i < n; i++) {
			b++;
			if (b == a[i]) b++;
		}
        cout << b << '\n';
	}
	return 0;
}
