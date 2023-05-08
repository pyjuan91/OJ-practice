#include <bits/stdc++.h>
#define int long long
using namespace std;
signed main() {
	cin.tie()->sync_with_stdio(false);
	int n, l, r, q, P = 0, N = 0;
	string s;
	cin >> n >> s >> q;
	for (auto &c : s) {
		if (c == '+') P += 1;
		else N += 1;
	}
	while (q--) {
		cin >> l >> r;
		if (l > r) swap(l, r);
		int d = r - l, res = r * P - l * N;
		if (res == 0) cout << "YES\n";
		else if (d == 0) cout << "NO\n";
		else {
			if (res < 0 || res / d > n || res % d > 0)
				cout << "NO\n";
			else cout << "YES\n";
		}
	}
	return 0;
}