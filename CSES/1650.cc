#include <bits/stdc++.h>
#define int long long
using namespace std;
int32_t main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n, q;
	cin >> n >> q;
	vector<int> a(n + 1);
	for (int i = 1; i <= n; i++) cin >> a[i], a[i] ^= a[i - 1];
	while (q--) {
		int l, r;
		cin >> l >> r;
		cout << (a[r] ^ a[l - 1]) << '\n';
	}
	return 0;
}
