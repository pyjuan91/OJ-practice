#include <bits/stdc++.h>
#define int long long
using namespace std;
bool chaewon(vector<int> &a, int m, int n) {
	if (n == 1) return a[0] == m;
	bool has_m = false, ok = false;
	for (int i = 0; i < n; i++) {
		if (a[i] == m) has_m = true;
		if (a[i] >= m) {
			if (i + 1 < n && a[i + 1] >= m) ok = true;
			if (i + 2 < n && a[i + 2] >= m) ok = true;
		}
	}
	return has_m && ok;
}
int32_t main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int t, n, m;
	cin >> t;
	while (t--) {
		cin >> n >> m;
		vector<int> a(n);
		for (auto &x : a) cin >> x;
		cout << (chaewon(a, m, n) ? "yes" : "no") << '\n';
	}
	return 0;
}
