#include <bits/stdc++.h>
using namespace std;
int32_t main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int t, a, b, n;
	cin >> t;
	while (t--) {
		cin >> a >> b >> n;
		vector<int> v(n);
		int diff = 0, sol = 1;
		for (int i = 0; i < n; i++) {
			v[i] = b - diff;
			b -= diff;
			diff += 1;
			if (v[i] < a) {
				sol = 0;
				break;
			}
		}
		if (sol) {
			reverse(v.begin(), v.end());
			v[0] = a;
			for (auto x : v) cout << x << ' ';
			cout << '\n';
		}
		else cout << -1 << '\n';
	}

	return 0;
}
