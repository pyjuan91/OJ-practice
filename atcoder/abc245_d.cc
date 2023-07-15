#include <bits/stdc++.h>
#define int long long
using namespace std;
using vi = vector<int>;
int32_t main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	vi a(n + 1, 0), c(n + m + 1, 0), b(m + 1, 0);
	for (auto& x : a) cin >> x;
	for (auto& x : c) cin >> x;
	for (int i = m; i >= 0; i--) {
		b[i] = c[n + i] / a[n];
		for (int j = n - 1; j >= 0; j--)
			c[i + j] -= a[j] * b[i];
	}
	for (auto& x : b) cout << x << " ";
	return 0;
}